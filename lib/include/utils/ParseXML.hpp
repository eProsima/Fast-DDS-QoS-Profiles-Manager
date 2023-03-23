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

#include <utils/ParseXMLErrorHandler.hpp>

xercesc::XercesDOMParser* open_xml(
        const std::string& xml_file);

void closeXML();

xercesc::DOMNode* get_node(
        const xercesc::DOMNodeList& node_tag_list,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value);

void validate_xml(
        const std::string& xml_file,
        xercesc::XercesDOMParser& parser);

void save_xml(
        const std::string& xml_file,
        const xercesc::DOMDocument& doc);

void clear_node(
        const std::string& xml_file,
        xercesc::DOMNode& parent_node,
        xercesc::DOMNode& node_to_be_deleted);

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name);

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        int32_t index);

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value);

xercesc::DOMNode* get_node(
        xercesc::XercesDOMParser& parser,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value);

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name);

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        int32_t index);

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        const std::string& att_name,
        const std::string& att_value);

xercesc::DOMNode* get_node(
        const xercesc::DOMNode& parent_node,
        const std::string& tag_name,
        int32_t index,
        const std::string& att_name,
        const std::string& att_value);

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
