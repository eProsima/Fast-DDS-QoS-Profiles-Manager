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

void qos_parser(
        DDSEntity entity,
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
    message << ((entity == DDSEntity::DATAREADER) ? "DataReader <" : "DataWriter <") << element << "> QoS";

    print_usage = subelement.empty() && check_help(values);

    if (!print_usage)
    {
        if (element == DATASHARING_ELEMENT)
        {
            std::cout << "DataSharing QoS configuration not yet supported" << std::endl;
        }
        else if (element == DURATION_SUBELEMENT)
        {
            std::cout << "Duration-related QoS (Deadline, Latency budget and Lifespan) configuration not yet supported"
                        << std::endl;
        }
        else if (element == DISABLE_HEARTBEAT_PIGGYBACK_ELEMENT)
        {
            if (entity == DDSEntity::DATAREADER)
            {
                print_usage = true;
                std::cout << "ERROR: " << message.str() << " not recognized" << std::endl;
            }
            else
            {
                std::cout << "Disable heartbeat piggyback QoS configuration not yet supported" << std::endl;
            }
        }
        else if (element == DISABLE_POSITIVE_ACKS_ELEMENT)
        {
            std::cout << "Disable positive ACKs QoS Policy configuration not yet supported" << std::endl;
        }
        else if (element == DURABILITY_ELEMENT)
        {
            std::cout << "Durability QoS configuration not yet supported" << std::endl;
        }
        else if (element == GROUP_DATA_ELEMENT)
        {
            std::cout << "Group Data QoS Policy configuration not yet supported" << std::endl;
        }
        else if (element == HISTORY_ELEMENT)
        {
            std::cout << "History QoS Policy configuration not yet supported" << std::endl;
        }
        else if (element == LIVELINESS_ELEMENT)
        {
            std::cout << "Liveliness QoS Policy configuration not yet supported" << std::endl;
        }
        else if (element == OWNERSHIP_ELEMENT)
        {
            std::cout << "Ownership and Ownership strength QoS Policies configuration not yet supported" << std::endl;
        }
        else if (element == PARTITIONS_ELEMENT)
        {
            std::cout << "Partitions QoS Policy not yet supported" << std::endl;
        }
        else if (element == PUBLISH_MODE_ELEMENT)
        {
            if (entity == DDSEntity::DATAREADER)
            {
                print_usage = true;
                std::cout << "ERROR: " << message.str() << " not recognized" << std::endl;
            }
            else
            {
                std::cout << "Publish mode QoS configuration not yet supported" << std::endl;
            }
        }
        else if (element == RELIABILITY_ELEMENT)
        {
            std::cout << "Reliability QoS configuration not yet supported" << std::endl;
        }
        else if (element == RESOURCE_LIMITS_ELEMENT)
        {
            std::cout << "Resource Limits QoS configuration not yet supported" << std::endl;
        }
        else if (element == TOPIC_DATA_ELEMENT)
        {
            std::cout << "Topic Data QoS configuration not yet supported" << std::endl;
        }
        else if (element == USER_DATA_SUBELEMENT)
        {
            std::cout << "User Data QoS configuration not yet supported" << std::endl;
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
            std::cout << ((entity == DDSEntity::DATAREADER) ? DATAREADER_QOS_USAGE : DATAWRITER_QOS_USAGE) << std::endl;
        }
        else
        {
            // TODO
            // std::cout << ((entity == DDSEntity::DATAREADER) ? DATAREADER_QOS_QUERY_USAGE :
            //        DATAWRITER_QOS_QUERY_USAGE) << std::endl;
        }
    }
}

} // qosprof_cli
} // eprosima
