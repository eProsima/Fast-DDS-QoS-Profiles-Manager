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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_ARGUMENT_CONSTANTS_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_ARGUMENT_CONSTANTS_HPP_

namespace eprosima {
namespace qosprof_cli {

// Duration type infinite
constexpr const char* CLI_INFINITE_ARGUMENT = "infinite";
constexpr const char* LIB_INFINITE_ARGUMENT = "DURATION_INFINITY";

// Durability QoS kind
constexpr const char* CLI_VOLATILE_ARGUMENT = "volatile";
constexpr const char* CLI_TRANSIENT_LOCAL_ARGUMENT  = "transient_local";
constexpr const char* CLI_TRANSIENT_ARGUMENT = "transient";
constexpr const char* CLI_PERSISTENT_ARGUMENT = "persistent";

constexpr const char* LIB_VOLATILE_ARGUMENT = "VOLATILE";
constexpr const char* LIB_TRANSIENT_LOCAL_ARGUMENT  = "TRANSIENT_LOCAL";
constexpr const char* LIB_TRANSIENT_ARGUMENT = "TRANSIENT";
constexpr const char* LIB_PERSISTENT_ARGUMENT = "PERSISTENT";

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_ARGUMENT_CONSTANTS_HPP_
