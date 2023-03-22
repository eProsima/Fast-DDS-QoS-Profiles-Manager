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

constexpr const char* PARSER_ARGS = "<args>";
constexpr const char* PARSER_ELEMENT = "<element>";
constexpr const char* PARSER_FILE = "<file>";
constexpr const char* PARSER_VALUES = "<values>";
constexpr const char* PARSER_VERB = "<verb>";

// CLI supported verbs
constexpr const char* CLEAR_VERB = "clear";
constexpr const char* COMPARE_VERB = "compare";
constexpr const char* HELP_VERB = "help";
constexpr const char* PRINT_VERB = "print";
constexpr const char* QUERY_VERB = "query";
constexpr const char* SET_VERB = "set";
constexpr const char* VALIDATE_VERB = "validate";

// CLI supported main elements
constexpr const char* DATAREADER_ELEMENT = "datareader";
constexpr const char* DATAWRITER_ELEMENT = "datawriter";
constexpr const char* INTRAPROCESS_ELEMENT = "intraprocess";
constexpr const char* LOG_ELEMENT = "log";
constexpr const char* PARTICIPANT_ELEMENT = "participant";
constexpr const char* TRANSPORT_ELEMENT = "transport_descriptor";
constexpr const char* TYPES_ELEMENT = "types";

} // eprosima
} // qosprof_cli

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_PARSER_CONSTANTS_HPP_
