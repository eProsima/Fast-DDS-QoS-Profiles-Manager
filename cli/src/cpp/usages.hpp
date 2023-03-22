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
      fastddsqosprof <file> <command> [<element>] help
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
      clear             Erase XML configuration parameter from file.
      compare           Compare between two XML configuration files.
      help              CLI specific options for the corresponding configuration parameter.
      print             Print XML configuration parameter.
      query             Query about XML parameter list size or keys.
      set               Write XML configuration parameter to file.
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
