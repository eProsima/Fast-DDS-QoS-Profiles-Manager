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

#include <utils/utils.hpp>

#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace eprosima {
namespace qosprof_cli {

bool check_command_arguments(
        const CommonCommands command,
        uint32_t expected_arguments,
        uint32_t actual_argument_number,
        const std::string& element,
        bool exact)
{
    if (exact ? (actual_argument_number != expected_arguments) : (actual_argument_number < expected_arguments))
    {
        std::cout << "ERROR: " << common_command_str[command] << " command for " << element
                  << " expects " << (exact ? "" : "at least ") << expected_arguments << " arguments and received "
                  << actual_argument_number << std::endl;
        return false;
    }
    return true;
}

bool check_final_element(
        bool expected_final,
        const std::string& subelement,
        const std::string& element)
{
    if (expected_final != subelement.empty())
    {
        std::ostringstream message;
        message << "ERROR: " << element << " must " << (expected_final ? "" : "not ") << "be FINAL element";
        std::cout << message.str() << std::endl;
        return false;
    }
    return true;
}

bool check_index(
        const std::string& index,
        bool expected_empty)
{
    if (expected_empty != index.empty())
    {
        std::cout << "ERROR: <index> must " << (expected_empty ? "" : "not ") << "be empty." <<
            (expected_empty ? "" : "Index read: ") << index << std::endl;
        return false;
    }
    return true;
}

bool check_keyed(
        bool expected_keyed,
        bool keyed,
        const std::string& element)
{
    if (expected_keyed != keyed)
    {
        std::ostringstream message;
        message << "ERROR: " << element << " must " << (expected_keyed ? "" : "not ") << "be keyed []";
        std::cout << message.str() << std::endl;
        return false;
    }
    return true;
}

bool check_profile(
        const std::string& profile_name,
        const std::string& element)
{
    if (profile_name.empty())
    {
        std::cout << "ERROR: " << element << " requires a profile name" << std::endl;
        return false;
    }
    return true;
}

bool extract_element_subelement_key(
        std::string& element,
        std::string& subelement,
        std::string& key)
{
    std::smatch match;
    std::regex_search(element, match, dot_pattern);
    subelement = match.suffix();
    element = match[0];
    if (std::regex_search(element, match, bracket_pattern))
    {
        element = match.prefix();
        key = match[1];
        return true;
    }
    return false;
}

} // qosprof_cli
} // eprosima
