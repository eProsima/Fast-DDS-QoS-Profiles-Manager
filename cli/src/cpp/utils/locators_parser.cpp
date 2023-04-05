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

#include <fastdds_qos_profiles_manager/domain_participant/builtin/InitialPeers.hpp>
#include <fastdds_qos_profiles_manager/domain_participant/builtin/MetatrafficMulticastLocators.hpp>
#include <fastdds_qos_profiles_manager/domain_participant/builtin/MetatrafficUnicastLocators.hpp>
#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <parser_constants.hpp>
#include <utils/utils.hpp>
#include <usages.hpp>

namespace eprosima {
namespace qosprof_cli {

void locators_parser(
        LocatorsList list,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::string& key,
        const std::vector<std::string>& values,
        std::ostringstream& message)
{
    bool print_usage = false;
    bool set_several_elements = false;

    // Validity checks of locator list element has been performed in the upper level. Also help check
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
                    switch (list)
                    {
                        case LocatorsList::DATAREADER_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAREADER_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAWRITER_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAWRITER_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                            qosprof::domain_participant::builtin::initial_peers::clear(filename, profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                            qosprof::domain_participant::builtin::metatraffic_multicast_locators::clear(filename,
                                    profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                            qosprof::domain_participant::builtin::metatraffic_unicast_locators::clear(filename,
                                    profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                            // TODO
                            break;
                    }
                    break;
                case CommonCommands::PRINT:
                    switch (list)
                    {
                        case LocatorsList::DATAREADER_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAREADER_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAWRITER_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::DATAWRITER_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                            // TODO
                            break;
                        case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                            qosprof::domain_participant::builtin::initial_peers::print(filename, profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                            qosprof::domain_participant::builtin::metatraffic_multicast_locators::print(filename,
                                    profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                            qosprof::domain_participant::builtin::metatraffic_unicast_locators::print(filename,
                                    profile_name, key);
                            break;
                        case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                            // TODO
                            break;
                    }
                    break;
                case CommonCommands::QUERY:
                    // TODO: query kind should be passed in order to select the corresponding library function
                    break;
                case CommonCommands::SET:
                    // SET command requires 3 values: kind, address, and port.
                    print_usage = !check_command_arguments(command, 3, values.size(), message.str(), true);
                    set_several_elements = print_usage ? false : true;
                    break;
            }
        }
        catch(const qosprof::Exception& e)
        {
            std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
        }
    }

    if (!element.empty() || set_several_elements)
    {
        if (!element.empty())
        {
            std::string dummy_subelement;
            std::string dummy_key;
            bool keyed = extract_element_subelement_key(element, dummy_subelement, dummy_key);
            message << " <" << element << "> attribute";
            print_usage = print_usage || !check_keyed(false, keyed, message.str());
            print_usage = print_usage || !check_final_element(true, dummy_subelement, message.str());
            print_usage = print_usage || (CommonCommands::SET == command &&
                    !check_command_arguments(command, 1, values.size(), message.str(), true));
        }

        if (!print_usage)
        {
            try
            {
                bool element_valid = false;
                if (element == ADDRESS_SUBELEMENT || set_several_elements)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::clear_address(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::clear_address(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::clear_address(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_address(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::print_address(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::print_address(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string address = set_several_elements ?
                                    values[locators::LocatorArgumentPosition::ADDRESS] : values[DEFAULT_POSITION];
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_address(filename,
                                            profile_name, address, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::set_address(
                                            filename, profile_name, address, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::set_address(
                                            filename, profile_name, address, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                    }
                }
                if (element == KIND_SUBELEMENT || set_several_elements)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            print_usage = true;
                            std::cout << "ERROR: trying to clear a mandatory configuration parameter. "
                                      << "Either update the locator kind or else clear the entire locator" << std::endl;
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_kind(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::print_kind(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::print_kind(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string kind = set_several_elements ?
                                    values[locators::LocatorArgumentPosition::KIND] : values[DEFAULT_POSITION];
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_kind(filename,
                                            profile_name, kind, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::set_kind(
                                            filename, profile_name, kind, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::set_kind(
                                            filename, profile_name, kind, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                    }
                }
                if (element == PHYSICAL_PORT_SUBELEMENT)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::clear_physical_port(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            clear_physical_port(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            clear_physical_port(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_physical_port(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            print_physical_port(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            print_physical_port(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_physical_port(filename,
                                            profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            set_physical_port(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            set_physical_port(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                    }
                }
                if (element == PORT_SUBELEMENT || set_several_elements)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::clear_port(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::clear_port(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::clear_port(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_port(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::print_port(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::print_port(
                                            filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string port = set_several_elements ?
                                    values[locators::LocatorArgumentPosition::PORT] : values[DEFAULT_POSITION];
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_port(filename,
                                            profile_name, port, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::set_port(
                                            filename, profile_name, port, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::set_port(
                                            filename, profile_name, port, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                    }
                }
                if (element == UNIQUE_LAN_ID_SUBELEMENT)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::clear_unique_lan_id(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            clear_unique_lan_id(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            clear_unique_lan_id(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_unique_lan_id(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            print_unique_lan_id(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            print_unique_lan_id(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_unique_lan_id(filename,
                                            profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            set_unique_lan_id(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            set_unique_lan_id(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                    }
                }
                if (element == WAN_ADDRESS_SUBELEMENT)
                {
                    element_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::clear_wan_address(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            clear_wan_address(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            clear_wan_address(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::print_wan_address(filename,
                                            profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            print_wan_address(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            print_wan_address(filename, profile_name, key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            switch (list)
                            {
                                case LocatorsList::DATAREADER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    // TODO
                                    break;
                                case LocatorsList::PARTICIPANT_INITIAL_PEERS:
                                    qosprof::domain_participant::builtin::initial_peers::set_wan_address(filename,
                                            profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
                                    qosprof::domain_participant::builtin::metatraffic_multicast_locators::
                                            set_wan_address(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_unicast_locators::
                                            set_wan_address(filename, profile_name, values[DEFAULT_POSITION], key);
                                    break;
                                case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                                    // TODO
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
            catch(const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
            
        }
    }

    if (print_usage)
    {
        std::string usage;
        switch (list)
        {
            case LocatorsList::DATAREADER_MULTICAST:
                // TODO
                break;
            case LocatorsList::DATAREADER_UNICAST:
                // TODO
                break;
            case LocatorsList::DATAWRITER_MULTICAST:
                // TODO
                break;
            case LocatorsList::DATAWRITER_UNICAST:
                // TODO
                break;
            case LocatorsList::PARTICIPANT_DEFAULT_MULTICAST:
                // TODO
                break;
            case LocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                // TODO
                break;
            case LocatorsList::PARTICIPANT_INITIAL_PEERS:
            case LocatorsList::PARTICIPANT_METATRAFFIC_MULTICAST:
            case LocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                usage = PARTICIPANT_BUILTIN_LOCATORS_USAGE;
                break;
            case LocatorsList::PARTICIPANT_REMOTE_SERVER_METATRAFFIC_UNICAST:
                // TODO
                break;
        }
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
