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

#include <iostream>
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

// Duration elements
enum class DurationList
{
    DATAREADER_INITIAL_ACKNACK_DELAY,
    DATAREADER_HEARTBEAT_RESPONSE_DELAY,
    DATAREADER_QOS_DEADLINE_PERIOD,
    DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD,
    DATAREADER_QOS_LATENCY_BUDGET_PERIOD,
    DATAREADER_QOS_LIFESPAN_PERIOD,
    DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD,
    DATAREADER_QOS_LIVELINESS_LEASE_DURATION,
    DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME,
    DATAWRITER_INITIAL_HEARTBEAT_DELAY,
    DATAWRITER_HEARTBEAT_PERIOD,
    DATAWRITER_NACK_RESPONSE_DELAY,
    DATAWRITER_NACK_SUPRESSION,
    DATAWRITER_QOS_DEADLINE_PERIOD,
    DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD,
    DATAWRITER_QOS_LATENCY_BUDGET_PERIOD,
    DATAWRITER_QOS_LIFESPAN_PERIOD,
    DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD,
    DATAWRITER_QOS_LIVELINESS_LEASE_DURATION,
    DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME,
    PARTICIPANT_ANNOUNCEMENT_PERIOD,
    PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD,
    PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD,
    PARTICIPANT_LEASE_DURATION
};

// Locator lists
enum class LocatorsList
{
    DATAREADER_MULTICAST,
    DATAREADER_UNICAST,
    DATAWRITER_MULTICAST,
    DATAWRITER_UNICAST,
    PARTICIPANT_DEFAULT_MULTICAST,
    PARTICIPANT_DEFAULT_UNICAST,
    PARTICIPANT_INITIAL_PEERS,
    PARTICIPANT_METATRAFFIC_MULTICAST,
    PARTICIPANT_METATRAFFIC_UNICAST,
    PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST
};

// External locator lists
enum class ExternalLocatorsList
{
    DATAREADER_UNICAST,
    DATAWRITER_UNICAST,
    PARTICIPANT_DEFAULT_UNICAST,
    PARTICIPANT_METATRAFFIC_UNICAST
};

namespace locators {
enum LocatorArgumentPosition
{
    KIND,
    ADDRESS,
    PORT
};
} // locators

namespace external_locators {
enum ExternalLocatorArgumentPosition
{
    KIND,
    EXTERNALITY,
    ADDRESS,
    COST,
    MASK,
    PORT
};
} // external_locators

constexpr const int8_t DEFAULT_POSITION = 0;

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
 * @brief Participant builtin discovery config parser.
 *
 * @param[in] command Command kind.
 * @param[in] filename File to be modified.
 * @param[in] profile_name Domain Participant profile name.
 * @param[in] element String with the dot-separated subelements.
 * @param[in] values Vector of strings with the values passed to CLI.
 */
void builtin_discovery_config_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values);

/**
 * @brief Auxiliary participant builtin parser to parse the specific locator list.
 *
 * @param[out] locator_list Specific participant builtin locator list being accessed.
 * @param[in, out] element String with the dot-separated subelements.
 *                         Next subelement to be parsed is returned.
 * @param[out] subelement Next element to be parsed.
 * @param[out] key Index of the locator being modified.
 * @param[in] values Vector of strings with the values passed to CLI.
 * @param[out] message Error message in case of validity check failure.
 * @return true if valid locator list. False otherwise.
 */
bool builtin_locator_parser(
        LocatorsList& locator_list,
        std::string& element,
        std::string& subelement,
        std::string& key,
        const std::vector<std::string>& values,
        std::ostringstream& message);

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
 * @param[in] list Identify the specific list which is being accessed.
 * @param[in] command Command kind.
 * @param[in] filename File to be accessed.
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
 * @brief Common parser for locator lists
 *
 * @param[in] list Identify the specific list which is being accessed.
 * @param[in] command Command kind.
 * @param[in] filename File to be accessed.
 * @param[in] profile_name DDS entity profile name.
 * @param[in] element String with the dot-separated subelements.
 * @param[in] key Index of the locator to be accessed in the list.
 * @param[in] values Vector of strings with the values passed to CLI.
 * @param[in] message Error message in case of validity check failure.
 */
void locators_parser(
        LocatorsList list,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::string& key,
        const std::vector<std::string>& values,
        std::ostringstream& message);

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
 * @param[in] command Command kind in order to be shown in the log.
 * @param[in] expected_arguments Number of expected arguments.
 * @param[in] actual_argument_number Number of actual arguments parsed in CLI.
 * @param[in] element specific element that expects the arguments.
 * @param[in] exact Flag set if the expected arguments are enforced.
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
 * @param[in] expected_final Flag to mark final expectations.
 * @param[in] subelement Subelement to check if it is FINAL.
 * @param[in] element Element being checked in order to be shown in the log.
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
 * @brief Auxiliary method to output error when index must be empty.
 *
 * @param[in] index Index received in CLI.
 * @param[in] expected_empty Flag to set index expectations.
 * @return true if check is successful. False otherwise.
 */
bool check_index(
        const std::string& index,
        bool expected_empty);

/**
 * @brief Check if subelement should be keyed [].
 *
 * @param[in] expected_keyed Flag to set keyed expectations.
 * @param[in] keyed Actual keyed value.
 * @param[in] element Element being checked in order to be shown in the log.
 * @return true if check is successful.False otherwise .
 */
bool check_keyed(
        bool expected_keyed,
        bool keyed,
        const std::string& element);

/**
 * @brief Auxiliary method to enforce a profile name.
 *
 * @param[in] profile_name
 * @param[in] element Element being checked in order to be shown in the log.
 * @return true always.
 */
bool check_profile(
        const std::string& profile_name,
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

/**
 * @brief Auxiliary method to output error when query command is not allowed.
 *
 * @param[in] element Element being checked in order to be shown in the log.
 * @return true always.
 */
inline bool query_not_allowed(
        const std::string& element)
{
    std::cout << "ERROR: query command not allowed. " << element << " is not a collection" << std::endl;
    return true;
}

} // qosprof_cli
} // eprosima

#endif // _FASTDDS_QOS_PROFILES_MANAGER_CLI_UTILS_UTILS_HPP_
