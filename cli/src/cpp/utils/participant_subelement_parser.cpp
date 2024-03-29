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

#include <fastdds_qos_profiles_manager_lib/domain_participant/DomainParticipant.hpp>
#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <parser_constants.hpp>
#include <utils/utils.hpp>
#include <usages.hpp>

namespace eprosima {
namespace qosprof_cli {

void participant_subelement_parser(
        CommonCommands command,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    std::string subelement;
    std::string key;
    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message << "Participant <" << element << ">";

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
        // If there is no subelement and the last value is (help | -h | --help), print usage
        print_usage = subelement.empty() && check_help(values);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Builtin element require a subelement
        print_usage = print_usage || !check_final_element(false, subelement, message.str());

        if (!print_usage)
        {
            builtin_parser(command, profile_name, subelement, values);
        }
        else
        {
            if (CommonCommands::QUERY == command)
            {
                // TODO
                // std::cout << PARTICIPANT_BUILTIN_QUERY_USAGE << std::endl;
            }
            else
            {
                std::cout << PARTICIPANT_BUILTIN_USAGE << std::endl;
            }
        }
    }
    else if (element == DEFAULT_PROFILE_SUBELEMENT)
    {
        print_usage = check_help(values);
        // No values are allowed (only if help is the last which has already been checked)
        print_usage = print_usage || !check_command_arguments(command, 0, values.size(), message.str(), true);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Final element
        print_usage = print_usage || !check_final_element(true, subelement, message.str());

        if (!print_usage)
        {
            try
            {
                // Call library
                switch (command)
                {
                    case CommonCommands::CLEAR:
                        // TODO: think if the CLI command should change with the new behavior -> participant.default_profile
                        qosprof::domain_participant::clear_default_profile();
                        break;
                    case CommonCommands::PRINT:
                        // TODO: think if the CLI command should change with the new behavior.
                        qosprof::domain_participant::print_default_profile();
                        break;
                    case CommonCommands::SET:
                        qosprof::domain_participant::set_default_profile(profile_name);
                        break;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cout << ENTITY_DEFAULT_PROFILE_USAGE << std::endl;
        }
    }
    else if (element == DOMAIN_ID_SUBELEMENT)
    {
        std::cout << "Participant domain ID configuration not yet supported" << std::endl;
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
            external_locators_parser(ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST, command, profile_name,
                    subelement, values);
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
        // Check help value
        print_usage = check_help(values);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Final element
        print_usage = print_usage || !check_final_element(true, subelement, message.str());

        if (!print_usage)
        {
            try
            {
                switch (command)
                {
                    case CommonCommands::CLEAR:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::clear_name(profile_name);
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::print_name(profile_name);
                        }
                        break;
                    case CommonCommands::QUERY:
                        print_usage = query_not_allowed(message.str());
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::set_name(profile_name, values[DEFAULT_POSITION]);
                        }
                        break;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }

        if (print_usage)
        {
            std::cout << PARTICIPANT_NAME_USAGE << std::endl;
        }
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
        // Check help value
        print_usage = check_help(values);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Final element
        print_usage = print_usage || !check_final_element(true, subelement, message.str());

        if (!print_usage)
        {
            try
            {
                switch (command)
                {
                    case CommonCommands::CLEAR:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::clear_use_builtin_transports(profile_name);
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::print_use_builtin_transports(profile_name);
                        }
                        break;
                    case CommonCommands::QUERY:
                        print_usage = query_not_allowed(message.str());
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::set_use_builtin_transports(profile_name,
                                    values[DEFAULT_POSITION]);
                        }
                        break;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }

        if (print_usage)
        {
            std::cout << PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE << std::endl;
        }
    }
    else if (element == USER_DATA_SUBELEMENT)
    {
        std::cout << "Participant user data QoS configuration not yet supported" << std::endl;
    }
    else if (element == USER_TRANSPORTS_SUBELEMENT)
    {
        print_usage = check_help(values);
        print_usage = print_usage || !check_keyed(true, keyed, message.str());
        print_usage = print_usage || !check_final_element(true, subelement, message.str());

        if (!print_usage)
        {
            try
            {
                switch (command)
                {
                    case CommonCommands::CLEAR:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::clear_user_transports(profile_name, key);
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::print_user_transports(profile_name, key);
                        }
                        break;
                    case CommonCommands::QUERY:
                        // TODO: maybe additional validity check is required checking that keys has not been passed to
                        //       the query command.
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        print_usage = print_usage || !check_index(key, true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::user_transports_size(profile_name);
                        }
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::domain_participant::set_user_transports(profile_name,
                                    values[DEFAULT_POSITION], key);
                        }
                        break;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }

        if (print_usage)
        {
            if (CommonCommands::QUERY != command)
            {
                std::cout << PARTICIPANT_USER_TRANSPORTS_USAGE << std::endl;
            }
            else
            {
                // TODO
                // std::cout << PARTICIPANT_USER_TRANSPORTS_QUERY_USAGE << std::endl;
            }
        }
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
