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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_TAGS_XML_MANAGER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_TAGS_XML_MANAGER_HPP_

namespace eprosima {
namespace qosprof {
namespace utils {
namespace tag {

// HEADER TAGS
constexpr const char* EPROSIMA_URL = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles";
constexpr const char* XMLNS = "xmlns";

// MAIN ROOT TAGS
constexpr const char* PROFILES = "profiles";
constexpr const char* ROOT = "dds";

// PROFILE TAGS
constexpr const char* DATA_READER = "data_reader";
constexpr const char* DATA_WRITER = "data_writer";
constexpr const char* DEFAULT_PROFILE = "is_default_profile";
constexpr const char* PARTICIPANT = "participant";
constexpr const char* PROFILE_NAME = "profile_name";
constexpr const char* TRANSPORT_DESCRIPTOR_LIST = "transport_descriptors";

/// PARTICIPANT
constexpr const char* RTPS = "rtps";

/// RTPS PARTICIPANT
constexpr const char* BUILTIN = "builtin";
constexpr const char* DEFAULT_EXTERNAL_UNICAST_LOCATOR_LIST = "default_external_unicast_locators";
constexpr const char* INITIAL_PEERS_LIST = "initialPeersList";
constexpr const char* METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST = "metatraffic_external_unicast_locators";
constexpr const char* NAME = "name";
constexpr const char* USE_BUILTIN_TRANSPORTS = "useBuiltinTransports";
constexpr const char* USER_TRANSPORTS = "userTransports";

//// BUILTIN RTPS PARTICIPANT
constexpr const char* DISCOVERY_CONFIG = "discovery_config";

///// DISCOVERY CONFIG BUILTIN
constexpr const char* LEASE_ANNOUNCEMENT = "leaseAnnouncement";
constexpr const char* LEASE_DURATION = "leaseDuration";

/// TRANSPORT DESCRIPTOR LIST
constexpr const char* INTERFACE_WHITELIST = "interfaceWhiteList";
constexpr const char* TRANSPORT_DESCRIPTOR = "transport_descriptor";
constexpr const char* TRANSPORT_ID = "transport_id";
constexpr const char* TRANSPORT_KIND = "type";

// COMMONS
/// LOCATOR
constexpr const char* ADDRESS = "address";
constexpr const char* EXTERNALITY = "externality";
constexpr const char* LOCATOR = "locator";
constexpr const char* PORT = "port";
constexpr const char* UDP_V4_LOCATOR = "udpv4";
constexpr const char* UDP_V6_LOCATOR = "udpv6";

/// DURATION TYPE
constexpr const char* NANOSEC = "nanosec";
constexpr const char* SEC = "sec";

/// QOS
constexpr const char* DURABILITY = "durability";
constexpr const char* KIND = "kind";
constexpr const char* QOS = "qos";
constexpr const char* RELIABILITY = "reliability";

} /* tag */
} /* utils */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_TAGS_XML_MANAGER_HPP_
