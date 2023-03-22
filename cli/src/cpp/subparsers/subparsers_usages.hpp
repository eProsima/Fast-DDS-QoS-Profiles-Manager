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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SUBPARSERS_USAGES_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SUBPARSERS_USAGES_HPP_

namespace eprosima {
namespace qosprof_cli {

static const char SET_SUBPARSER_USAGE[] =
        R"(Set subparser: fastddsqosprof <file> set

    Usage:
      set <element> [<values>...]
      set (-h | --help)

    Options:
      -h --help                 CLI set subparser options.

    The allowed <element> types are:
      datawriter                Configure DataWriter profile.
      datareader                Configure DataReader profile.
      help                      Available configuration options for the set command.
      intraprocess              Configure intra-process delivery.
      log                       Configure log module.
      participant               Configure DomainParticipant profile.
      transport_descriptor      Configure transport descriptor profile.
      types                     Configure dynamic types.
)";

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SUBPARSERS_USAGES_HPP_
