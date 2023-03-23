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

#include <iostream>
#include <string>
#include <vector>

#include <parser_constants.hpp>
#include <utils/utils.hpp>
#include <usages.hpp>

namespace eprosima {
namespace qosprof_cli {

void participant_subelement_parser(
        CommonCommands command,
        const std::string& /*filename*/,
        const std::string& /*profile_name*/,
        std::string& element,
        const std::vector<std::string>& /*values*/)
{
    std::smatch match;
    std::regex_search(element, match, dot_pattern);
    element = match[0];
    std::string subelement = match.suffix();
    // Some subelement (property and binary_property) require a key
    std::string key;
    if (std::regex_search(element, match, bracket_pattern))
    {
        element = match.prefix();
        key = match[1];
    }

    if (element == ALLOCATIONS_SUBELEMENT)
    {
        std::cout << "Participant allocations configuration not yet supported" << std::endl;
    }
    else if (element == BINARY_PROPERTY_SUBELEMENT)
    {
        std::cout << "Participant binary properties configuration not yet supported" << std::endl;
    }
    else if (element == BUILTIN_SUBELEMENT)
    {
        std::cout << "Participant builtin configuration not yet supported" << std::endl;
    }
    else if (element == DEFAULT_PROFILE_SUBELEMENT)
    {
        std::cout << "Participant default profile configuration not yet supported" << std::endl;
    }
    else if (element == EXTERNAL_LOCATORS_SUBELEMENT)
    {
        std::cout << "Participant external locators configuration not yet supported" << std::endl;
    }
    else if (element == GUID_PREFIX_SUBELEMENT)
    {
        std::cout << "Participant GUID prefix configuration not yet supported" << std::endl;
    }
    else if (element == ID_SUBELEMENT)
    {
        std::cout << "Participant ID configuration not yet supported" << std::endl;
    }
    else if (element == IGNORE_NON_MATCHING_LOCATORS_SUBELEMENT)
    {
        std::cout << "Participant ignore non matching locators configuration flag not yet supported" << std::endl;
    }
    else if (element == LISTEN_SOCKET_BUFFER_SIZE_SUBELEMENT)
    {
        std::cout << "Participant listen socket buffer size configuration not yet supported" << std::endl;
    }
    else if (element == LOCATORS_SUBELEMENT)
    {
        std::cout << "Participant locators configuration not yet supported" << std::endl;
    }
    else if (element == NAME_SUBELEMENT)
    {
        std::cout << "Participant name configuration not yet supported" << std::endl;
    }
    else if (element == PORT_SUBELEMENT)
    {
        std::cout << "Participant port parameters configuration not yet supported" << std::endl;
    }
    else if (element == PROPERTY_SUBELEMENT)
    {
        std::cout << "Participant properties configuration not yet supported" << std::endl;
    }
    else if (element == SEND_SOCKET_BUFFER_SIZE_SUBELEMENT)
    {
        std::cout << "Participant send socket buffer size configuration not yet supported" << std::endl;
    }
    else if (element == USE_BUILTIN_TRANSPORTS_SUBELEMENT)
    {
        std::cout << "Participant use builtin transports flag configuration not yet supported" << std::endl;
    }
    else if (element == USER_TRANSPORTS_SUBELEMENT)
    {
        std::cout << "Participant user transports configuration not yet supported" << std::endl;
    }
    else
    {
        std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        if (CommonCommands::QUERY != command)
        {
            std::cout << PARTICIPANT_USAGE << std::endl;
        }
        else
        {
            // TODO
            // std::cout << PARTICIPANT_QUERY_USAGE << std::endl;
        }
    }
}

} // qosprof_cli
} // eprosima