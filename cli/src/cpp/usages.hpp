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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_USAGES_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_USAGES_HPP_

namespace eprosima {
namespace qosprof_cli {

static const char CLEAR_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI clear command usage

    Usage:
      fastddsqosprof <file> clear <element>
)";

static const char COMPARE_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI compare command usage

    Usage:
      fastddsqosprof <file_1> compare <file_2>
)";

static const char HELP_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI help command usage

    Usage:
      fastddsqosprof <file> help
      fastddsqosprof <file> <command> [<element>] [<values>] (help | -h | --help)
)";

static const char PRINT_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI print command usage

    Usage:
      fastddsqosprof <file> print [<element>]
)";

static const char QUERY_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI query command usage

    Usage:
      fastddsqosprof <file> query [size | keys] <element>
)";

static const char PARTICIPANT_BUILTIN_LOCATORS_USAGE[] =
        R"(Participant builtin locators usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)] [<kind_value> <address_value> <port_value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)].<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)].<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)] [(help | -h | --help)]

    Options:
      help -h --help    CLI participant builtin locators usage

    The allowed <command> options are:
      clear                     Erase participant builtin locator <subelement> list from XML file.
      print                     Print participant builtin locator <subelement> list.
      set                       Write participant builtin locator <subelement> list configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <locator_list> options are:
      metatraffic_unicast       Configure builtin metatraffic unicast locator list.
      metatraffic_multicast     Configure builtin metatraffic multicast locator list.
      initial_peers             Configure builtin initial peers locator list.

    The <index> element is OPTIONAL:
      No <index> pushes a new element into the list.
      Positive <index> accesses the element in that position starting from the first element in the list.
      Negative <index> accesses the element in that position starting from the last element in the list.

    The allowed <subelement> options are:
      address           Locator address. Valid set values: IP format or DNS.
      kind              Locator kind. Valid set values: udp_v4 | udp_v6 | tcp_v4 | tcp_v6 (Default: udp_v4)
                        kind is a mandatory parameter. Consequently, this parameter cannot be cleared. Erase the entire locator or update the kind.
      physical_port     Locator physical port (TCP). Valid set values: [0, 65535]
      port              Locator port. Valid set values: [0, 65535]
      unique_lan_id     Locator unique LAN ID (TCP v4). Valid set values: 8 dot-separated bytes.
      wan_address       Locator WAN address (TCP v4). Valid set values: IP v4 format.
)";

static const char PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE[] =
        R"(Participant builtin metatraffic external unicast locators usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.external_locators.metatraffic_unicast[(<index>)] [<kind_value> <externality_value> <cost_value> <address_value> <mask_value> <port_value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.external_locators.metatraffic_unicast[(<index>)].<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.external_locators.metatraffic_unicast[(<index>)].<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.external_locators.metatraffic_unicast[(<index>)] [(help | -h | --help)]

    Options:
      help -h --help    CLI participant builtin metatraffic external unicast locators usage

    The allowed <command> options are:
      clear             Erase participant builtin metatraffic external unicast locator configuration parameter from XML file.
      print             Print participant builtin metatraffic external unicast locator XML configuration parameter.
      set               Write participant builtin metatraffic external unicast locator configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> pushes a new element into the list.
      Positive <index> accesses the element in that position starting from the first element in the list.
      Negative <index> accesses the element in that position starting from the last element in the list.

    The allowed <subelement> options are:
      address           Builtin metatraffic external unicast locator address. Valid set values: IP format or DNS.
      cost              Builtin metatraffic external unicast locator cost. Valid set values: [0, 255]
      externality       Builtin metatraffic external unicast locator externality index. Valid set values: [1, 255]
      kind              Builtin metatraffic external unicast locator kind. Valid set values: udp_v4 | udp_v6 (Default: udp_v4)
                        kind is a mandatory parameter. Consequently, this parameter cannot be cleared. Erase the entire locator or update the kind.
      mask              Builtin metatraffic external unicast locator mask. Valid set values: udp_v4 [1, 31] | udp_v6 [1, 127]
      port              Builtin metatraffic external unicast locator port. Valid set values: [0, 65535]
)";

static const char PARTICIPANT_BUILTIN_USAGE[] =
        R"(Participant builtin configuration usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin [(help | -h | --help)]

    Options:
      help -h --help    CLI participant builtin configuration usage

    The allowed <command> options are:
      clear                           Erase participant builtin configuration parameter from XML file.
      print                           Print participant builtin XML configuration parameter.
      set                             Write participant builtin configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> options are:
      avoid_builtin_multicast         Participant builtin avoid_builtin_multicast flag configuration. Valid set values: [true | false]
      discovery_config                Participant builtin discovery mechanism configuration.
      external_locators               Participant builtin external locators configuration.
      mutation_tries                  Participant builtin mutation tries configuration. Valid set values: [0, 65535]
      locators                        Participant builtin locators configuration.
      reader                          Participant builtin readers configuration.
      use_writer_liveliness_protocol  Participant builtin use_writer_liveliness_protocol flag configuration. Valid set values: [true | false]
      writer                          Participant builtin writers configuration.
)";

static const char PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE[] =
        R"(Participant default external unicast locators usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].external_locators.default_unicast[(<index>)] [<kind_value> <externality_value> <cost_value> <address_value> <mask_value> <port_value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].external_locators.default_unicast[(<index>)].<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].external_locators.default_unicast[(<index>)].<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].external_locators.default_unicast[(<index>)] [(help | -h | --help)]

    Options:
      help -h --help    CLI participant default external unicast locators usage

    The allowed <command> options are:
      clear             Erase participant default external unicast locator configuration parameter from XML file.
      print             Print participant default external unicast locator XML configuration parameter.
      set               Write participant default external unicast locator configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> pushes a new element into the list.
      Positive <index> accesses the element in that position starting from the first element in the list.
      Negative <index> accesses the element in that position starting from the last element in the list.

    The allowed <subelement> options are:
      address           Default external unicast locator address. Valid set values: IP format or DNS.
      cost              Default external unicast locator cost. Valid set values: [0, 255]
      externality       Default external unicast locator externality index. Valid set values: [1, 255]
      kind              Default external unicast locator kind. Valid set values: udp_v4 | udp_v6 (Default: udp_v4)
                        kind is a mandatory parameter. Consequently, this parameter cannot be cleared. Erase the entire locator or update the kind.
      mask              Default external unicast locator mask. Valid set values: udp_v4 [1, 31] | udp_v6 [1, 127]
      port              Default external unicast locator port. Valid set values: [0, 65535]
)";

static const char PARTICIPANT_DEFAULT_PROFILE_USAGE[] =
        R"(Participant default profile usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].default_profile [(help | -h | --help)]

    Options:
      help -h --help                CLI participant default profile usage

    The allowed <command> options are:
      clear                         Erase participant default profile from XML file.
      print                         Print participant default profile.
      set                           Set participant profile as default in the XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).
)";

static const char PARTICIPANT_NAME_USAGE[] =
        R"(Participant name parser:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].name <participant_name> (help | -h | --help)
      fastddsqosprof <file> <command> participant[<profile_name>].name (help | -h | --help)

    Options:
      help -h --help              CLI Participant name usage

    The allowed <command> options are:
      clear                       Erase participant name from XML file.
      print                       Print participant name.
      set                         Set participant name in the XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <participant_name> value is MANDATORY and it can be any string (whitespaces are supported if quoted).
)";

static const char PARTICIPANT_USAGE[] =
        R"(Participant parser:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].<subelement> [<values>...]
      fastddsqosprof <file> <command> participant[<profile_name>] (help | -h | --help)
      fastddsqosprof <file> <command> participant[<profile_name>].<subelement> (help | -h | --help)

    Options:
      help -h --help                CLI participant options

    The allowed <command> options are:
      clear                         Erase participant configuration parameter from XML file.
      print                         Print participant XML configuration parameter.
      set                           Write participant configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      allocations                   Participant allocations configuration.
      binary_property               Participant binary properties according to Property QoS Policy.
      builtin                       Participant builtin configuration.
      default_profile               Default profile attribute.
      domain_id                     Participant DDS Domain ID.
      external_locators             Participant external locators.
      guid_prefix                   Participant GUID prefix (unique identifier).
      id                            Participant ID.
      ignore_non_matching_locators  Participant ignore non matching locators flag.
      listen_socket_buffer_size     Participant listen socket buffer size.
      locators                      Participant locators.
      name                          Participant name.
      port                          Participant port parameters configuration.
      property                      Participant properties according to Property QoS Policy.
      send_socket_buffer_size       Participant send socket buffer size.
      use_builtin_transports        Participant use builtin transports flag.
      user_data                     Participant User Data QoS configuration.
      user_transports               Participant custom user-defined transports.
)";

static const char SET_SUBPARSER_USAGE[] =
        R"(Set subparser: fastddsqosprof <file> set

    Usage:
      set <element> [<values>...]
      set (-h | --help)

    Options:
      -h --help                 CLI set subparser options.

    The allowed <element> types are:
      datareader                Configure DataReader profile.
      datawriter                Configure DataWriter profile.
      help                      Available configuration options for the set command.
      intraprocess              Configure intra-process delivery.
      log                       Configure log module.
      participant               Configure DomainParticipant profile.
      topic                     Configure Topic profile.
      transport_descriptor      Configure transport descriptor profile.
      types                     Configure dynamic types.
)";

static const char SET_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI set command usage

    Usage:
      fastddsqosprof <file> set <element> [<value>]
)";

static const char USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI

    Usage:
      fastddsqosprof <file> <command> [<args>...]
      fastddsqosprof (-v | --version | -h | --help)

    Options:
      -v --version      CLI version.
      -h --help         CLI general options.

    The allowed <command> options are:
      clear             Erase configuration parameter from XML file.
      compare           Compare between two XML configuration files.
      help              CLI specific options for the corresponding configuration parameter.
      print             Print XML configuration parameter.
      query             Query about XML parameter list size or keys.
      set               Write configuration parameter to XML file.
      validate          Validate XML configuration file against Fast DDS XSD schema.
)";

static const char VALIDATE_USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI validate command usage

    Usage:
      fastddsqosprof <file> validate        
)";

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_USAGES_HPP_
