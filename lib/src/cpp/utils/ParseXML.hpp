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
 * @file ParseXML.hpp
 */

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_

#include <string>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>

#include "utils/ParseXMLErrorHandler.hpp"

/**
 * @brief Initialize Xerces required tools, and reads given xml_file document
 *
 * @param config DOMConfiguration NULL pointer to be created
 * @param doc DOMDocument NULL pointer to be created
 * @param error_handler ParseXMLErrorHandler NULL pointer to be created
 * @param implementation DOMImplementation NULL pointer to be created
 * @param output DOMLSOutput NULL pointer to be created
 * @param parser XercesDOMParser NULL pointer to be created
 * @param serializer DOMLSSerializer NULL pointer to be created
 * @param target XMLFormatTarget NULL pointer to be created
 * @param xml_file string with the file path
 *
 * @return true Xerces XML workspace initialized successfully
 * @return false Xerces XML workspace could not be initialized
 *
 * @throw FileNotFound exception if Xerces XML workspace could not be initialized
 */
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
);

/**
 * @brief Validate the document, and save to disk if valid
 *
 * @param doc DOMDocument XML document with the parsed / crated nodes
 * @param error_handler ParseXMLErrorHandler to handle validation errors
 * @param output DOMLSOutput tool to set destination of serialization
 * @param parser XercesDOMParser validation tool
 * @param serializer DOMLSSerializer tool to write the XML document in the selected output
 * @param target XMLFormatTarget configured xml file path
 *
 * @throw ElementInvalid exception if document does not pass parser validation
 */
void validate_and_save_xml_document(
    xercesc::DOMDocument*& doc,
    eprosima::qosprof::parse::ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target);

/**
 * @brief Save the document as string and validate
 *
 * @param doc DOMDocument XML document with the parsed / crated nodes
 * @param error_handler ParseXMLErrorHandler to handle validation errors
 * @param output DOMLSOutput tool to set destination of serialization
 * @param parser XercesDOMParser validation tool
 * @param serializer DOMLSSerializer tool to write the XML document in the selected output
 *
 * @return true document passes parser validation
 * @return false document does not pass parser validation
 *
 * @throw ElementInvalid exception if document does not pass parser validation
 */

bool validate_xml(
    xercesc::DOMDocument*& doc,
    eprosima::qosprof::parse::ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer);

/**
 * @brief  Save the document in the target file path
 *
 * @param doc DOMDocument XML document with the parsed / crated nodes
 * @param output DOMLSOutput tool to set destination of serialization
 * @param serializer DOMLSSerializer tool to write the XML document in the selected output
 * @param target XMLFormatTarget configured xml file path
 *
 * @return true document saved
 * @return false failure saving document
 */
bool save_xml(
    xercesc::DOMDocument*& doc,
    xercesc::DOMLSOutput*& output,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target);

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
 * @return NULL if node not found
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
 * @throw ElementInvalid exception if node was last element node (could not be deleted)
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
 * @brief Get the absolute path of the given file name
 *
 * @param[in]  xml_file string with the given file name
 * @param[out] file_exists bool reference to save file existence status
 * @return std::string with the absolute path
 */
std::string get_absolute_path(
        const std::string& xml_file,
        bool& file_exists);

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

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
