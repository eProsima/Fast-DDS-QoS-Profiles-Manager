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

#include <fastdds_qos_profiles_manager_dll.h>

/**
 * @brief Get the absolute path of the given file name
 *
 * @param xml_file string with the given file name
 * @return std::string with the absolute path
 */
std::string get_absolute_path(
        const std::string& xml_file);

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_HPP_
