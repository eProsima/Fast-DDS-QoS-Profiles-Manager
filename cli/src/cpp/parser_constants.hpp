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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_PARSER_CONSTANTS_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_PARSER_CONSTANTS_HPP_

namespace eprosima {
namespace qosprof_cli {

// Parser tags
constexpr const char* PARSER_ARGS = "<args>";
constexpr const char* PARSER_ELEMENT = "<element>";
constexpr const char* PARSER_FILE = "<file>";
constexpr const char* PARSER_VALUES = "<values>";
constexpr const char* PARSER_COMMAND = "<command>";

// CLI supported commands
constexpr const char* CLEAR_COMMAND = "clear";
constexpr const char* COMPARE_COMMAND = "compare";
constexpr const char* HELP_COMMAND = "help";
constexpr const char* PRINT_COMMAND = "print";
constexpr const char* QUERY_COMMAND = "query";
constexpr const char* SET_COMMAND = "set";
constexpr const char* VALIDATE_COMMAND = "validate";

// CLI supported help flags
constexpr const char* HELP_SHORTHAND_FLAG = "-h";
constexpr const char* HELP_FLAG = "--help";

// CLI supported main elements
constexpr const char* DATAREADER_ELEMENT = "datareader";
constexpr const char* DATAWRITER_ELEMENT = "datawriter";
constexpr const char* INTRAPROCESS_ELEMENT = "intraprocess";
constexpr const char* LOG_ELEMENT = "log";
constexpr const char* PARTICIPANT_ELEMENT = "participant";
constexpr const char* TOPIC_ELEMENT = "topic";
constexpr const char* TRANSPORT_ELEMENT = "transport_descriptor";
constexpr const char* TYPES_ELEMENT = "types";

// CLI common main subelements
constexpr const char* ALLOCATIONS_SUBELEMENT = "allocations";
constexpr const char* BINARY_PROPERTY_SUBELEMENT = "binary_property";
constexpr const char* DEFAULT_PROFILE_SUBELEMENT = "default_profile";
constexpr const char* DURATION_SUBELEMENT = "duration";
constexpr const char* EXTERNAL_LOCATORS_SUBELEMENT = "external_locators";
constexpr const char* IGNORE_NON_MATCHING_LOCATORS_SUBELEMENT = "ignore_non_matching_locators";
constexpr const char* KIND_SUBELEMENT = "kind";
constexpr const char* LOCATORS_SUBELEMENT = "locators";
constexpr const char* PORT_SUBELEMENT = "port";
constexpr const char* PROPERTY_SUBELEMENT = "property";

// CLI participant main subelements
constexpr const char* BUILTIN_SUBELEMENT = "builtin";
constexpr const char* DOMAIN_ID_SUBELEMENT = "domain_id";
constexpr const char* GUID_PREFIX_SUBELEMENT = "guid_prefix";
constexpr const char* ID_SUBELEMENT = "id";
constexpr const char* LISTEN_SOCKET_BUFFER_SIZE_SUBELEMENT = "listen_socket_buffer_size";
constexpr const char* NAME_SUBELEMENT = "name";
constexpr const char* SEND_SOCKET_BUFFER_SIZE_SUBELEMENT = "send_socket_buffer_size";
constexpr const char* USE_BUILTIN_TRANSPORTS_SUBELEMENT = "use_builtin_transports";
constexpr const char* USER_DATA_SUBELEMENT = "user_data";
constexpr const char* USER_TRANSPORTS_SUBELEMENT = "user_transports";

// CLI participant builtin subelements
constexpr const char* AVOID_BUILTIN_MULTICAST_SUBELEMENT = "avoid_builtin_multicast";
constexpr const char* DISCOVERY_CONFIG_SUBELEMENT = "discovery_config";
constexpr const char* MUTATION_TRIES_SUBELEMENT = "mutation_tries";
constexpr const char* READER_SUBELEMENT = "reader";
constexpr const char* USE_WRITER_LIVELINESS_PROTOCOL_SUBELEMENT = "use_writer_liveliness_protocol";
constexpr const char* WRITER_SUBELEMENT = "writer";

// CLI participant builtin discovery config subelements
constexpr const char* CLIENT_ANNOUNCEMENTS_SUBELEMENT = "client_announcements";
constexpr const char* DISCOVERY_PROTOCOL_SUBELEMENT = "discovery_protocol";
constexpr const char* EDP_SUBELEMENT = "edp";
constexpr const char* IGNORE_PARTICIPANT_FLAGS_SUBELEMENT = "ignore_participant_flags";
constexpr const char* INITIAL_ANNOUNCEMENTS_SUBELEMENT = "initial_announcements";
constexpr const char* REMOTE_SERVERS_SUBELEMENT = "remote_servers";
constexpr const char* SIMPLE_EDP_SUBELEMENT = "simple_edp";
constexpr const char* STATIC_EDP_XMLS_SUBELEMENT = "static_edp_xmls";

// CLI locators common elements
constexpr const char* DEFAULT_UNICAST_ELEMENT = "default_unicast";
constexpr const char* METATRAFFIC_UNICAST_ELEMENT = "metatraffic_unicast";
constexpr const char* UNICAST_ELEMENT = "unicast";

// CLI participant builtin specific locator lists
constexpr const char* INITIAL_PEERS_ELEMENT = "initial_peers";
constexpr const char* METATRAFFIC_MULTICAST_ELEMENT = "metatraffic_multicast";

// CLI locators common subelements
constexpr const char* ADDRESS_SUBELEMENT = "address";

// CLI specific locator subelements
constexpr const char* PHYSICAL_PORT_SUBELEMENT = "physical_port";
constexpr const char* UNIQUE_LAN_ID_SUBELEMENT = "unique_lan_id";
constexpr const char* WAN_ADDRESS_SUBELEMENT = "wan_address";

// CLI external locators specific subelements
constexpr const char* COST_SUBELEMENT = "cost";
constexpr const char* EXTERNALITY_SUBELEMENT = "externality";
constexpr const char* MASK_SUBELEMENT = "mask";

} // eprosima
} // qosprof_cli

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_PARSER_CONSTANTS_HPP_
