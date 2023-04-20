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

#include <sstream>
#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager_lib/transport_descriptor/TransportDescriptor.hpp>
#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <argument_constants.hpp>
#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void transport_subelement_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& transport_identifier,
        std::string& element,
        const std::vector<std::string>& values)
{
    bool print_usage = false;
    std::string usage_to_print;
    std::string subelement;
    std::string key;

    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message <<  "Transport descriptor <" << element << ">";

    if (element == CALCULATE_CRC_SUBELEMENT)
    {
        std::cout << "Calculate CRC configuration not yet supported" << std::endl;
    }
    else if (element == CHECK_CRC_SUBELEMENT)
    {
        std::cout << "Check CRC configuration not yet supported" << std::endl;
    }
    else if (element == ENABLE_TCP_NODELAY_SUBELEMENT)
    {
        std::cout << "Enable TCP nodelay configuration not yet supported" << std::endl;
    }
    else if (element == HEALTHY_CHECK_TIMEOUT_SUBELEMENT)
    {
        std::cout << "Healthy check timeout configuration not yet supported" << std::endl;
    }
    else if (element == INTERFACE_WHITELIST_SUBELEMENT)
    {
        // If there is no subelement and the last value is (help | -h | --help), print usage
        print_usage = subelement.empty() && check_help(values);
        // Keyed element
        print_usage = print_usage || !check_keyed(true, keyed, message.str());
        // Kind element does NOT require a subelement
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
                            qosprof::transport_descriptor::clear_interface_whitelist(filename, transport_identifier,
                                    key);
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::transport_descriptor::print_interface_whitelist(filename, transport_identifier,
                                    key);
                        }
                        break;
                    case CommonCommands::QUERY:
                        // TODO: query kind should be passed in order to check the arguments and the amount of them
                        //qosprof::transport_descriptor::interface_whitelist_size(filename, transport_identifier);
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::transport_descriptor::set_interface_whitelist(filename, transport_identifier,
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
            if (CommonCommands::QUERY == command)
            {
                // TODO
                // std::cout << TRANSPORT_QUERY_USAGE << std::endl;
            }
            else
            {
                usage_to_print = TRANSPORT_WHITELIST_INTERFACE_USAGE;
            }
        }
    }
    else if (element == KEEP_ALIVE_FREQUENCY_SUBELEMENT)
    {
        std::cout << "Keep alive frequency configuration not yet supported" << std::endl;
    }
    else if (element == KEEP_ALIVE_TIMEOUT_SUBELEMENT)
    {
        std::cout << "Keep alive timeout configuration not yet supported" << std::endl;
    }
    else if (element == KIND_SUBELEMENT)
    {
        // If there is no subelement and the last value is (help | -h | --help), print usage
        print_usage = subelement.empty() && check_help(values);
        // Not keyed element
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        // Kind element does NOT require a subelement
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
                            qosprof::transport_descriptor::clear_kind(filename, transport_identifier);
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            qosprof::transport_descriptor::print_kind(filename, transport_identifier);
                        }
                        break;
                    case CommonCommands::QUERY:
                        print_usage = query_not_allowed(message.str());
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            std::string kind = values[DEFAULT_POSITION];
                            if (values[DEFAULT_POSITION] == CLI_UDP_V4_ARGUMENT)
                            {
                                kind = LIB_UDP_V4_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_UDP_V6_ARGUMENT)
                            {
                                kind = LIB_UDP_V6_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_TCP_V4_ARGUMENT)
                            {
                                kind = LIB_TCP_V4_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_TCP_V6_ARGUMENT)
                            {
                                kind = LIB_TCP_V6_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_SHM_ARGUMENT)
                            {
                                kind = LIB_SHM_ARGUMENT;
                            }
                            else
                            {
                                kind = values[DEFAULT_POSITION];
                            }
                            qosprof::transport_descriptor::set_kind(filename, transport_identifier, kind);
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
            if (CommonCommands::QUERY == command)
            {
                // TODO
                // std::cout << TRANSPORT_QUERY_USAGE << std::endl;
            }
            else
            {
                usage_to_print = TRANSPORT_KIND_USAGE;
            }
        }
    }
    else if (element == LISTENING_PORT_SUBELEMENT)
    {
        std::cout << "Listening port configuration not yet supported" << std::endl;
    }
    else if (element == LOGICAL_PORT_INCREMENT_SUBELEMENT)
    {
        std::cout << "Logical port increment configuration not yet supported" << std::endl;
    }
    else if (element == LOGICAL_PORT_RANGE_SUBELEMENT)
    {
        std::cout << "Logical port range configuration not yet supported" << std::endl;
    }
    else if (element == MAX_INITIAL_PEERS_RANGE_SUBELEMENT)
    {
        std::cout << "Maximum initial peers range configuration not yet supported" << std::endl;
    }
    else if (element == MAX_LOGICAL_PORT_SUBELEMENT)
    {
        std::cout << "Maximum logical port configuration not yet supported" << std::endl;
    }
    else if (element == MAX_MESSAGE_SIZE_SUBELEMENT)
    {
        std::cout << "Maximum message size configuration not yet supported" << std::endl;
    }
    else if (element == NON_BLOCKING_SEND_SUBELEMENT)
    {
        std::cout << "Non-blocking send configuration not yet supported" << std::endl;
    }
    else if (element == OUTPUT_PORT_SUBELEMENT)
    {
        std::cout << "Output port configuration not yet supported" << std::endl;
    }
    else if (element == PORT_QUEUE_CAPACITY_SUBELEMENT)
    {
        std::cout << "Port queue capacity configuration not yet supported" << std::endl;
    }
    else if (element == RECEIVE_BUFFER_SIZE_SUBELEMENT)
    {
        std::cout << "Receive buffer size configuration not yet supported" << std::endl;
    }
    else if (element == RTPS_DUMP_FILE_SUBELEMENT)
    {
        std::cout << "RTPS dump file configuration not yet supported" << std::endl;
    }
    else if (element == SEGMENT_SIZE_SUBELEMENT)
    {
        std::cout << "Segment size configuration not yet supported" << std::endl;
    }
    else if (element == SEND_BUFFER_SIZE_SUBELEMENT)
    {
        std::cout << "Send buffer size configuration not yet supported" << std::endl;
    }
    else if (element == TLS_SUBELEMENT)
    {
        std::cout << "TLS configuration not yet supported" << std::endl;
    }
    else if (element == TTL_SUBELEMENT)
    {
        std::cout << "TTL configuration not yet supported" << std::endl;
    }
    else if (element == WAN_ADDRESS_SUBELEMENT)
    {
        std::cout << "WAN address configuration not yet supported" << std::endl;
    }
    else
    {
        print_usage = true;
        std::cout << "ERROR: " << message.str() << " element not recognized" << std::endl;
    }


    if (print_usage)
    {
        if (CommonCommands::QUERY != command)
        {
            if (usage_to_print.empty())
            {
                usage_to_print = TRANSPORT_USAGE;
            }
            std::cout <<  usage_to_print << std::endl;
        }
        else
        {
            // TODO
            //std::cout <<  TRANSPORT_QUERY_USAGE << std::endl;
        }
    }
}

} // qosprof_cli
} // eprosima
