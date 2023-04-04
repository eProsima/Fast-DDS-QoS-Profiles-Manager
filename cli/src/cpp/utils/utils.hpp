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

#include <parser_constants.hpp>

namespace eprosima {
namespace qosprof_cli {

// Supported common commands
enum CommonCommands
{
    CLEAR,
    PRINT,
    QUERY,
    SET
};

// External locator lists
enum class ExternalLocatorsList
{
    PARTICIPANT_DEFAULT_UNICAST,
    PARTICIPANT_METATRAFFIC_UNICAST,
    DATAWRITER_UNICAST,
    DATAREADER_UNICAST
};

constexpr const char* common_command_str[] = {
    "clear",
    "print",
    "query",
    "set"
};

// Regex patterns
const std::regex dot_pattern("[^\\.]+");
const std::regex bracket_pattern("\\[([^\\]]*)\\]");

/**********************************************************************************************************************/
/* PARSERS                                                                                                            */
/**********************************************************************************************************************/

/**
 * @brief Participant builtin parser.
 *
 * @param[in] command Command kind.
 * @param[in] filename File to be modified.
 * @param[in] profile_name Domain Participant profile name.
 * @param[in] element String with the dot-separated subelements.
 * @param[in] values Vector of strings with the values passed to CLI.
 */
void builtin_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values);

/**
 * @brief Common parser for external locators lists
 *
 * @param[in] list Identify the specific list which is being modified.
 * @param[in] command Command kind.
 * @param[in] filename File to be modified.
 * @param[in] profile_name DDS entity profile name.
 * @param[in] element String with the dot-separated subelements.
 * @param[in] values Vector of strings with the values passed to CLI.
 */
void external_locators_parser(
        ExternalLocatorsList list,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values);

/**
 * @brief Parser for the main element to be configured.
 *
 * @param[in] command Command kind.
 * @param[in] filename File to be modified.
 * @param[in] argc Number of arguments passed to the parser.
 * @param[in] argv Arguments to be parsed.
 */
void main_element_parser(
        CommonCommands command,
        const std::string& filename,
        int argc,
        char** argv);

/**
 * @brief Parser for the participant main subelements.
 *
 * @param[in] command Command kind.
 * @param[in] filename File to be modified.
 * @param[in] profile_name Participant profile name.
 * @param[in] element String with the dot-separated subelements.
 * @param[in] values Vector of strings with the values passed to CLI.
 */
void participant_subelement_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values);

/**********************************************************************************************************************/
/* AUXILIARY FUNCTIONS                                                                                                */
/**********************************************************************************************************************/

/**
 * @brief Check number of arguments.
 *
 * @param command Command kind in order to be shown in the log.
 * @param expected_arguments Number of expected arguments.
 * @param actual_argument_number Number of actual arguments parsed in CLI.
 * @param element specific element that expects the arguments.
 * @param exact Flag set if the expected arguments are enforced.
 * @return true if the check holds. False otherwise.
 */
bool check_command_arguments(
        const CommonCommands comand,
        uint32_t expected_arguments,
        uint32_t actual_argument_number,
        const std::string& element,
        bool exact);

/**
 * @brief Check if it is the last element.
 *
 * @param expected_final Flag to mark final expectations.
 * @param subelement Subelement to check if it is FINAL.
 * @param element Element being checked in order to be shown in the log.
 * @return true if check is successful. False otherwise.
 */
bool check_final_element(
        bool expected_final,
        const std::string& subelement,
        const std::string& element);

/**
 * @brief Check if the last argument is help.
 *
 * @param[in] values String vector with the arguments.
 * @return true if help (or its variants) is the last argument.
 */
inline bool check_help(
        const std::vector<std::string>& values)
{
    return !values.empty() && (values.back() == HELP_COMMAND || values.back() == HELP_SHORTHAND_FLAG ||
           values.back() == HELP_FLAG);
}

/**
 * @brief Check if subelement should be keyed [].
 *
 * @param expected_keyed Flag to set keyed expectations.
 * @param keyed Actual keyed value.
 * @param element Element being checked in order to be shown in the log.
 * @return true if check is successful.False otherwise .
 */
bool check_keyed(
        bool expected_keyed,
        bool keyed,
        const std::string& element);

/**
 * @brief Auxiliary function to extract the element, subelement and key for the next level.
 *
 * @param[in out] element String to be parsed. Return only the main element (until next dot).
 * @param[out] subelement String after main element.
 * @param[out] key Index or key if the element is keyed.
 *
 * @return true if a key was found. False otherwise.
 */
bool extract_element_subelement_key(
        std::string& element,
        std::string& subelement,
        std::string& key);

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_UTILS_UTILS_HPP_
