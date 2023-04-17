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

#include <string>
#include <vector>

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
    std::string subelement;
    std::string key;

    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message <<  "Transport <" << element << ">";

    print_usage = subelement.empty() && check_help(values);

    if (!print_usage)
    {
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
            std::cout << "Interface whitelist configuration not yet supported" << std::endl;
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
            std::cout << "Kind configuration not yet supported" << std::endl;
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
            std::cout << message.str() << " not recognized" << std::endl;
        }
    }

    if (print_usage)
    {
        if (CommonCommands::QUERY != command)
        {
            std::cout <<  TRANSPORT_USAGE << std::endl;
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
