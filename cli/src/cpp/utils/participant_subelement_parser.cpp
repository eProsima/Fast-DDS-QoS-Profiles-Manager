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

#include <fastdds_qos_profiles_manager/domain_participant/DomainParticipant.hpp>

#include <parser_constants.hpp>
#include <utils/utils.hpp>
#include <usages.hpp>

namespace eprosima {
namespace qosprof_cli {

void participant_subelement_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    std::string subelement;
    std::string key;
    extract_element_subelement_key(element, subelement, key);

    bool print_usage = false;
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
        // No values with exception to help
        if (!values.empty())
        {
            print_usage = true;
            if (values.back() != HELP_COMMAND &&
                values.back() != HELP_SHORTHAND_FLAG &&
                values.back() != HELP_FLAG)
            {
                std::cout << "ERROR: Participant default attribute configuration does not require any value"
                        << std::endl;
            }
        }
        // Final element
        else if (!subelement.empty())
        {
            std::cout << "ERROR: Participant default profile attribute is FINAL element" << std::endl;
            print_usage = true;
        }
        else
        {
            // Call library
            switch (command)
            {
                case CommonCommands::CLEAR:
                    // TODO: think if the CLI command should change with the new behavior -> participant.default_profile
                    qosprof::domain_participant::clear_default_profile(filename);
                    break;
                case CommonCommands::PRINT:
                    // TODO: think if the CLI command should change with the new behavior.
                    qosprof::domain_participant::print_default_profile(filename);
                    break;
                case CommonCommands::SET:
                    qosprof::domain_participant::set_default_profile(filename, profile_name);
                    break;
            }
        }

        if (print_usage)
        {
            std::cout << PARTICIPANT_DEFAULT_PROFILE_USAGE << std::endl;
        }
    }
    else if (element == EXTERNAL_LOCATORS_SUBELEMENT)
    {
        // Check help value
        if (!values.empty() && (values.back() == HELP_COMMAND || values.back() == HELP_SHORTHAND_FLAG ||
                values.back() == HELP_FLAG))
        {
            print_usage = true;
        }
        // Default external unicast locators require a subelement
        else if (subelement.empty())
        {
            print_usage = true;
            std::cout << "ERROR: subelement is required for external locators element" << std::endl;
        }
        // At least one value is required for SET command
        else if (values.empty() && CommonCommands::SET == command)
        {
            print_usage = true;
            std::cout << "ERROR: at least one value has to be passed to configure external locators" << std::endl;
        }
        else
        {
            external_locators_parser(ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST, command, filename, profile_name,
                    subelement, values);
        }

        if (print_usage)
        {
            if (CommonCommands::QUERY == command)
            {
                // TODO
                // std::cout << PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_QUERY_USAGE << std::endl;
            }
            else
            {
                std::cout << PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE << std::endl;
            }
        }
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
