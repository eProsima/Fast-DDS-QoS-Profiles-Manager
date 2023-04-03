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
#include <sstream>
#include <string>
#include <vector>

#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void builtin_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    bool print_usage = false;
    std::string subelement;
    std::string key;

    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message << "Participant builtin <" << element << ">";

    if (element == AVOID_BUILTIN_MULTICAST_SUBELEMENT)
    {
        std::cout << "Participant builtin avoid_builtin_multicast flag configuration not yet supported" << std::endl;
    }
    else if (element == DISCOVERY_CONFIG_SUBELEMENT)
    {
        std::cout << "Participant builtin dicovery mechanism configuration not yet supported" << std::endl;
    }
    else if (element == EXTERNAL_LOCATORS_SUBELEMENT)
    {
        // Check help value
        print_usage = check_help(values);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Default external unicast locators require a subelement
        print_usage = print_usage || !check_final_element(false, subelement, message.str());
        // At least one value is required for SET command
        print_usage = print_usage || (CommonCommands::SET == command && !check_command_arguments(command, 1,
                values.size(), message.str(), false));

        if (!print_usage)
        {
            external_locators_parser(ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST, command, filename,
                    profile_name, subelement, values);
        }
        else
        {
            if (CommonCommands::QUERY == command)
            {
                // TODO
                // std::cout << PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_QUERY_USAGE << std::endl;
            }
            else
            {
                std::cout << PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE << std::endl;
            }
        }
    }
    else if (element == MUTATION_TRIES_SUBELEMENT)
    {
        std::cout << "Participant builtin mutation tries configuration not yet supported" << std::endl;
    }
    else if (element == LOCATORS_SUBELEMENT)
    {
        std::cout << "Participant builtin locators configuration not yet supported" << std::endl;
    }
    else if (element == READER_SUBELEMENT)
    {
        std::cout << "Participant builtin readers configuration not yet supported" << std::endl;
    }
    else if (element == USE_WRITER_LIVELINESS_PROTOCOL_SUBELEMENT)
    {
        std::cout << "Participant builtin use writer liveliness protocol flag configuration not yet supported"
                  << std::endl;
    }
    else if (element == WRITER_SUBELEMENT)
    {
        std::cout << "Participant builtin writers configuration not yet supported" << std::endl;
    }
    else
    {
        // Check if the user has asked for help. Otherwise show error
        if (!check_help(values))
        {
            std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        }

        if (CommonCommands::QUERY != command)
        {
            std::cout << PARTICIPANT_BUILTIN_USAGE << std::endl;
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
