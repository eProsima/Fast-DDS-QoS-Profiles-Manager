// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ParseXML.cpp
 */

#include <utils/ParseXML.hpp>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/ParseXMLTags.hpp>
#include <utils/ParseXMLString.hpp>

#include <unistd.h>

std::string get_absolute_path(
        const std::string& xml_file,
        bool& file_exists)
{
    std::string absolute_xml_file;

    //   Check if file already exists
    char* absolute_xml_path = realpath(xml_file.c_str(), NULL);
    //   File does not exist
    if (absolute_xml_path == NULL)
    {
        // Check if it not already an absolute path
        if (xml_file.find("/") == std::string::npos)
        {
            // Get current path and concat xml file name
            absolute_xml_path = realpath(".", NULL);
            absolute_xml_file = absolute_xml_path;
            absolute_xml_file += "/" + xml_file;
        }
        // Set the given absolute path
        else
        {
            absolute_xml_file = xml_file;
        }

        // Save status in the given reference
        file_exists = false;
    }
    //   File exists: load file name directly
    else
    {
        absolute_xml_file = absolute_xml_path;

        // Save status in the given reference
        file_exists = true;
    }
    return absolute_xml_file;
}

bool initialize_tools (
    xercesc::DOMConfiguration*& config,
    xercesc::DOMDocument*& doc,
    eprosima::qosprof::parse::ParseXMLErrorHandler*& error_handler,
    xercesc::DOMImplementation*& implementation,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target,
    const std::string& xml_file
)
{
    // Create Xerces implementation
    implementation = xercesc::DOMImplementationRegistry::getDOMImplementation (xercesc::XMLString::transcode("Core"));
    if (implementation == NULL)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::FileNotFound("Could not set XML workspace");

        // Initialization process failed
        return false;
    }

    // Create Xerces Required elements based on the implementation
    //   Serializer and output would export the Document's nodes into a legible string / file
    serializer = ((xercesc::DOMImplementationLS*)implementation)->createLSSerializer();
    output = implementation->createLSOutput();
    output->setEncoding(xercesc::XMLString::transcode("UTF-8"));
    serializer->setNewLine(xercesc::XMLString::transcode("\n"));
    //   Config would configure serialized XML data
    config = serializer->getDomConfig();
    config->setParameter(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint, true);
    config->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, true);
    target = new xercesc::LocalFileFormatTarget(xercesc::XMLString::transcode(xml_file.c_str()));
    //   Parser would validate the serialized XML against the defined XSD, with some configured parameters
    parser = new xercesc::XercesDOMParser();
    std::string xsd_file_path = FASTDDS_QOS_PROFILES_MANAGER_XML_SCHEMA;
    std::string namespace_schema_location = eprosima::qosprof::tag::EPROSIMA_URL;
    namespace_schema_location += " " + xsd_file_path;
    parser->loadGrammar(xsd_file_path.c_str(), xercesc::Grammar::SchemaGrammarType, true);
    parser->setExternalSchemaLocation(namespace_schema_location.c_str());
    parser->setValidationScheme(xercesc::XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);
    parser->setDoSchema(true);
    parser->setValidationConstraintFatal(true);
    //   Error handler would receive the exception from the parser, and report it as a FileNotFound expected exception
    error_handler = new eprosima::qosprof::parse::ParseXMLErrorHandler(eprosima::qosprof::parse::ParseXMLErrorHandler::Kind::FileNotFound);
    parser->setErrorHandler(error_handler);

    // Read XML file and obtain the doc object
    try
    {
        // Parsing initially would load the elements in the parser's doc object
        parser->parse(xercesc::XMLString::transcode(xml_file.c_str()));
        // Doc would be needed in some other process, so it would be useful to take it apart of the parser
        doc = parser->getDocument();
    }
    // Given file does not exist, so new doc with root element needs to be created
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Implementation would create an empty document
        doc = implementation->createDocument(0, xercesc::XMLString::transcode(
            eprosima::qosprof::tag::ROOT), 0);
        // The root element would be <dds>, with the 'xmlns' att.
        doc->getDocumentElement()->setAttribute(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::XMLNS),
            xercesc::XMLString::transcode(eprosima::qosprof::tag::EPROSIMA_URL));
    }

    // Initialization process successful
    return true;
}

void validate_and_save_xml_document(
    xercesc::DOMDocument*& doc,
    eprosima::qosprof::parse::ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target)
{
    if (validate_xml(doc, error_handler, output, parser, serializer))
    {
        save_xml(doc, output, serializer, target);
    }
}

bool validate_xml(
    xercesc::DOMDocument*& doc,
    eprosima::qosprof::parse::ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer)
{
    // Set ElementInvalid error handler
    error_handler = new eprosima::qosprof::parse::ParseXMLErrorHandler(eprosima::qosprof::parse::ParseXMLErrorHandler::Kind::ElementInvalid);
    parser->setErrorHandler(error_handler);

    // Validate new element
    try {
        // String buffer for validation
        eprosima::qosprof::parse::ParseXMLString* xml_string = new eprosima::qosprof::parse::ParseXMLString();

        // Save XML document as string
        output->setByteStream(xml_string);
        serializer->write(doc, output);

        // Validate XML string
        xercesc::MemBufInputSource src((const XMLByte*)xml_string->buffer(), xml_string->length(), "", false);
        parser->parse(src);
    }
    // Validation error, report to parent and return failure
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);

        // Validation failed
        return false;
    }

    // Validation successful
    return true;
}

bool save_xml(
    xercesc::DOMDocument*& doc,
    xercesc::DOMLSOutput*& output,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target)
{
    // Save XML document in target file path
    output->setByteStream(target);
    return serializer->write(doc, output);
}

xercesc::DOMNode* get_node(
        xercesc::DOMNodeList*& node_tag_list,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Throw exception if no nodes
    if (node_tag_list->getLength() == 0)
    {
        // Throw eprosima::qosprof::ElementNotFound exception
        throw eprosima::qosprof::ElementNotFound("non-existent " + tag_name + " profile\n");

        return NULL;
    }

    // Complex element Node
    else if (node_tag_list->getLength() == 1)
    {
        // Return Node
        return node_tag_list->item(0);
    }
    // MAP or LIST element node
    else
    {
        // Obtain node based on MAP
        if (att_name.c_str() != NULL){
            xercesc::DOMNode* tag_node = NULL;

            // Iterate throw the nodes
            // TODO maybe trying with node->getNextSibling() iterator this function is more efficient
            for (int i=0, j=0, size=node_tag_list->getLength(); i<size && j==0; i++)
            {
                tag_node = node_tag_list->item(i);
                if (tag_node != NULL)
                {
                    std::string name = xercesc::XMLString::transcode(tag_node->getNodeValue());
                    xercesc::DOMNamedNodeMap* atts = tag_node->getAttributes();
                    if (atts != NULL)
                    {
                        xercesc::DOMNode* item = atts->getNamedItem(xercesc::XMLString::transcode(att_name.c_str()));
                        if (item != NULL)
                        {
                            std::string val = xercesc::XMLString::transcode(item->getNodeValue());
                            if (val == att_value)
                            {
                                j++;
                            }
                            else
                            {
                                tag_node = NULL;
                            }
                        }
                        else
                        {
                            tag_node = NULL;
                        }
                    }
                    else
                    {
                        tag_node = NULL;
                    }
                }
                else
                {
                    tag_node = NULL;
                }
            }

            // Throw exception if node not found
            if (tag_node == NULL)
            {
                // Given file does not exist
                throw eprosima::qosprof::ElementNotFound(
                    tag_name + " does not have an element with key " + att_value + "\n");

                return NULL;
            }
            else
            {
                // Return Node
                return tag_node;
            }
        }
        // Obtain node based on LIST
        else
        {
            int32_t realIndex = index;

            // Transform index to real index
            if (index < 0)
            {
                realIndex = node_tag_list->getLength() + index;
            }

            // Check bounds
            if (realIndex < 0 || realIndex >= node_tag_list->getLength())
            {
                // Throw eprosima::qosprof::ElementNotFound exception
                throw eprosima::qosprof::ElementNotFound(
                    tag_name + " does not have an element in position " + std::to_string(realIndex) + "\n");

                return NULL;
            }
            // Return Node
            return node_tag_list->item(realIndex);
        }
    }
}

void clear_node(
        xercesc::DOMNode*& parent_node,
        xercesc::DOMNode*& node_to_be_deleted)

{
    // Check if parent node has child nodes
    if (parent_node->hasChildNodes())
    {
        // Check if the node to be deleted is the last child node of the parent
        if (parent_node->getChildNodes()->getLength() == 1 &&
            parent_node->getChildNodes()->item(0)->getNodeName() == node_to_be_deleted->getNodeName())
        {
            // Invalid request: report exception
            std::string message = "could not delete last element from ";
            message.append(xercesc::XMLString::transcode(parent_node->getNodeValue()));
            message.append(". Delete element by running the predecessor clear API.\n");

            // Throw ElementInvalid exception with custom message
            throw eprosima::qosprof::ElementInvalid(message);
            return;
        }
    }
    // Remove node from parent
    parent_node->removeChild(node_to_be_deleted);

    // Free node resources (optional?)
    node_to_be_deleted->release();
    delete node_to_be_deleted;
}

void reset_node(
        xercesc::DOMNode*& node)

{
    // Loop for childs
    while (node->hasChildNodes())
    {
        // Remove all childs
        node->removeChild(node->getFirstChild());
    }
}

xercesc::DOMNode* get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, 0, "", "");;
}

xercesc::DOMNode* get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        int32_t index)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, index, "", "");
}

xercesc::DOMNode* get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, 0, att_name, att_value);
}

xercesc::DOMNode* get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Obtain main list of nodes
    xercesc::DOMNodeList* node_list = doc->getDocumentElement()->getElementsByTagName(xercesc::XMLString::transcode(tag_name.c_str()));

    // Check there was any node with given tag name
    if (node_list == NULL)
    {
        // Throw ElementNotFound exception
        throw eprosima::qosprof::ElementNotFound("non-existent " + tag_name + " profile\n");

        return NULL;
    }

    // Obtain node from main get_node function
    return get_node(node_list, tag_name, index, att_name, att_value);;
}

xercesc::DOMNode* get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, 0, "", "");
}

xercesc::DOMNode* get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        int32_t index)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, index, "", "");
}

xercesc::DOMNode* get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, 0, att_name, att_value);
}

xercesc::DOMNode* get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{

    // Obtain main list of nodes
    xercesc::DOMNodeList* node_list = parent_node->getChildNodes();
    if (node_list == NULL)
    {
        // Throw ElementNotFound exception
        throw eprosima::qosprof::ElementNotFound("non-existent " + tag_name + " profile\n");

        return NULL;
    }

    // Obtain node from main get_node function
    return get_node(node_list, tag_name, index, att_name, att_value);
}
