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

#include <utils/ParseXMLErrorHandler.hpp>

XercesDOMParser* openXML(
        const std::string& xml_file);

void closeXML();

DOMNode* getNode(
        const DOMNodeList& tagNodeList,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue);

void validateXML(
        const std::string& xmlFile
        const XercesDOMParser& xmlParser);

void saveXML(
        const std::string& xmlFile,
        const DOMDocument& xmlDoc);





DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index);

DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue);

DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue);

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName);

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        int32_t index);

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue);

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue);

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
