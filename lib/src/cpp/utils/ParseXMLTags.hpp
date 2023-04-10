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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_

namespace eprosima {
namespace qosprof {
namespace utils {
namespace tag {

// HEADER TAGS
constexpr const char* XMLNS = "xmlns";
constexpr const char* EPROSIMA_URL = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles";

// MAIN ROOT TAGS
constexpr const char* ROOT = "dds";
constexpr const char* PROFILES = "profiles";

// PROFILE TAGS
constexpr const char* PROFILE_NAME = "profile_name";
constexpr const char* DEFAULT_PROF = "is_default_profile";
constexpr const char* PARTICIPANT = "participant";

/// PARTICIPANT
constexpr const char* RTPS = "rtps";

/// RTPS PARTICIPANT
constexpr const char* NAME = "name";
constexpr const char* BUILTIN = "builtin";
constexpr const char* METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST = "metatraffic_external_unicast_locators";

// COMMONS
/// LOCATOR
constexpr const char* UDP_V4_LOCATOR = "udpv4";
constexpr const char* UDP_V6_LOCATOR = "udpv6";
constexpr const char* EXTERNALITY = "externality";

} /* tag */
} /* utils */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_
