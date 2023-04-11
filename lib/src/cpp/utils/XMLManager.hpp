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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_XML_MANAGER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_XML_MANAGER_HPP_

#include <memory>
#include <string>
#include <vector>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>

#include <utils/ErrorHandlerXMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

/**
 * @brief XMLManager is a tool to manage easily the XML elements given by Xerces
 *  library. It would deploy different functions to make the public library API
 *  easier to implement.
 *
 */
class XMLManager
{
public:

    /**
     * @brief Construct a new Parse XML object, which initializes Xerces required tools,
     *  and reads given xml_file document
     *
     * @param[in] xml_file string with the file path
     * @param[in] create_file bool (optional) create file if it does not exist flag
     *
     * @throw FileNotFound exception if Xerces XML workspace could not be initialized
     */
    XMLManager(
            const std::string& xml_file,
            bool create_file = false);

    /**
     * @brief Pase XML Destructor
     *
     */
    ~XMLManager();

    /**
     * @brief Validate the document, and save to disk if valid
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     */
    void validate_and_save_document();

    /**
     * @brief Remove the given node from the parent node
     *
     * @param parent_node DOMNode parent node which should contain the node to be deleted
     * @param node_to_be_deleted DOMNode node to be deleted
     *
     * @throw ElementInvalid exception if node is the last node element (could not be deleted)
     */
    void clear_node(
            xercesc::DOMNode*& parent_node,
            xercesc::DOMNode*& node_to_be_deleted);

    /**
     * @brief Set the value to node object
     *
     * @param node DOMNode node to be set
     * @param value to be set in the node
     */
    void set_value_to_node(
            xercesc::DOMNode*& node,
            const std::string& value);

    /**
     * @brief Set the attribute value associated to the attribute name to node object
     *
     * @param node DOMNode node which attribute would be set
     * @param name to set the node attribute
     * @param value to be set in the node
     */
    void set_attribute_to_node(
            xercesc::DOMNode*& node,
            const std::string& name,
            const std::string& value);

    /**
     * @brief Temporal function to get the doc object
     *
     * @return xercesc::DOMDocument* doc object
     */
    xercesc::DOMDocument* get_doc();

    /*
     * AUX get_node functions based on the implementation needs
     */
    xercesc::DOMNode* get_node(
            const std::string& tag_name);

    xercesc::DOMNode* get_node(
            const std::string& tag_name,
            const std::string* index);

    xercesc::DOMNode* get_node(
            const std::string& tag_name,
            const std::string& att_name,
            const std::string& att_value);

    xercesc::DOMNode* get_node(
            const std::string& tag_name,
            const std::string* index,
            const std::string& att_name,
            const std::string& att_value);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            const std::string* index);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            const std::string& att_name,
            const std::string& att_value);

    /**
     * @brief  MAIN get_node function.
     *   Obtain the node in the list that matches tag name and
     *   the given index or the given name-value attribute pair
     *
     * @param parent_node DOMNode with the parent node
     * @param tag_name string with the node (<tag>) name
     * @param index string index of the node element in LIST cases
     * @param att_name string key (attribute) name of the node element in MAP cases
     * @param att_value string key (attribute) value of the node element in MAP cases
     *
     * @return xercesc::DOMNode* with the found node
     *
     * @throw ElementNotFound exception if expected node was not found
     */
    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            const std::string* index,
            const std::string& att_name,
            const std::string& att_value);

private:

    /**
     * @brief Save the document as string and validate
     *
     * @return true document passes parser validation
     * @return false document does not pass parser validation
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     */
    bool validate_xml();

    /**
     * @brief  Save the document in the target file path
     *
     * @return true document saved
     * @return false failure saving document
     */
    bool save_xml();

    /**
     * @brief Get the absolute path of the given file name [POSIX only]
     *
     * @param[in]  xml_file string with the given file name
     * @param[out] file_exists bool reference to save file existence status
     * @return std::string with the absolute path
     */
    std::string get_absolute_path(
            const std::string& xml_file,
            bool& file_exists);

    /**
     * @brief Get the real index of the listed nodes (avoid empty nodes)
     *
     * @param[in]  node_list with the nodes to be filtered
     * @return std::unique_ptr<std::vector<uint>> with the indexes of the non-empty nodes
     */
    std::unique_ptr<std::vector<uint>>  get_real_index(
            xercesc::DOMNodeList*& node_list);

    /**
     * @brief Clear node. Usage: remove all DOMText children from node
     *
     * @param node DOMNode to be reset
     */
    void reset_node(
            xercesc::DOMNode*& node);

    // CONSTANT CHAR USED BY XERCES
    constexpr static const char* CORE = "Core";
    constexpr static const char* UTF8 = "UTF-8";
    constexpr static const char* LINE_BREAK = "\n";

    // Xerces tools required for node management
    xercesc::DOMConfiguration* config = nullptr;
    xercesc::DOMDocument* doc = nullptr;
    xercesc::DOMImplementation* implementation = nullptr;
    xercesc::DOMLSOutput* output = nullptr;
    xercesc::XercesDOMParser* parser = nullptr;
    xercesc::DOMLSSerializer* serializer = nullptr;
    xercesc::XMLFormatTarget* target = nullptr;

    // XML file path
    std::string xml_file;

    // Custom utils
    utils::ErrorHandlerXMLManager* error_handler = nullptr;
};

} /* parse */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_XML_MANAGER_HPP_
