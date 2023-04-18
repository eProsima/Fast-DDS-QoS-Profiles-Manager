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

#include <fastdds_qos_profiles_manager/data_reader/Qos.hpp>
#include <fastdds_qos_profiles_manager/data_writer/Qos.hpp>
#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <argument_constants.hpp>
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
        bool print_error = false;
        print_usage = check_help(values);
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
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
                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    // TODO
                                    break;
                                case DDSEntity::DATAWRITER:
                                    // TODO
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    // TODO
                                    break;
                                case DDSEntity::DATAWRITER:
                                    // TODO
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                    case CommonCommands::QUERY:
                        print_usage = !query_not_allowed(message.str());
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            std::string durability_kind;
                            if (values[DEFAULT_POSITION] == CLI_PERSISTENT_ARGUMENT)
                            {
                                durability_kind = LIB_PERSISTENT_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_TRANSIENT_ARGUMENT)
                            {
                                durability_kind = LIB_TRANSIENT_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_TRANSIENT_LOCAL_ARGUMENT)
                            {
                                durability_kind = LIB_TRANSIENT_LOCAL_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_VOLATILE_ARGUMENT)
                            {
                                durability_kind = LIB_VOLATILE_ARGUMENT;
                            }
                            else
                            {
                                durability_kind = values[DEFAULT_POSITION];
                            }

                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    qosprof::data_reader::qos::set_durability_kind(filename, profile_name,
                                            durability_kind);
                                    break;
                                case DDSEntity::DATAWRITER:
                                    qosprof::data_writer::qos::set_durability_kind(filename, profile_name,
                                            durability_kind);
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                }
                if (print_error)
                {
                    std::cout << "ERROR: Durability QoS cannot be set in given DDS Entity" << std::endl;
                    print_usage = true;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }

        if (print_usage)
        {
            std::cout << DURABILITY_QOS_USAGE << std::endl;
        }
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
        print_usage = subelement.empty() && check_help(values);
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        print_usage = print_usage || !check_final_element(false, subelement, message.str());

        if (!print_usage)
        {
            reliability_qos_parser(entity, command, filename, profile_name, subelement, values, message);
        }
        else
        {
            std::cout << RELIABILITY_QOS_USAGE << std::endl;
        }
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
        if (!check_help(values))
        {
            std::cout << message.str() << " not recognized" << std::endl;
        }

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

void reliability_qos_parser(
        DDSEntity entity,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values,
        std::ostringstream& message)
{
    bool print_usage = false;
    bool print_error = false;
    std::string subelement;
    std::string dummy_key;

    bool keyed = extract_element_subelement_key(element, subelement, dummy_key);
    message << ": '" << element << "' attribute";

    if (element == KIND_SUBELEMENT)
    {
        print_usage = check_help(values);
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
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
                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    // TODO
                                    break;
                                case DDSEntity::DATAWRITER:
                                    // TODO
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                    case CommonCommands::PRINT:
                        print_usage = !check_command_arguments(command, 0, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    // TODO
                                    break;
                                case DDSEntity::DATAWRITER:
                                    // TODO
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                    case CommonCommands::QUERY:
                        print_usage = !query_not_allowed(message.str());
                        break;
                    case CommonCommands::SET:
                        print_usage = !check_command_arguments(command, 1, values.size(), message.str(), true);
                        if (!print_usage)
                        {
                            std::string reliability_kind;
                            if (values[DEFAULT_POSITION] == CLI_BEST_EFFORT_ARGUMENT)
                            {
                                reliability_kind = LIB_BEST_EFFORT_ARGUMENT;
                            }
                            else if (values[DEFAULT_POSITION] == CLI_RELIABLE_ARGUMENT)
                            {
                                reliability_kind = LIB_RELIABLE_ARGUMENT;
                            }
                            else
                            {
                                reliability_kind = values[DEFAULT_POSITION];
                            }

                            switch (entity)
                            {
                                case DDSEntity::DATAREADER:
                                    qosprof::data_reader::qos::set_reliability_kind(filename, profile_name,
                                            reliability_kind);
                                    break;
                                case DDSEntity::DATAWRITER:
                                    qosprof::data_writer::qos::set_reliability_kind(filename, profile_name,
                                            reliability_kind);
                                    break;
                                default:
                                    print_error = true;
                                    break;
                            }
                        }
                        break;
                }
                if (print_error)
                {
                    std::cout << "ERROR: Reliability QoS cannot be set in given DDS Entity" << std::endl;
                    print_usage = true;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }
        if (print_usage)
        {
            std::cout << RELIABILITY_KIND_QOS_USAGE << std::endl;
        }
    }
    else if (element == DURATION_SUBELEMENT)
    {
        print_usage = check_help(values);
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
        print_usage = print_usage || !check_final_element(false, subelement, message.str());

        DurationTypeList duration_type;
        std::string subsubelement;
        print_usage = print_usage || !duration_type_selector(entity, duration_type, RELIABILITY_ELEMENT, subelement,
                        subsubelement, values, message);
        if (!print_usage)
        {
            duration_type_parser(duration_type, command, filename, profile_name, subsubelement, values, message);
        }
        else
        {
            std::cout << RELIABILITY_DURATION_QOS_USAGE << std::endl;
        }
    }
    else
    {
        if (!check_help(values))
        {
            std::cout << "ERROR: " << message.str() << " not recognized" << std::endl;
        }
        std::cout << RELIABILITY_QOS_USAGE << std::endl;
    }
}

} // qosprof_cli
} // eprosima
