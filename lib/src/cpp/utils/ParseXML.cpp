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
 * @file ParseXMLErrorHandler.cpp
 */

#include <utils/ParseXML.hpp>

xercesc::XercesDOMParser* open_xml(
        const std::string& xml_file)
{
    // Try to initialize XML workspace
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw eprosima::qosprof::Unsupported(xercesc::XMLString::transcode(toCatch.getMessage()));
        return NULL;
    }

    // Create parser
    xercesc::XercesDOMParser* parser = new xercesc::XercesDOMParser();

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::FileNotFound);
    parser->setErrorHandler(xmlErrorHandler);

    // Try to open the given file
    try
    {
        parser->parse(xercesc::XMLString::transcode(xml_file.c_str()));
    }
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Delete resources
        delete parser;
        delete xmlErrorHandler;

        // Close XML workspace
        xercesc::XMLPlatformUtils::Terminate();

        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return NULL;
    }

    return parser;
}

void closeXML()
{
    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();
}

xercesc::DOMNode* get_node(
        const xercesc::DOMNodeList& node_tag_list,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Throw exception if no nodes
    if (node_tag_list.getLength() == 0)
    {
        // Throw eprosima::qosprof::ElementNotFound exception
        throw eprosima::qosprof::ElementNotFound("non-existent " + tag_name + " profile\n");

        return NULL;
    }
    // Complex element Node
    else if (node_tag_list.getLength() == 1)
    {
        // Return Node
        return node_tag_list.item(0);
    }
    // MAP or LIST element node
    else
    {
        // Obtain node based on MAP
        if (att_name.c_str() != NULL){
            xercesc::DOMNode* tagNode = NULL;

            // Iterate throw the nodes
            // TODO try with node->getNextSibling();
            for (int i=0, j=0, size=node_tag_list.getLength(); i<size && j==0; i++)
            {
                tagNode = node_tag_list.item(i);
                if (tagNode->getAttributes()->getNamedItem(xercesc::XMLString::transcode(att_name.c_str()))->getNodeValue()
                    == xercesc::XMLString::transcode(att_value.c_str()))
                {
                    j++;
                }
                else
                {
                    tagNode = NULL;
                }
            }

            // Throw exception if node not found
            if (tagNode == NULL)
            {
                // Given file does not exist
                throw eprosima::qosprof::ElementNotFound(
                    tag_name + " does not have an element with key " + att_value + "\n");

                return NULL;
            }
            else
            {
                // Return Node
                return tagNode;
            }
        }
        // Obtain node based on LIST
        else
        {
            int32_t realIndex = index;

            // Transform index to real index
            if (index < 0)
            {
                realIndex = node_tag_list.getLength() + index;
            }

            // Check bounds
            if (realIndex < 0 || realIndex >= node_tag_list.getLength())
            {
                // Throw eprosima::qosprof::ElementNotFound exception
                throw eprosima::qosprof::ElementNotFound(
                    tag_name + " does not have an element in position " + std::to_string(realIndex) + "\n");

                return NULL;
            }
            // Return Node
            return node_tag_list.item(realIndex);
        }
    }
}

void validate_xml(
        const std::string& xml_file,
        xercesc::XercesDOMParser& parser)
{
    // TODO make this static
    std::string xsdFile = "/home/jesus/Fast-DDS/src/fastrtps/resources/xsd/fastRTPS_profiles.xsd";

    // Create parser for validation
    std::string namespaceSchemaLocation = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles " + xsdFile;

    // Load XSD schema
    parser.loadGrammar(xsdFile.c_str(),xercesc::Grammar::SchemaGrammarType, true);
    parser.setExternalSchemaLocation(namespaceSchemaLocation.c_str());

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::ElementInvalid);
    parser.setErrorHandler(xmlErrorHandler);

    // Validation configuration
    parser.setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
    parser.setDoNamespaces(true);
    parser.setDoSchema(true);
    parser.setValidationConstraintFatal(true);

    // Parse file
    try
    {
        parser.parse(xml_file.c_str());
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
    }

    delete xmlErrorHandler;

    return;
}

void save_xml(
        const std::string& xml_file,
        const xercesc::DOMDocument& doc)
{
    // Create file
    xercesc::DOMImplementation* xmlImplementation =
        xercesc::DOMImplementationRegistry::getDOMImplementation (xercesc::XMLString::transcode("Core"));
    if (xmlImplementation == NULL)
    {
        closeXML();

        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported("Could not initialize XML workspace");

        return;
    }
    // Save the created elements in the given file
    xercesc::DOMLSOutput* xmlOutput = xmlImplementation->createLSOutput();
    xercesc::DOMLSSerializer* xmlWriter = ((xercesc::DOMImplementationLS*)xmlImplementation)->createLSSerializer();;
    xercesc::XMLFormatTarget* xmlTargetName = new xercesc::LocalFileFormatTarget(
        xercesc::XMLString::transcode(xml_file.c_str()));
    xmlOutput->setByteStream(xmlTargetName);
    xmlOutput->setEncoding(xercesc::XMLString::transcode("UTF-8"));
    xmlWriter->setNewLine(xercesc::XMLString::transcode("\n"));
    xercesc::DOMConfiguration* xmlConfiguration = xmlWriter->getDomConfig();
    xmlConfiguration->setParameter(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint, true);
    xmlConfiguration->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, true);
    xercesc::DOMNode* rootNode = (xercesc::DOMNode*)doc.getDocumentElement();
    xmlWriter->write(rootNode, xmlOutput);

    // Ended working with the document, release resources
    delete xmlConfiguration;
    delete xmlWriter;
    delete xmlOutput;
    delete xmlTargetName;
}

void clear_node(
        const std::string& xml_file,
        xercesc::DOMNode& parent_node,
        xercesc::DOMNode& node_to_be_deleted)

{
    if (parent_node.hasChildNodes())
    {
        if (parent_node.getChildNodes()->getLength() == 1 &&
            parent_node.getChildNodes()->item(0)->getNodeName() == node_to_be_deleted.getNodeName())
        {
            // report exception
            std::string message = "could not delete last element from ";
            message.append(xercesc::XMLString::transcode(parent_node.getNodeValue()));
            message.append(". Delete element by running the predecessor clear API.\n");
            throw eprosima::qosprof::ElementInvalid(message);
            return;
        }
    }
    parent_node.removeChild(&node_to_be_deleted);
    node_to_be_deleted.release();
    delete &node_to_be_deleted;
}

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name)
{
    try
    {
        return get_node(parser, tag_name, 0, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        int32_t index)
{
    try
    {
        return get_node(parser, tag_name, index, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    try
    {
        return get_node(parser, tag_name, 0, att_name, att_value);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Open document
    xercesc::DOMDocument* doc = parser.getDocument();

    // Obtain root element
    xercesc::DOMElement* xmlRoot = doc->getDocumentElement();

    xercesc::DOMNode* node = NULL;

    // Obtain node from root
    try
    {
        node = get_node(*xmlRoot->getElementsByTagName(xercesc::XMLString::transcode(tag_name.c_str())), tag_name, index, att_name, att_value);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

    }
    // Delete resources
    delete xmlRoot;
    delete doc;

    return node;
}

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name)
{
    try
    {
        return get_node(parent_node, tag_name, 0, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        int32_t index)
{
    try
    {
        return get_node(parent_node, tag_name, index, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value)
{
    try
    {
        return get_node(parent_node, tag_name, 0, att_name, att_value);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value)
{
    // Obtain node from parent node
    try
    {
        return get_node(*parent_node.getChildNodes(), tag_name, index, att_name, att_value);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}
