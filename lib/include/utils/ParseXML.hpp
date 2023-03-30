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

#include <fastdds_qos_profiles_manager_dll.h>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>

#include <utils/ParseXMLErrorHandler.hpp>

/*
 * Initialize Xerces required tools, and reads given xml_file document
 */
bool initialize_tools (
    xercesc::DOMConfiguration*& config,
    xercesc::DOMDocument*& doc,
    ParseXMLErrorHandler*& error_handler,
    xercesc::DOMImplementation*& implementation,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target,
    const std::string& xml_file
);

/*
 * Validate the document, and save to disk if valid
 */
void validate_and_save_xml_document(
    xercesc::DOMDocument*& doc,
    ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target);

/*
 * Save the document as string and validate
 */
bool validate_xml(
    xercesc::DOMDocument*& doc,
    ParseXMLErrorHandler*& error_handler,
    xercesc::DOMLSOutput*& output,
    xercesc::XercesDOMParser*& parser,
    xercesc::DOMLSSerializer*& serializer);

/*
 * Save the document in the target file path
 */
bool save_xml(
    xercesc::DOMDocument*& doc,
    xercesc::DOMLSOutput*& output,
    xercesc::DOMLSSerializer*& serializer,
    xercesc::XMLFormatTarget*& target);

/*
 * MAIN get_node function
 *   Obtain the node in the list that matches tag name and
 *   the given index or the given name-value attribute pair
 */
xercesc::DOMNode* get_node(
        xercesc::DOMNodeList*& node_tag_list,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value);

/*
 * Remote the given node from the parent node
 */
void clear_node(
        const std::string& xml_file,
        xercesc::DOMNode*& parent_node,
        xercesc::DOMNode*& node_to_be_deleted);

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
