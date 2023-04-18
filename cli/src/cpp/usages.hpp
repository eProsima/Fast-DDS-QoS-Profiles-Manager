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

static const char DATAREADER_DEFAULT_PROFILE_USAGE[] =
        R"(DataReader default profile usage:

    Usage:
      fastddsqosprof <file> <command> datareader[<profile_name>].default_profile [(help | -h | --help)]

    Options:
      help -h --help                CLI DataReader default profile usage

    The allowed <command> options are:
      clear                         Erase DataReader default profile from XML file.
      print                         Print DataReader default profile.
      set                           Set DataReader profile as default in the XML file.

    SET command REQUIRES a <profile_name> element. It can be any string (whitespaces are supported if quoted).
)";

static const char DATAREADER_QOS_USAGE[] =
        R"(DataReader QoS usage:

    Usage:
      fastddsqosprof <file> <command> datareader[<profile_name>].qos.<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> datareader[<profile_name>].qos.<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> datareader[<profile_name>].qos (help | -h | --help)

    Options:
      help -h --help                    CLI DataReader QoS options

    The allowed <command> options are:
      clear                             Erase DataReader QoS configuration from XML file.
      print                             Print DataReader QoS configuration.
      set                               Write DataReader QoS configuration to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      datasharing                       Data-Sharing QoS Policy configuration.
      duration                          Duration-related QoS Policies configuration: Deadline, Latency budget and Lifespan.
      disable_positive_acks             Disable positive ACKs QoS Policy configuration.
      durability                        Durability QoS Policy configuration.
      group_data                        Group Data QoS Policy configuration.
      history                           History QoS Policy configuration.
      liveliness                        Liveliness QoS Policy configuration.
      ownership                         Ownership and Ownership Strength QoS Policy configuration.
      partitions                        Partition QoS Policy configuration.
      reliability                       Realibility QoS Policy configuration.
      resource_limits                   Resource Limits QoS Policy configuration.
      topic_data                        Topic Data QoS Policy configuration.
      user_data                         User Data QoS Policy configuration.
)";

static const char DATAREADER_USAGE[] =
        R"(DataReader usage:

    Usage:
      fastddsqosprof <file> <command> datareader[<profile_name>].<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> datareader[<profile_name>].<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> datareader[<profile_name>] (help | -h | --help)
      fastddsqosprof <file> <command> datareader (help | -h | --help)

    Options:
      help -h --help                    CLI DataReader options

    The allowed <command> options are:
      clear                             Erase DataReader configuration parameter from XML file.
      print                             Print DataReader XML configuration parameter.
      set                               Write DataReader configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      allocations                       DataReader allocations configuration.
      binary_property                   DataReader binary properties according to Property QoS Policy.
      default_profile                   DataReader default profile attribute.
      entity_id                         DataReader ID configuration.
      expect_inline_qos                 DataReader flag enabled if QoS are expected inline.
      external_locators                 DataReader external locators configuration.
      history_memory_policy             DataReader history memory policy configuration.
      ignore_non_matching_locators      DataReader ignore non matching locators flag.
      locators                          DataReader locators configuration.
      property                          DataReader properties according to Property QoS Policy.
      qos                               DataReader QoS configuration.
      times                             DataReader time related parameters configuration.
      user_defined_id                   DataReader user ID for Static EDP discovery mechanism.
)";

static const char DATAWRITER_DEFAULT_PROFILE_USAGE[] =
        R"(DataWriter default profile usage:

    Usage:
      fastddsqosprof <file> <command> datawriter[<profile_name>].default_profile [(help | -h | --help)]

    Options:
      help -h --help                CLI DataWriter default profile usage

    The allowed <command> options are:
      clear                         Erase DataWriter default profile from XML file.
      print                         Print DataWriter default profile.
      set                           Set DataWriter profile as default in the XML file.

    SET command REQUIRES a <profile_name> element. It can be any string (whitespaces are supported if quoted).
)";

static const char DATAWRITER_QOS_USAGE[] =
        R"(DataWriter QoS usage:

    Usage:
      fastddsqosprof <file> <command> datawriter[<profile_name>].qos.<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> datawriter[<profile_name>].qos.<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> datawriter[<profile_name>].qos (help | -h | --help)

    Options:
      help -h --help                    CLI DataWriter QoS options

    The allowed <command> options are:
      clear                             Erase DataWriter QoS configuration from XML file.
      print                             Print DataWriter QoS configuration.
      set                               Write DataWriter QoS configuration to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      datasharing                       Data-Sharing QoS Policy configuration.
      duration                          Duration-related QoS Policies configuration: Deadline, Latency budget and Lifespan.
      disable_heartbeat_piggyback       Disable Heartbeat Piggyback QoS Policy configuration.
      disable_positive_acks             Disable positive ACKs QoS Policy configuration.
      durability                        Durability QoS Policy configuration.
      group_data                        Group Data QoS Policy configuration.
      history                           History QoS Policy configuration.
      liveliness                        Liveliness QoS Policy configuration.
      ownership                         Ownership and Ownership Strength QoS Policy configuration.
      partitions                        Partition QoS Policy configuration.
      publish_mode                      Publish Mode QoS Policy configuration.
      reliability                       Realibility QoS Policy configuration.
      resource_limits                   Resource Limits QoS Policy configuration.
      topic_data                        Topic Data QoS Policy configuration.
      user_data                         User Data QoS Policy configuration.
)";

static const char DATAWRITER_USAGE[] =
        R"(DataWriter usage:

    Usage:
      fastddsqosprof <file> <command> datawriter[<profile_name>].<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> datawriter[<profile_name>].<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> datawriter[<profile_name>] (help | -h | --help)
      fastddsqosprof <file> <command> datawriter (help | -h | --help)

    Options:
      help -h --help                    CLI DataWriter options

    The allowed <command> options are:
      clear                             Erase DataWriter configuration parameter from XML file.
      print                             Print DataWriter XML configuration parameter.
      set                               Write DataWriter configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      allocations                       DataWriter allocations configuration.
      binary_property                   DataWriter binary properties according to Property QoS Policy.
      default_profile                   DataWriter default profile attribute.
      entity_id                         DataWriter ID configuration.
      external_locators                 DataWriter external locators configuration.
      history_memory_policy             DataWriter history memory policy configuration.
      ignore_non_matching_locators      DataWriter ignore non matching locators flag.
      locators                          DataWriter locators configuration.
      property                          DataWriter properties according to Property QoS Policy.
      qos                               DataWriter QoS configuration.
      times                             DataWriter time related parameters configuration.
      user_defined_id                   DataWriter user ID for Static EDP discovery mechanism.
)";

static const char DURABILITY_QOS_USAGE[] =
        R"(DataReader/DataWriter Durability QoS Policy usage:

    Usage:
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.durability [<durability_kind> (help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.durability (help | -h | --help)

    Options:
      help -h --help              CLI DataReader/DataWriter Durability QoS Policy usage

    The allowed <command> options are:
      clear                       Erase Durability QoS Policy from XML file.
      print                       Print Durability QoS Policy.
      set                         Set Durability QoS Policy in the XML file.

    The allowed <endpoint> options are:
      datareader                  DataReader Durability QoS Policy.
      datawriter                  DataWriter Durability QoS Policy.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    SET command REQUIRES a <durability_kind> value. The accepted values are:
      volatile
      transient_local
      transient
      persistent
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

static const char PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE[] =
        R"(Participant lease duration and announcement period configuration:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.duration.<duration_type> [<infinite | seconds_value> (<nanoseconds_value>) (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.duration.<duration_type>.<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.duration.<duration_type>.<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.duration.<duration_type> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.duration [(help | -h | --help)]

    Options:
      help -h --help    CLI participant lease duration and announcement period configuration usage

    The allowed <command> options are:
      clear             Erase participant lease duration or announcement period from XML file.
      print             Print participant lease duration or announcement period configuration.
      set               Write participant lease duration or announcement period configuration to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <duration_type> options are:
      announcements     Configure participant lease announcement period.
      lease             Configure participant lease duration.

    The allowed <subelement> options are:
      sec               Duration seconds. Valid set values: int32_t.
      nanosec           Duration nanoseconds. Valid set values: uint32_t.
)";

static const char PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_USAGE[] =
        R"(Participant builtin discovery configuration usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config.<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.discovery_config [(help | -h | --help)]

    Options:
      help -h --help    CLI participant builtin discovery configuration usage

    The allowed <command> options are:
      clear                           Erase participant builtin discovery configuration from XML file.
      print                           Print participant builtin discovery configuration.
      set                             Write participant builtin discovery configuration to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> options are:
      client_announcements            Participant client announcement period configuration (Discovery Server specific).
      discovery_protocol              Participant discovery protocol configuration.
      duration                        Participant lease duration and announcement period configuration.
      edp                             Participant Endpoint Discovery Phase (EDP) configuration.
      ignore_participant_flags        Participant discovery metatraffic configuration.
      initial_announcements           Participant initial announcements configuration.
      remote_servers                  Participant remote servers list (Discovery Server specific).
      simple_edp                      Participant simple Endpoint Discovery Phase (EDP) configuration (Standard EDP specific).
      static_edp_xmls                 Participant static Endpoint Discovery Phase (EDP) configuration (Static EDP specific).
)";

static const char PARTICIPANT_BUILTIN_LOCATORS_USAGE[] =
        R"(Participant builtin locators usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)] [<kind_value> <address_value> <port_value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)].<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)].<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators.<locator_list>[(<index>)] [(help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.locators [(help | -h | --help)]

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
      No <index> with a SET command pushes a new element into the list.
      No <index> with a PRINT command prints every element in the list. Printing any subelement requires setting an <index>.
      No <index> with a CLEAR command clears every element in the list. Clearing any subelement requires setting an <index>.
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
      fastddsqosprof <file> <command> participant[<profile_name>].builtin.external_locators [(help | -h | --help)]

    Options:
      help -h --help    CLI participant builtin metatraffic external unicast locators usage

    The allowed <command> options are:
      clear             Erase participant builtin metatraffic external unicast locator configuration parameter from XML file.
      print             Print participant builtin metatraffic external unicast locator XML configuration parameter.
      set               Write participant builtin metatraffic external unicast locator configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> with a SET command pushes a new element into the list.
      No <index> with a PRINT command prints every element in the list. Printing any subelement requires setting an <index>.
      No <index> with a CLEAR command clears every element in the list. Clearing any subelement requires setting an <index>.
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
      fastddsqosprof <file> <command> participant[<profile_name>].external_locators [(help | -h | --help)]

    Options:
      help -h --help    CLI participant default external unicast locators usage

    The allowed <command> options are:
      clear             Erase participant default external unicast locator configuration parameter from XML file.
      print             Print participant default external unicast locator XML configuration parameter.
      set               Write participant default external unicast locator configuration parameter to XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> with a SET command pushes a new element into the list.
      No <index> with a PRINT command prints every element in the list. Printing any subelement requires setting an <index>.
      No <index> with a CLEAR command clears every element in the list. Clearing any subelement requires setting an <index>.
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
      fastddsqosprof <file> <command> participant[(<profile_name>)].default_profile [(help | -h | --help)]

    Options:
      help -h --help                CLI participant default profile usage

    The allowed <command> options are:
      clear                         Erase participant default profile from XML file.
      print                         Print participant default profile.
      set                           Set participant profile as default in the XML file.

    SET command REQUIRES a <profile_name> element. It can be any string (whitespaces are supported if quoted).
)";

static const char PARTICIPANT_NAME_USAGE[] =
        R"(Participant name usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].name [<participant_name> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].name (help | -h | --help)

    Options:
      help -h --help              CLI Participant name usage

    The allowed <command> options are:
      clear                       Erase participant name from XML file.
      print                       Print participant name.
      set                         Set participant name in the XML file.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    SET command REQUIRES a <participant_name> value. It can be any string (whitespaces are supported if quoted).
)";

static const char PARTICIPANT_USAGE[] =
        R"(Participant usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> participant[<profile_name>] (help | -h | --help)
      fastddsqosprof <file> <command> participant (help | -h | --help)

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
      default_profile               Participant default profile attribute.
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

static const char PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE[] =
        R"(Participant use_builtin_transports usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].use_builtin_transports [true | false (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].use_builtin_transports (help | -h | --help)

    Options:
      help -h --help                CLI participant use builtin transports flag usage

    The allowed <command> options are:
      clear                         Erase participant use builtin transports flag from XML file.
      print                         Print participant use builtin transports flag.
      set                           Set participant use builtin transports flag in the XML file.
                                    Valid values: true, builtin transports enabled.
                                                  false, builtin transports disabled.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).
)";

static const char PARTICIPANT_USER_TRANSPORTS_USAGE[] =
        R"(Participant user transports usage:

    Usage:
      fastddsqosprof <file> <command> participant[<profile_name>].user_transports[(<index>)] [<transport_id> (help | -h | --help)]
      fastddsqosprof <file> <command> participant[<profile_name>].user_transports[(<index>)] (help | -h | --help)

    Options:
      help -h --help    CLI participant user transports usage

    The allowed <command> options are:
      clear             Erase user transport from the participant list.
      print             Print user transport in the participant list.
      set               Add or update user transport in the participant list.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> with a SET command pushes a new element into the list.
      No <index> with a PRINT command prints every element in the list. Printing any subelement requires setting an <index>.
      No <index> with a CLEAR command clears every element in the list. Clearing any subelement requires setting an <index>.
      Positive <index> accesses the element in that position starting from the first element in the list.
      Negative <index> accesses the element in that position starting from the last element in the list.

    SET command REQUIRES a <transport_id> element which should be any Transport Descriptor profile defined in the XML configuration file.
)";

static const char RELIABILITY_DURATION_QOS_USAGE[] =
        R"(DataReader/DataWriter Reliability QoS Policy maximum blocking time usage:

    Usage:
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.duration.max_blocking_time [infinite | <seconds_value> (<nanoseconds_value>) (help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.duration.max_blocking_time.<subelement> [<value> (help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.duration.max_blocking_time.<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.duration.max_blocking_time [(help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.duration [(help | -h | --help)]

    Options:
      help -h --help              CLI DataReader/DataWriter Reliability QoS Policy maximum blocking time usage

    The allowed <command> options are:
      clear                       Erase Reliability QoS Policy maximum blocking time from XML file.
      print                       Print Reliability QoS Policy maximum blocking time.
      set                         Set Reliability QoS Policy maximum blocking time in the XML file.

    The allowed <endpoint> options are:
      datareader                  DataReader Reliability QoS Policy maximum blocking time.
      datawriter                  DataWriter Reliability QoS Policy maximum blocking time.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> options are:
      sec               Duration seconds. Valid set values: int32_t.
      nanosec           Duration nanoseconds. Valid set values: uint32_t.
)";

static const char RELIABILITY_KIND_QOS_USAGE[] =
        R"(DataReader/DataWriter Reliability QoS Policy kind usage:

    Usage:
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.kind [<reliability_kind (help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.kind (help | -h | --help)

    Options:
      help -h --help              CLI DataReader/DataWriter Reliability QoS Policy kind usage

    The allowed <command> options are:
      clear                       Erase Reliability QoS Policy kind from XML file.
      print                       Print Reliability QoS Policy kind.
      set                         Set Reliability QoS Policy kind in the XML file.

    The allowed <endpoint> options are:
      datareader                  DataReader Reliability QoS Policy kind.
      datawriter                  DataWriter Reliability QoS Policy kind.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    SET command REQUIRES a <reliability_kind> value. The accepted values are:
      best_effort
      reliable
)";

static const char RELIABILITY_QOS_USAGE[] =
        R"(DataReader/DataWriter Reliability QoS Policy usage:

    Usage:
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability.<subelement> [(help | -h | --help)]
      fastddsqosprof <file> <command> <endpoint>[<profile_name>].qos.reliability [(help | -h | --help)]

    Options:
      help -h --help              CLI DataReader/DataWriter Reliability QoS Policy usage

    The allowed <command> options are:
      clear                       Erase Reliability QoS Policy from XML file.
      print                       Print Reliability QoS Policy.
      set                         Set Reliability QoS Policy in the XML file.

    The allowed <endpoint> options are:
      datareader                  DataReader Reliability QoS Policy.
      datawriter                  DataWriter Reliability QoS Policy.

    The <profile_name> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> options are:
      kind                        Reliability QoS Policy kind configuration.
      duration                    Reliability QoS Policy maximum blocking time configuration.
)";

static const char TRANSPORT_KIND_USAGE[] =
        R"(Transport descriptor kind usage:
    Usage:
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].kind [<transport_kind> (help | -h | --help)]
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].kind (help | -h | --help)

    Options:
      help -h --help              CLI transport descriptor kind usage

    The allowed <command> options are:
      clear                       Erase transport descriptor kind from XML file.
      print                       Print transport descriptor kind.
      set                         Set transport descriptor kind in the XML file.

    The <transport_id> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    SET command REQUIRES a <transport_kind> value. The accepted values are:
      udp_v4
      udp_v6
      tcp_v4
      tcp_v6
      shm
)";

static const char TRANSPORT_USAGE[] =
        R"(Transport descriptor usage:

    Usage:
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].<subelement> [<values>... (help | -h | --help)]
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].<subelement> (help | -h | --help)
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>] (help | -h | --help)
      fastddsqosprof <file> <command> transport_descriptor (help | -h | --help)

    Options:
      help -h --help                CLI transport descriptor options

    The allowed <command> options are:
      clear                         Erase transport descriptor configuration parameter from XML file.
      print                         Print transport descriptor configuration as XML parameter.
      set                           Write transport descriptor configuration parameter to XML file.

    The <transport_id> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The allowed <subelement> types are:
      calculate_crc                 Enable calculating Cyclic Redundancy Code for error control (only available for TCP transport kind)
      check_crc                     Enable checking Cyclic Redundancy Code for error control (only available for TCP transport kind)
      enable_tcp_nodelay            Enable the Nagle algorithm for sockets (only available for TCP transport kind)
      healthy_check_timeout_ms      Maximum time-out (in milliseconds) for checking if listener is alive (only available for shared memory transport kind)
      interface_whitelist           Transport interface whitelist (only available for UDP and TCP transport kind)
      keep_alive_frequency_ms       Frequency in milliseconds for sending RTCP keep-alive requests (only available for TCP transport kind)
      keep_alive_timeout_ms         Timeout in milliseconds between RTCP keep-alive requests (only available for TCP transport kind)
      kind                          Kind of transport descriptor.
      listening_port                Collection of local ports (only available for TCP transport kind)
      logical_port_increment        Increment between logical ports to try during RTCP negotiations (only available for TCP transport kind)
      logical_port_range            Maximum number of logical ports per request to try RTCP negotiations (only available for TCP transport kind)
      max_initial_peers_range       Maximum range of transport initial peers
      max_logical_port              Maximum number of logical ports to try RTCP negotiations (only available for TCP transport kind)
      max_message_size              Maximum size of transport messages
      non_blocking_send             Transport socket non blocking send mode configuration (only available for UDP transport kind)
      output_port                   Port used for output bound (only available for UDP transport kind)
      port_queue_capacity           Maximum number of messages per listener (only available for shared memory transport kind)
      receive_buffer_size           Transport receive buffer size.
      rtps_dump_file                Complete path to store debugging RTPS messages (only available for shared memory transport kind)
      segment_size                  Size (in bytes) of the shared-memory segment (only available for shared memory transport kind)
      send_buffer_size              Transport send buffer size.
      tls                           Transport Layer Security configuration (only available for TCP transport kind)
      ttl                           Transport Time To Live (only available for UDP transport kind)
      wan_address                   Public IPv4 wan address (only available for TCPv4 transport kind)
)";

static const char TRANSPORT_WHITELIST_INTERFACE_USAGE[] =
        R"(Transport descriptor whitelist interface usage:
    Usage:
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].interface_whitelist[(<index>)] [<address_value> (help | -h | --help)]
      fastddsqosprof <file> <command> transport_descriptor[<transport_id>].interface_whitelist[(<index>)] [(help | -h | --help)]

    Options:
      help -h --help    CLI transport descriptor interface whitelist usage

    The allowed <command> options are:
      clear             Erase transport descriptor interface whitelist configuration parameter from XML file.
      print             Print transport descriptor interface whitelist XML configuration parameter.
      set               Write transport descriptor interface whitelist configuration parameter to XML file.

    The <transport_id> element is MANDATORY and it can be any string (whitespaces are supported if quoted).

    The <index> element is OPTIONAL:
      No <index> with a SET command pushes a new element into the list.
      No <index> with a PRINT command prints every element in the list. Printing any subelement requires setting an <index>.
      No <index> with a CLEAR command clears every element in the list. Clearing any subelement requires setting an <index>.
      Positive <index> accesses the element in that position starting from the first element in the list.
      Negative <index> accesses the element in that position starting from the last element in the list.

    SET command REQUIRES a <address_value> element. The accepted values are IP format or DNS.
)";

static const char SET_SUBPARSER_USAGE[] =
        R"(Set command parser: fastddsqosprof <file> set

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
