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
 * @file
 */

#include <utils/ParseXML.hpp>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/ParseXMLString.hpp>
#include <utils/ParseXMLTags.hpp>

#include <unistd.h>

namespace eprosima {
namespace qosprof {
namespace utils {

ParseXML::ParseXML (
    xercesc::DOMDocument*& doc,
    const std::string& file_name,
    bool create_file
)
{
    // File exists flag
    bool file_exists = false;

    // Obtain absolute path of the XML file
    xml_file = get_absolute_path(file_name, file_exists); // if file exist, flag would be updated

    // Try to initialize XML workspace
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw FileNotFound(xercesc::XMLString::transcode(toCatch.getMessage()));
    }

    // Create Xerces implementation
    implementation = xercesc::DOMImplementationRegistry::getDOMImplementation (
        xercesc::XMLString::transcode(CORE));
    if (implementation == nullptr)
    {
        // Could not initialize XML workspace
        throw FileNotFound("Could not set XML workspace");
    }

    // Create Xerces Required elements based on the implementation
    // Serializer and output would export the Document's nodes into a legible string / file
    serializer = (static_cast<xercesc::DOMImplementationLS*>(implementation))->createLSSerializer();
    output = implementation->createLSOutput();
    output->setEncoding(xercesc::XMLString::transcode(UTF8));
    serializer->setNewLine(xercesc::XMLString::transcode(LINE_BREAK));

    // Config would configure serialized XML data
    config = serializer->getDomConfig();
    config->setParameter(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint, true);
    config->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, true);

    // Parser would validate the serialized XML against the defined XSD, with some configured parameters
    parser = new xercesc::XercesDOMParser();
    // Obtain XML schema path
    std::string xsd_file_path = FASTDDS_QOS_PROFILES_MANAGER_XML_SCHEMA;
    // Set as namespace location both URL and the path to the XML schema
    std::string namespace_schema_location = eprosima::qosprof::utils::tag::EPROSIMA_URL;
    namespace_schema_location += " " + xsd_file_path;
    // Load the schema as part of the grammar of the parser
    parser->loadGrammar(xsd_file_path.c_str(), xercesc::Grammar::SchemaGrammarType, true);
    // Set the schema location as the given URL plus the path to the file
    parser->setExternalSchemaLocation(namespace_schema_location.c_str());
    // Turn ON validation in the parser
    parser->setValidationScheme(xercesc::XercesDOMParser::Val_Always);
    // Force parser to use the given namespace URL for validation
    parser->setDoNamespaces(true);
    // Force parser to use the given XML schema for validation
    parser->setDoSchema(true);
    // Force parser to throw related exception no matter the severity of the issue found
    parser->setValidationConstraintFatal(true);

    // Error handler would receive the exception from the parser, and report it as a FileNotFound expected exception
    error_handler = new eprosima::qosprof::utils::ParseXMLErrorHandler(
        eprosima::qosprof::utils::ParseXMLErrorHandler::Kind::FileNotFound);
    parser->setErrorHandler(error_handler);

    // Read XML file and obtain the doc object
    try
    {
        // Parsing initially would load the elements in the parser's doc object
        parser->parse(xml_file.c_str());
        // Doc would be needed in some other process, so it would be useful to take it apart of the parser
        doc = parser->getDocument();
    }
    // Given file does not exist
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Create new document if required
        if (create_file && !file_exists)
        {
            // Implementation would create an empty document
            doc = implementation->createDocument(0, xercesc::XMLString::transcode(
                eprosima::qosprof::utils::tag::ROOT), 0);
            // The root element would be <dds>, with the 'xmlns' att.
            doc->getDocumentElement()->setAttribute(
                xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::XMLNS),
                xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::EPROSIMA_URL));
        }
        // Propagate the exception
        else
        {
            throw FileNotFound(ex);
        }
    }
}

ParseXML::~ParseXML()
{
    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();

    // Release resources
    delete config;
    delete implementation;
    delete output;
    delete parser;
    delete serializer;
    delete target;
    delete error_handler;
}

void ParseXML::validate_and_save_xml_document(
    xercesc::DOMDocument*& doc)
{
    if (validate_xml(doc))
    {
        save_xml(doc);
    }
}

bool ParseXML::validate_xml(
    xercesc::DOMDocument*& doc)
{
    // Set ElementInvalid error handler
    error_handler = new eprosima::qosprof::utils::ParseXMLErrorHandler(
        eprosima::qosprof::utils::ParseXMLErrorHandler::Kind::ElementInvalid);
    parser->setErrorHandler(error_handler);

    // Create a XML string buffer for validation
    eprosima::qosprof::utils::ParseXMLString* xml_string = new eprosima::qosprof::utils::ParseXMLString();

    // Save XML document in the XML string buffer
    output->setByteStream(xml_string);
    serializer->write(doc, output);
    xercesc::MemBufInputSource src(reinterpret_cast<XMLByte*>(xml_string->buffer()), xml_string->length(), "", false);

    // Validate the XML string buffer against the schema
    parser->parse(src);

    // Validation successful
    return true;
}

bool ParseXML::save_xml(
    xercesc::DOMDocument*& doc)
{
    // Save XML document in target file path
    target = new xercesc::LocalFileFormatTarget(xercesc::XMLString::transcode(xml_file.c_str()));
    output->setByteStream(target);
    return serializer->write(doc, output);
}

xercesc::DOMNode* ParseXML::get_node(
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
        throw ElementNotFound("non-existent " + tag_name + " profile\n");
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
        // Obtain node
        xercesc::DOMNode* tag_node = nullptr;
        bool found = false;

        // Iterate through the nodes
        // TODO maybe trying with node->getNextSibling() iterator this function is more efficient
        for (int i=0, size=node_tag_list->getLength(); i<size && !found; i++)
        {
            // Obtain index element
            tag_node = node_tag_list->item(i);
            if (tag_node != nullptr)
            {
                // Node is not a Element, go next
                if (tag_node->getNodeType() != xercesc::DOMNode::NodeType::ELEMENT_NODE)
                {
                    continue;
                }
                // Node is a Complex Element
                if (tag_name == xercesc::XMLString::transcode(tag_node->getNodeName()))
                {
                    // MAP element
                    if (att_name.length() != 0)
                    {
                        // Get node name and attributes
                        xercesc::DOMNamedNodeMap* atts = tag_node->getAttributes();
                        // If there are attributes
                        if (atts != nullptr)
                        {
                            // Obtain the attribute that matches the name
                            xercesc::DOMNode* item = atts->getNamedItem(xercesc::XMLString::transcode(att_name.c_str()));
                            if (item != nullptr)
                            {
                                // If the value of the attribute match
                                std::string val = xercesc::XMLString::transcode(item->getNodeValue());
                                if (val == att_value)
                                {
                                    found = true;
                                }
                            }
                            else
                            {
                                // Throw eprosima::qosprof::ElementNotFound exception
                                throw ElementNotFound(
                                    tag_name + " does not have the attribute " + att_name + "\n");
                            }
                        }
                        else
                        {
                            // Throw eprosima::qosprof::ElementNotFound exception
                            throw ElementNotFound(
                                tag_name + " does not have the attribute " + att_name + "\n");
                        }
                    }
                    // LIST element TODO refactor
                    else if (&index == nullptr)
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
                            throw ElementNotFound(
                                tag_name + " does not have an element in position " + std::to_string(realIndex) + "\n");
                        }
                        // Return Node
                        return node_tag_list->item(realIndex);
                    }
                    // Complex Element
                    else
                    {
                        found = true;
                    }
                }
            }
        }
        // Throw exception if node not found
        if (!found)
        {
            // Given element does not exist
            throw ElementNotFound(
                tag_name + " does not have an element with key " + att_value + "\n");
        }
        else
        {
            // Return Node
            return tag_node;
        }
    }
}

void ParseXML::clear_node(
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
            std::string message = "Could not delete last element from ";
            message.append(xercesc::XMLString::transcode(parent_node->getNodeValue()));
            message.append(". Delete element by running the predecessor clear API.\n");

            // Throw ElementInvalid exception with custom message
            throw ElementInvalid(message);
        }
    }
    // Remove node from parent
    parent_node->removeChild(node_to_be_deleted);

    // Free node resources
    node_to_be_deleted->release();
}

void ParseXML::reset_node(
        xercesc::DOMNode*& node)
{
    // Loop for childs
    while (node->hasChildNodes())
    {
        // Obtain each node
        xercesc::DOMNode* node_to_be_deleted = node->getFirstChild();

        // Remove each child from parent node
        node->removeChild(node_to_be_deleted);

        // Free node resources
        node_to_be_deleted->release();
    }
}

void ParseXML::set_value_to_node(
        xercesc::DOMDocument*& doc,
        xercesc::DOMNode*& node,
        const std::string& value)
{
    // Remove all childs
    reset_node(node);

    // Set name value
    xercesc::DOMText* name_value = doc->createTextNode(xercesc::XMLString::transcode(value.c_str()));
    node->appendChild(name_value);
}

std::string ParseXML::get_absolute_path(
        const std::string& xml_file,
        bool& file_exists)
{
    std::string absolute_xml_file;

    //   Check if file already exists
    char* absolute_xml_path = realpath(xml_file.c_str(), nullptr);
    //   File does not exist
    if (absolute_xml_path == nullptr)
    {
        // Check if it not already an absolute path
        if (xml_file.find("/") == std::string::npos)
        {
            // Get current path and concat xml file name
            absolute_xml_path = realpath(".", nullptr);
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

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, 0, "", "");;
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        int32_t index)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, index, "", "");
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    // Try call main get_node function with remain empty values
    return get_node(doc, tag_name, 0, att_name, att_value);
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMDocument*& doc,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Obtain main list of nodes
    xercesc::DOMNodeList* node_list = doc->getDocumentElement()->getElementsByTagName(xercesc::XMLString::transcode(tag_name.c_str()));

    // Check there was any node with given tag name
    if (node_list == nullptr)
    {
        // Throw ElementNotFound exception
        throw ElementNotFound("non-existent " + tag_name + " profile\n");
    }

    // Obtain node from main get_node function
    return get_node(node_list, tag_name, index, att_name, att_value);;
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, 0, "", "");
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        int32_t index)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, index, "", "");
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    // Try call main get_node function with remain empty values
    return get_node(parent_node, tag_name, 0, att_name, att_value);
}

xercesc::DOMNode* ParseXML::get_node(
        xercesc::DOMNode*& parent_node,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Obtain main list of nodes
    xercesc::DOMNodeList* node_list = parent_node->getChildNodes();
    if (node_list == nullptr)
    {
        // Throw ElementNotFound exception
        throw ElementNotFound("non-existent " + tag_name + " profile\n");
    }

    // Obtain node from main get_node function
    return get_node(node_list, tag_name, index, att_name, att_value);
}

} /* utils */
} /* qosprof */
} /* eprosima */
