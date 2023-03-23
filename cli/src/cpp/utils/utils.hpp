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

#ifndef _FASTDDS_QOS_PROFILES_MANAGER_CLI_UTILS_UTILS_HPP_
#define _FASTDDS_QOS_PROFILES_MANAGER_CLI_UTILS_UTILS_HPP_

#include <regex>
#include <string>
#include <vector>

namespace eprosima {
namespace qosprof_cli {

// Supported common commands
enum class CommonCommands
{
    CLEAR,
    PRINT,
    QUERY,
    SET
};

// Regex patterns
const std::regex dot_pattern("[^\\.]+");
const std::regex bracket_pattern("\\[([^\\]]*)\\]");

/**
 * @brief Parser for the main element to be configured.
 *
 * @param command Command kind.
 * @param filename File to be modified.
 * @param argc Number of arguments passed to the parser.
 * @param argv Arguments to be parsed.
 */
void main_element_parser(
        CommonCommands command,
        const std::string& filename,
        int argc,
        char** argv);

/**
 * @brief Parser for the participant main subelements.
 *
 * @param command Command kind.
 * @param filename File to be modified.
 * @param profile_name Participant profile name.
 * @param element String with the dot-separated subelements.
 * @param values Vector of strings with the values passed to CLI.
 */
void participant_subelement_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values);

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_UTILS_UTILS_HPP_
