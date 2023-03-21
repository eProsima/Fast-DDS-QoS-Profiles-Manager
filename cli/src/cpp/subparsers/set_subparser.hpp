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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SET_SUBPARSER_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SET_SUBPARSER_HPP_

#include <string>

namespace eprosima {
namespace qosprof_cli {

void set_subparser(
        std::string file,
        int argc,
        char** argv);

} // eprosima
} // qosprof_cli

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_SUBPARSERS_SET_SUBPARSER_HPP_
