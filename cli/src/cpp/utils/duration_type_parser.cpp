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

#include <fastdds_qos_profiles_manager/data_reader/Qos.hpp>
#include <fastdds_qos_profiles_manager/data_writer/Qos.hpp>
#include <fastdds_qos_profiles_manager/domain_participant/builtin/discovery_config/DiscoveryConfig.hpp>
#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <argument_constants.hpp>
#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

bool duration_type_selector(
        DDSEntity entity,
        DurationTypeList& duration_type,
        const std::string& parent,
        std::string& element,
        std::string& subelement,
        const std::vector<std::string>& values,
        std::ostringstream& message)
{
    bool print_usage = false;
    std::string dummy_key;
    bool keyed = extract_element_subelement_key(element, subelement, dummy_key);

    message << ": '" << element << "' duration type";

    print_usage = check_help(values);

    if (!print_usage)
    {
        switch (entity)
        {
            case DDSEntity::DATAREADER:
                if (parent == RELIABILITY_ELEMENT && element == MAX_BLOCKING_TIME_ELEMENT)
                {
                    duration_type = DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME;
                }
                else
                {
                    std::cout << message.str() << " not yet implemented or not recognized" << std::endl;
                    print_usage = true;
                }
                break;
            case DDSEntity::DATAWRITER:
                if (parent == RELIABILITY_ELEMENT && element == MAX_BLOCKING_TIME_ELEMENT)
                {
                    duration_type = DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME;
                }
                else
                {
                    std::cout << message.str() << " not yet implemented or not recognized" << std::endl;
                    print_usage = true;
                }
                break;
            case DDSEntity::PARTICIPANT:
                if (parent == DISCOVERY_CONFIG_SUBELEMENT && element == LEASE_ELEMENT)
                {
                    duration_type = DurationTypeList::PARTICIPANT_LEASE_DURATION;
                }
                else if (parent == DISCOVERY_CONFIG_SUBELEMENT && element == ANNOUNCEMENTS_ELEMENT)
                {
                    duration_type = DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD;
                }
                else if (parent == INITIAL_ANNOUNCEMENTS_SUBELEMENT && element == PERIOD_ELEMENT)
                {
                    duration_type = DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD;
                }
                else if (parent == CLIENT_ANNOUNCEMENTS_SUBELEMENT && element == PERIOD_ELEMENT)
                {
                    duration_type = DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD;
                }
                else
                {
                    std::cout << "ERROR: " << message.str() << " not recognized" << std::endl;
                    print_usage = true;
                }
                break;
            case DDSEntity::TOPIC:
                // TODO: parent elements not yet defined
                break;
        }
        print_usage = print_usage || !check_keyed(false, keyed, message.str());
    }

    return !print_usage;
}

void duration_type_parser(
        DurationTypeList duration_type,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values,
        std::ostringstream& message)
{
    bool print_usage = false;
    bool set_every_element = false;
    bool set_infinite_duration = false;

    print_usage = command != CommonCommands::SET && !check_command_arguments(command, 0, values.size(), message.str(),
                    true);

    // No subelement
    if (!print_usage && element.empty())
    {
        try
        {
            switch (command)
            {
                case CommonCommands::CLEAR:
                    switch (duration_type)
                    {
                        case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                            // TODO
                            break;
                        case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::clear_lease_announcement(filename,
                                    profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::clear_client_announcement_period(
                                filename, profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::clear_initial_announcements_period(
                                filename, profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                            qosprof::domain_participant::builtin::discovery_config::clear_lease_duration(filename,
                                    profile_name);
                            break;
                    }
                    break;
                case CommonCommands::PRINT:
                    switch (duration_type)
                    {
                        case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                            // TODO
                            break;
                        case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                            // TODO
                            break;
                        case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                            // TODO
                            break;
                        case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::print_lease_announcement(filename,
                                    profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::print_client_announcement_period(
                                filename, profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                            qosprof::domain_participant::builtin::discovery_config::print_initial_announcements_period(
                                filename, profile_name);
                            break;
                        case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                            qosprof::domain_participant::builtin::discovery_config::print_lease_duration(filename,
                                    profile_name);
                            break;
                    }
                    break;
                case CommonCommands::QUERY:
                    print_usage = query_not_allowed(message.str());
                    break;
                case CommonCommands::SET:
                    // At least one argument
                    print_usage = !check_command_arguments(command, 1, values.size(), message.str(), false);
                    if (!print_usage)
                    {
                        if (values.size() == 1)
                        {
                            set_infinite_duration = true;
                        }
                        else if (values.size() == 2)
                        {
                            set_every_element = true;
                        }
                        else
                        {
                            print_usage = true;
                            std::cout << "ERROR: " << common_command_str[command] << " command for " << message.str()
                                      << " expects at most 2 arguments and received " << values.size() << std::endl;
                        }
                    }
                    break;
            }
        }
        catch (const qosprof::Exception& e)
        {
            std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
        }
    }

    if (!element.empty() || set_every_element || set_infinite_duration)
    {
        if (!element.empty())
        {
            final_subelement_check(command, print_usage, element, message, values.size());
        }

        if (!print_usage)
        {
            try
            {
                bool element_valid = false;
                if (element == SECONDS_SUBELEMENT || set_every_element || set_infinite_duration)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_lease_announcement_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_client_announcement_period_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_initial_announcements_period_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::clear_lease_duration_sec(
                                        filename, profile_name);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_lease_announcement_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_client_announcement_period_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_initial_announcements_period_sec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::print_lease_duration_sec(
                                        filename, profile_name);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            print_usage = query_not_allowed(message.str());
                        case CommonCommands::SET:
                            std::string seconds = set_every_element ? values[DurationTypeArgumentPosition::SECONDS] :
                                    set_infinite_duration ? values[DEFAULT_POSITION] == CLI_INFINITE_ARGUMENT ?
                                    LIB_INFINITE_ARGUMENT : values[DEFAULT_POSITION] : values[DEFAULT_POSITION];
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    qosprof::data_reader::qos::set_reliability_max_blocking_time_sec(filename,
                                            profile_name, seconds);
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    qosprof::data_writer::qos::set_reliability_max_blocking_time_sec(filename,
                                            profile_name, seconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_lease_announcement_sec(filename, profile_name, seconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_client_announcement_period_sec(filename, profile_name, seconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_initial_announcements_period_sec(filename, profile_name, seconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::set_lease_duration_sec(
                                        filename, profile_name, seconds);
                                    break;
                            }
                            break;
                    }
                }
                if (element == NANOSECONDS_SUBELEMENT || set_every_element)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_lease_announcement_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_client_announcement_period_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_initial_announcements_period_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            clear_lease_duration_nanosec(filename, profile_name);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    // TODO
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_lease_announcement_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_client_announcement_period_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_initial_announcements_period_nanosec(filename, profile_name);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            print_lease_duration_nanosec(filename, profile_name);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            print_usage = query_not_allowed(message.str());
                        case CommonCommands::SET:
                            std::string nanoseconds = set_every_element ?
                                    values[DurationTypeArgumentPosition::NANOSECONDS] : values[DEFAULT_POSITION];
                            switch (duration_type)
                            {
                                case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    qosprof::data_reader::qos::set_reliability_max_blocking_time_nanosec(filename,
                                            profile_name, nanoseconds);
                                    break;
                                case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                                    // TODO
                                    break;
                                case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                                    qosprof::data_writer::qos::set_reliability_max_blocking_time_nanosec(filename,
                                            profile_name, nanoseconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_lease_announcement_nanosec(filename, profile_name, nanoseconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_client_announcement_period_nanosec(filename, profile_name, nanoseconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                                    qosprof::domain_participant::builtin::discovery_config::
                                            set_initial_announcements_period_nanosec(filename, profile_name,
                                            nanoseconds);
                                    break;
                                case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                                    qosprof::domain_participant::builtin::discovery_config::set_lease_duration_nanosec(
                                        filename, profile_name, nanoseconds);
                                    break;
                            }
                            break;
                    }
                }

                if (!element_valid)
                {
                    std::cout << "ERROR: " << element << " subelement not recognized" << std::endl;
                    print_usage = true;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }
    }

    if (print_usage)
    {
        std::string usage;
        switch (duration_type)
        {
            case DurationTypeList::DATAREADER_HEARTBEAT_RESPONSE_DELAY:
                // TODO
                break;
            case DurationTypeList::DATAREADER_INITIAL_ACKNACK_DELAY:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_DEADLINE_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_LATENCY_BUDGET_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_LIFESPAN_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_LIVELINESS_LEASE_DURATION:
                // TODO
                break;
            case DurationTypeList::DATAREADER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
            case DurationTypeList::DATAWRITER_QOS_RELIABILITY_MAX_BLOCKING_TIME:
                usage = RELIABILITY_DURATION_QOS_USAGE;
                break;
            case DurationTypeList::DATAWRITER_HEARTBEAT_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_INITIAL_HEARTBEAT_DELAY:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_NACK_RESPONSE_DELAY:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_NACK_SUPRESSION:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_DEADLINE_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_DISABLE_POSITIVE_ACKS_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_LATENCY_BUDGET_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_LIFESPAN_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_LIVELINESS_ANNOUNCEMENT_PERIOD:
                // TODO
                break;
            case DurationTypeList::DATAWRITER_QOS_LIVELINESS_LEASE_DURATION:
                // TODO
                break;
            case DurationTypeList::PARTICIPANT_ANNOUNCEMENT_PERIOD:
            case DurationTypeList::PARTICIPANT_LEASE_DURATION:
                usage = PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE;
                break;
            case DurationTypeList::PARTICIPANT_CLIENT_ANNOUNCEMENT_PERIOD:
                // TODO
                break;
            case DurationTypeList::PARTICIPANT_INITIAL_ANNOUNCEMENTS_PERIOD:
                // TODO
                break;
        }
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
