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
     *  and reads given xml_file document.
     *
     * @param[in] xml_file string with the file path
     * @param[in] create_file bool (optional) create file if the flag is set
     *
     * @throw Error exception if Xerces XML workspace could not be initialized
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
     * @brief Validate the document, and save to disk if valid.
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     */
    void validate_and_save_document();

    /**
     * @brief Remove the selected node.
     *
     * @throw ElementInvalid exception if node is the last node element (could not be deleted)
     */
    void clear_node();

    /**
     * @brief Set the value to node object.
     *
     * @param[in] value to be set in the node
     */
    void set_value_to_node(
            const std::string& value);

    /**
     * @brief Set the attribute value associated to the attribute name attached to the node object.
     *
     * @param[in] name of the attribute to be set
     * @param[in] value to be set in the node attribute
     */
    void set_attribute_to_node(
            const std::string& name,
            const std::string& value);

    /**
     * @brief Set the specific attribute of all node siblings to the given value.
     *
     * @param[in] name of the node attribute to be set
     * @param[in] value to be set in the node attribute
     */
    void set_siblings_attribute(
            const std::string& name,
            const std::string& value);


    /**
     * @brief Get the node value (only for simple cases)
     *
     * @throw ElementNotFound exception if the node value could not be obtained
     *
     * @return std::string node value (Empty string if error)
     */
    std::string get_node_value();

    /**
     * @brief Get the node attribute value of the given attribute name
     *
     * @param[in] name attribute name
     *
     * @throw ElementNotFound exception if the attribute value could not be obtained from the node
     *
     * @return std::string node attribute value (Empty string if error)
     */
    std::string get_node_attribute_value(
            const std::string& name);

    /**
     * @brief Get the (unique) child node object that matches the given tag name.
     *
     * @param[in] tag_name string with the node (<tag>) name
     * @param[in] create_if_not_existent flag to create node if it is not found
     *
     * @throw ElementNotFound exception if expected node was not found and node creation was not required
     */
    void get_node(
            const std::string& tag_name,
            const bool create_if_not_existent);

    /**
     * @brief Get the node object located in the index position. If empty index, current node is kept.
     *
     * @param[in] index string index of the node element
     * @param[in] default_tag_name string with the default node (<tag>) name required to create the node if required.
     * @param[in] create_if_not_existent flag to create node if it is not found
     *
     * @throw ElementNotFound exception if expected node was not found and node creation was not required
     */
    void get_node(
            const std::string& index,
            const std::string& default_tag_name,
            const bool create_if_not_existent);

    /**
     * @brief Get the node object that matches the given tag name, and has the same attribute key-value pair
     *        set as the given name-value pair.
     *
     * @param[in] tag_name string with the node (<tag>) name
     * @param[in] name string key (attribute) name of the node element
     * @param[in] value string value (attribute) value of the node element
     * @param[in] create_if_not_existent flag to create node if it is not found
     *
     * @throw ElementNotFound exception if expected node was not found and node creation was not required
     */
    void get_node(
            const std::string& tag_name,
            const std::string& name,
            const std::string& value,
            const bool create_if_not_existent);

    /**
     * @brief Get the locator node object found at index position. If empty index, current node is kept.
     *
     * @param[in] index string index of the node element
     * @param[in] is_external flag to determine if the locator node is external or common
     * @param[in] create_if_not_existent flag to create node if it is not found
     *
     * @throw ElementNotFound exception if expected node was not found and node creation was not required
     */
    void get_locator_node(
            const std::string& index,
            const bool is_external,
            const bool create_if_not_existent);

private:

    /**
     * @brief Save the document as string and validate.
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     *
     * @return true document passes parser validation
     * @return false document does not pass parser validation
     */
    bool validate_xml();

    /**
     * @brief  Save the document in the target file path.
     *
     * @return true document saved
     * @return false failure saving document
     */
    bool save_xml();

    /**
     * @brief Auxiliar method that creates a new node with the given tag and appends it to the last node.
     *
     * @param tag_name string with the new node (<tag>) name
     */
    void create_node(
            const std::string& tag_name);

    /**
     * @brief Get the absolute path of the given file name (POSIX only).
     *
     * @param[in]  xml_file string with the given file name
     * @param[out] file_exists bool reference to save file existence status
     *
     * @return std::string with the absolute path
     */
    std::string get_absolute_path(
            const std::string& xml_file,
            bool file_exists);

    /**
     * @brief Get the real index of the listed nodes (avoid empty nodes).
     *
     * @param[in]  node_list with the nodes to be filtered
     *
     * @return std::unique_ptr<std::vector<uint>> with the indexes of the non-empty nodes
     */
    std::unique_ptr<std::vector<uint>>  get_real_index(
            xercesc::DOMNodeList*& node_list);

    /**
     * @brief Clear node. Usage: remove all DOMText children from node.
     *
     */
    void reset_node();

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

    // Latest node navigated to
    xercesc::DOMNode* last_node = nullptr;
};

} /* parse */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_XML_MANAGER_HPP_
