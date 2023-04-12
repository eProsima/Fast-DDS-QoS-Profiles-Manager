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

#include <utils/XMLManager.hpp>

#include <unistd.h>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/StringXMLManager.hpp>
#include <utils/TagsXMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

XMLManager::XMLManager (
        const std::string& file_name,
        bool create_file)
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
        throw Error(xercesc::XMLString::transcode(toCatch.getMessage()));
    }

    // Create Xerces implementation
    implementation = xercesc::DOMImplementationRegistry::getDOMImplementation (
        xercesc::XMLString::transcode(CORE));
    if (implementation == nullptr)
    {
        // Could not initialize XML workspace
        throw Error("Could not set XML workspace");
    }

    // Create Xerces Required elements based on the implementation
    // Serializer and output would export the Document's nodes into a legible string / file
    serializer = (static_cast<xercesc::DOMImplementationLS*>(implementation))->createLSSerializer();
    output = implementation->createLSOutput();
    output->setEncoding(xercesc::XMLString::transcode(UTF8));
    serializer->setNewLine(xercesc::XMLString::transcode(LINE_BREAK));

    // Parser would validate the serialized XML against the defined XSD, with some configured parameters
    parser = new xercesc::XercesDOMParser();

    // Error handler would receive the exception from the parser, and report it as a FileNotFound expected exception
    error_handler = new utils::ErrorHandlerXMLManager(
        utils::ErrorHandlerXMLManager::Kind::FileNotFound);
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
    catch (const FileNotFound& ex)
    {
        // Create new document if required
        if (create_file && !file_exists)
        {
            // Implementation would create an empty document
            doc = implementation->createDocument(0, xercesc::XMLString::transcode(
                                utils::tag::ROOT), 0);
            // The root element would be <dds>, with the 'xmlns' att.
            doc->getDocumentElement()->setAttribute(
                xercesc::XMLString::transcode(utils::tag::XMLNS),
                xercesc::XMLString::transcode(utils::tag::EPROSIMA_URL));
        }
        // Propagate the exception
        else
        {
            throw FileNotFound(ex);
        }
    }

    // Obtain first document node
    last_node = static_cast<xercesc::DOMNode*>(doc->getDocumentElement());

    // Check if XML document has rooted structure
    transform_standalone_to_rooted_structure();

    // Set up Validation parameters: XSD pash
    std::string xsd_file_path = FASTDDS_QOS_PROFILES_MANAGER_XML_SCHEMA;
    // Set as namespace location both URL and the path to the XML schema
    std::string namespace_schema_location = utils::tag::EPROSIMA_URL;
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
}

XMLManager::~XMLManager()
{
    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();
}

void XMLManager::transform_standalone_to_rooted_structure()
{
    std::string root_name = xercesc::XMLString::transcode(last_node->getNodeName());

    // If NOT rooted structure (standalone structure)
    if (root_name != utils::tag::ROOT)
    {
        // Create new ROOT node
        xercesc::DOMNode* new_root_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                xercesc::XMLString::transcode(utils::tag::ROOT)));
        static_cast<xercesc::DOMElement*>(new_root_node)->setAttribute(
                xercesc::XMLString::transcode(utils::tag::XMLNS),
                xercesc::XMLString::transcode(utils::tag::EPROSIMA_URL));

        // Create copy of node
        xercesc::DOMNode* copy_node = static_cast<xercesc::DOMNode*>(doc->createElement(last_node->getNodeName()));

        // Recursive adoption to all child nodes:
        xercesc::DOMNodeList* root_child_nodes = last_node->getChildNodes();
        std::unique_ptr<std::vector<uint>> index_list = get_real_index(root_child_nodes);
        for (int i = 0, size = index_list->size(); i < size; i++)
        {
            xercesc::DOMNode* adopted_node = root_child_nodes->item(index_list->at(i));
            last_node->removeChild(adopted_node);
            copy_node->appendChild(adopted_node);
        }

        // Add the copy node to the new root node
        new_root_node->appendChild(copy_node);

        // Remove node from document
        doc->removeChild(last_node);

        // Add new root to the document
        doc->appendChild(new_root_node);

        // set new root
        last_node = new_root_node;
    }
}

void XMLManager::validate_and_save_document()
{
    if (validate_xml())
    {
        save_xml();
    }
}

bool XMLManager::validate_xml()
{
    // Set ElementInvalid error handler
    error_handler = new utils::ErrorHandlerXMLManager(
        utils::ErrorHandlerXMLManager::Kind::ElementInvalid);
    parser->setErrorHandler(error_handler);

    // Create a XML string buffer for validation
    utils::StringXMLManager* xml_string = new utils::StringXMLManager();

    // Save XML document in the XML string buffer
    output->setByteStream(xml_string);
    serializer->write(doc, output);
    xercesc::MemBufInputSource src(static_cast<XMLByte*>(xml_string->buffer()), xml_string->length(), "", false);

    // Validate the XML string buffer against the schema
    parser->parse(src);

    // Validation successful
    return true;
}

bool XMLManager::save_xml()
{
    // Config would configure serialized XML data
    config = serializer->getDomConfig();
    config->setParameter(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint, true);
    config->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, true);

    // Save XML document in target file path
    target = new xercesc::LocalFileFormatTarget(xercesc::XMLString::transcode(xml_file.c_str()));
    output->setByteStream(target);
    return serializer->write(doc, output);
}

void XMLManager::create_node(
        const std::string& tag_name)
{
    // Save parent node
    xercesc::DOMNode* parent_node = last_node;

    // Create new node and save it as last node
    last_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(tag_name.c_str())));

    // Append new node to parent node
    parent_node->appendChild(last_node);
}

void XMLManager::clear_node()
{
    // Remove node from parent
    xercesc::DOMNode* parent_node = last_node->getParentNode();

    // Check the dependency
    if (parent_node == nullptr)
    {
        // Throw Error
        std::string exception_message = "Could not delete node ";
        exception_message += xercesc::XMLString::transcode(last_node->getNodeName());
        throw Error(exception_message);
    }

    // Obtain main list of nodes
    xercesc::DOMNodeList* node_list = parent_node->getChildNodes();

    // Obtain REAL node list
    std::unique_ptr<std::vector<uint>> index_list = get_real_index(node_list);

    // Check if the node to be deleted is the last child node of the parent
    if (index_list->size() == 1)
    {
        // Invalid request: report exception
        std::string message = "Could not delete last element from ";
        message += xercesc::XMLString::transcode(parent_node->getNodeValue());
        message += ". Delete element by running the predecessor clear API.\n";

        // Throw ElementInvalid exception with custom message
        throw ElementInvalid(message);
    }

    // Remove node from child
    parent_node->removeChild(last_node);

    // Free node resources
    last_node->release();
}

void XMLManager::reset_node()
{
    // Loop for childs
    while (last_node->hasChildNodes())
    {
        // Obtain each node
        xercesc::DOMNode* node_to_be_deleted = last_node->getFirstChild();

        // Remove each child from parent node
        last_node->removeChild(node_to_be_deleted);

        // Free node resources
        node_to_be_deleted->release();
    }
}

void XMLManager::set_value_to_node(
        const std::string& value)
{
    // Remove all childs
    reset_node();

    // Set name value
    xercesc::DOMText* name_value = doc->createTextNode(xercesc::XMLString::transcode(value.c_str()));
    last_node->appendChild(name_value);
}

void XMLManager::set_attribute_to_node(
        const std::string& name,
        const std::string& value)
{
    // Set the attribute value
    static_cast<xercesc::DOMElement*>(last_node)->setAttribute(
        xercesc::XMLString::transcode(name.c_str()),
        xercesc::XMLString::transcode(value.c_str()));
}

void XMLManager::set_siblings_attribute(
        const std::string& name,
        const std::string& value)
{
    // Obtain all siblings
    xercesc::DOMNodeList* siblings_node_list = last_node->getParentNode()->getChildNodes();

    // Obtain REAL node list
    std::unique_ptr<std::vector<uint>> index_list = get_real_index(siblings_node_list);

    // Iterate through node siblings
    for (int i = 0, size = index_list->size(); i < size; i++)
    {
        xercesc::DOMNode* sibling_node = siblings_node_list->item(index_list->at(i));
        // siblings must have same tag name
        if (sibling_node->getNodeName() == last_node->getNodeName() && sibling_node != last_node)
        {
            // Set the attribute value
            static_cast<xercesc::DOMElement*>(sibling_node)->setAttribute(
                xercesc::XMLString::transcode(name.c_str()),
                xercesc::XMLString::transcode(value.c_str()));
        }
    }
}

std::string XMLManager::get_node_value()
{
    if (xercesc::XMLString::transcode(last_node->getNodeValue()) != nullptr)
    {
        return xercesc::XMLString::transcode(last_node->getNodeValue());
    }
    // Throw ElementNotFound exception
    std::string exception_message = "Could not find value of element ";
    exception_message += xercesc::XMLString::transcode(last_node->getNodeName());
    throw ElementNotFound(exception_message + "\n");
}

std::string XMLManager::get_node_attribute_value(
        const std::string& name)
{
    xercesc::DOMNode* attribute_node = last_node->getAttributes()->getNamedItem(
        xercesc::XMLString::transcode(name.c_str()));
    if (attribute_node != nullptr)
    {
        if (xercesc::XMLString::transcode(attribute_node->getNodeValue()) != nullptr)
        {
            return xercesc::XMLString::transcode(attribute_node->getNodeValue());
        }
    }

    // Throw ElementNotFound exception
    std::string exception_message = "Could not find attribute ";
    exception_message += name + " in element ";
    exception_message += xercesc::XMLString::transcode(last_node->getNodeName());
    throw ElementNotFound(exception_message + "\n");
}

void XMLManager::get_node(
        const std::string& tag_name,
        const bool create_if_not_existent)
{
    // Obtain list of nodes based on the target tag
    xercesc::DOMNodeList* node_list = static_cast<xercesc::DOMElement*>(last_node)->getElementsByTagName(
        xercesc::XMLString::transcode(tag_name.c_str()));

    // Check if node should be created if not found
    if (node_list->getLength() == 0)
    {
        if (create_if_not_existent)
        {
            create_node(tag_name);
        }
        // Throw ElementNotFound exception
        else
        {
            throw ElementNotFound("non-existent " + tag_name + " element\n");
        }
    }
    // Check for expected node
    else if (node_list->getLength() == 1)
    {
        // Return Node
        last_node = node_list->item(0);
    }
    // Unexpected issue (misuse of the method)
    else
    {
        throw Error("Expected single" + tag_name + " returned multiple elements\n");
    }
}

void XMLManager::get_node(
        const std::string& index,
        const std::string& default_tag_name,
        const bool create_if_not_existent)
{
    // Index not empty
    if (!index.empty())
    {
        // Obtain main list of nodes
        xercesc::DOMNodeList* node_list = last_node->getChildNodes();

        // Obtain REAL node list
        std::unique_ptr<std::vector<uint>> index_list = get_real_index(node_list);

        // Parse index value and obtain node
        int32_t real_index = 0;
        try
        {
            // Parse index from string to int
            real_index = std::stoi(index);
        }
        catch (std::exception)
        {
            throw BadParameter(index + " could not be used as integer index");
        }

        // Transform index to real index
        if (real_index < 0)
        {
            real_index = index_list->size() + real_index;
        }

        // Check bounds
        if (real_index >= 0 && real_index < index_list->size())
        {
            // Return Node
            last_node = node_list->item(index_list->at(real_index));
            return;
        }
        else
        {
            // Set up exception message to be thrown if node should not be created
            std::string exception_message = xercesc::XMLString::transcode(last_node->getNodeName());
            exception_message += " does not have an element in position " + std::to_string(real_index) + "\n";
            throw ElementNotFound(exception_message);
        }
    }
    // Check if node should be created if not found
    else if (create_if_not_existent)
    {
        create_node(default_tag_name);
    }
    // Throw ElementNotFound exception
    else
    {
        // Set up exception message to be thrown if node should not be created
        std::string exception_message = xercesc::XMLString::transcode(last_node->getNodeName());
        exception_message += " does not have an element in position " + index + "\n";
        throw ElementNotFound(exception_message);
    }
}

void XMLManager::get_node(
        const std::string& tag_name,
        const std::string& name,
        const std::string& value,
        const bool create_if_not_existent)
{
    // Obtain list of nodes based on the target tag
    xercesc::DOMNodeList* node_list = static_cast<xercesc::DOMElement*>(last_node)->getElementsByTagName(
        xercesc::XMLString::transcode(tag_name.c_str()));

    // Iterate through the nodes
    for (int i = 0, size = node_list->getLength(); i < size; i++)
    {
        // Get node name and attributes
        xercesc::DOMNamedNodeMap* node_attributes = node_list->item(i)->getAttributes();
        // If there are attributes
        if (node_attributes != nullptr)
        {
            // Obtain the attribute that matches the name
            xercesc::DOMNode* attribute_item = node_attributes->getNamedItem(
                xercesc::XMLString::transcode(name.c_str()));
            if (attribute_item != nullptr)
            {
                // If the value of the attribute match
                std::string item_value = xercesc::XMLString::transcode(attribute_item->getNodeValue());
                if (item_value == value)
                {
                    last_node = node_list->item(i);
                    return;
                }
            }
        }
    }

    // Check if node should be created if not found
    if (create_if_not_existent)
    {
        create_node(tag_name);

        // Record the given attribute name and attribute value in the new node
        set_attribute_to_node(name, value);
    }
    // Throw ElementNotFound exception
    else
    {
        throw ElementNotFound(
                  "non-existent " + tag_name + " element with attribute " + name + " and value " + value +
                  "\n");
    }
}

void XMLManager::get_locator_node(
        const std::string& index,
        const bool is_external,
        const bool create_if_not_existent)
{
    // Set default tag name for locator
    std::string default_tag_name = utils::tag::LOCATOR;

    // Update the default tag name if external locator case
    if (is_external)
    {
        default_tag_name = utils::tag::UDP_V4_LOCATOR;
    }

    // Obtain element from list
    get_node(index, default_tag_name, create_if_not_existent);

    // Check if external or common locator
    std::string tag = xercesc::XMLString::transcode(last_node->getNodeName());
    if (tag == utils::tag::LOCATOR)
    {
        // Obtain main list of nodes
        xercesc::DOMNodeList* node_list = last_node->getChildNodes();

        // Obtain REAL node list
        std::unique_ptr<std::vector<uint>> index_list = get_real_index(node_list);

        // If there are kind children
        if (index_list->size() > 0)
        {
            // Save locator kind as current node
            last_node = node_list->item(index_list->at(0));
        }
        // Create default kind children if required
        else if (create_if_not_existent)
        {
            create_node(utils::tag::UDP_V4_LOCATOR);
        }
        // Throw ElementNotFound exception
        else
        {
            std::string exception_message = xercesc::XMLString::transcode(last_node->getNodeName());
            exception_message += " collection is empty\n";
            throw ElementNotFound(exception_message);
        }
    }
}

std::string XMLManager::get_absolute_path(
        const std::string& xml_file,
        bool file_exists)
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

std::unique_ptr<std::vector<uint>> XMLManager::get_real_index(
        xercesc::DOMNodeList*& node_list)
{
    // Create new list
    std::unique_ptr<std::vector<uint>> index_list (new std::vector<uint>());

    // Iterate through the list
    for (uint i = 0, size = node_list->getLength(); i < size; i++)
    {
        if (node_list->item(i)->getNodeType() == xercesc::DOMNode::NodeType::ELEMENT_NODE)
        {
            index_list->push_back(i);
        }
    }

    // return list
    return index_list;
}

} /* utils */
} /* qosprof */
} /* eprosima */
