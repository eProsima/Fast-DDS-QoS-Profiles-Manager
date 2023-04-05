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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_

#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>

#include <utils/ParseXMLErrorHandler.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

/**
 * @brief ParseXML is a tool to manage easily the XML elements given by Xerces
 *  library. It would deploy different functions to make the public library API
 *  easier to implement.
 *
 */
class ParseXML
{
public:

    /**
     * @brief Construct a new Parse XML object, which initializes Xerces required tools,
     *  and reads given xml_file document
     *
     * @param[in out] doc DOMDocument* to be created
     * @param[in] xml_file string with the file path
     * @param[in] create_file bool (optional) create file if it does not exist flag
     *
     * @throw FileNotFound exception if Xerces XML workspace could not be initialized
     */
    ParseXML(
            xercesc::DOMDocument*& doc,
            const std::string& xml_file,
            bool create_file = false);

    /**
     * @brief Pase XML Destructor
     *
     */
    ~ParseXML();

    /**
     * @brief Validate the document, and save to disk if valid
     *
     * @param doc DOMDocument XML document with the parsed / created nodes
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     */
    void validate_and_save_xml_document(
            xercesc::DOMDocument*& doc);

    /**
     * @brief  MAIN get_node function.
     *   Obtain the node in the list that matches tag name and
     *   the given index or the given name-value attribute pair
     *
     * @param node_tag_list DOMNodeList list of nodes where tag_name should be part of
     * @param tag_name string with the node (<tag>) name
     * @param index int32 index of the node element in LIST cases
     * @param att_name string key (attribute) name of the node element in MAP cases
     * @param att_value string key (attribute) value of the node element in MAP cases
     *
     * @return xercesc::DOMNode* with the node found
     *
     * @throw ElementNotFound exception if expected node was not found
     */
    xercesc::DOMNode* get_node(
            xercesc::DOMNodeList*& node_tag_list,
            const std::string& tag_name,
            int32_t index,
            const std::string& att_name,
            const std::string& att_value);

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
     * @brief Clear node. Usage: remove all DOMText children from node
     *
     * @param node DOMNode to be reset
     */
    void reset_node(
            xercesc::DOMNode*& node);

    /**
     * @brief Set the value to node object
     *
     * @param[in out] doc DOMDocument* document to use
     * @param node DOMNode node to be set
     * @param value to be set in the node
     */
    void set_value_to_node(
            xercesc::DOMDocument*& doc,
            xercesc::DOMNode*& node,
            const std::string& value);

    /*
     * AUX get_node functions based on the implementation needs
     */
    xercesc::DOMNode* get_node(
            xercesc::DOMDocument*& doc,
            const std::string& tag_name);

    xercesc::DOMNode* get_node(
            xercesc::DOMDocument*& doc,
            const std::string& tag_name,
            int32_t index);

    xercesc::DOMNode* get_node(
            xercesc::DOMDocument*& doc,
            const std::string& tag_name,
            const std::string& att_name,
            const std::string& att_value);

    xercesc::DOMNode* get_node(
            xercesc::DOMDocument*& doc,
            const std::string& tag_name,
            int32_t index,
            const std::string& att_name,
            const std::string& att_value);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            int32_t index);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            const std::string& att_name,
            const std::string& att_value);

    xercesc::DOMNode* get_node(
            xercesc::DOMNode*& parent_node,
            const std::string& tag_name,
            int32_t index,
            const std::string& att_name,
            const std::string& att_value);

private:

    /**
     * @brief Save the document as string and validate
     *
     * @param doc DOMDocument XML document with the parsed / created nodes
     *
     * @return true document passes parser validation
     * @return false document does not pass parser validation
     *
     * @throw ElementInvalid exception if document does not pass parser validation
     */
    bool validate_xml(
            xercesc::DOMDocument*& doc);

    /**
     * @brief  Save the document in the target file path
     *
     * @param doc DOMDocument XML document with the parsed / created nodes
     *
     * @return true document saved
     * @return false failure saving document
     */
    bool save_xml(
            xercesc::DOMDocument*& doc);

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

    // CONSTANT CHAR USED BY XERCES
    constexpr static const char* CORE = "Core";
    constexpr static const char* UTF8 = "UTF-8";
    constexpr static const char* LINE_BREAK = "\n";

    // Xerces tools required for node management
    xercesc::DOMConfiguration* config = nullptr;
    xercesc::DOMImplementation* implementation = nullptr;
    xercesc::DOMLSOutput* output = nullptr;
    xercesc::XercesDOMParser* parser = nullptr;
    xercesc::DOMLSSerializer* serializer = nullptr;
    xercesc::XMLFormatTarget* target = nullptr;

    // XML file path
    std::string xml_file;

    // Custom utils
    eprosima::qosprof::utils::ParseXMLErrorHandler* error_handler = nullptr;
};

} /* parse */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
