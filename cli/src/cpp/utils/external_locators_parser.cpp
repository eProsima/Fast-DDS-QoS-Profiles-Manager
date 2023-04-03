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

#include <fastdds_qos_profiles_manager/domain_participant/builtin/MetatrafficExternalUnicastLocators.hpp>
#include <fastdds_qos_profiles_manager/domain_participant/DefaultExternalUnicastLocators.hpp>
#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void external_locators_parser(
        ExternalLocatorsList list,
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
    bool set_every_element = false;

    // Initialize message in case of error
    std::ostringstream message;
    message << "external locator <" << element << "> list";

    // HELP command has been handled in the upper level so usage should be printed in case of wrong arguments.
    // Validity checks
    // Check that the element is the expected one
    if (((list == ExternalLocatorsList::DATAREADER_UNICAST || list == ExternalLocatorsList::DATAWRITER_UNICAST) &&
            element != UNICAST_ELEMENT) ||
            (list == ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST && element != DEFAULT_UNICAST_ELEMENT) ||
            (list == ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST && element != METATRAFFIC_UNICAST_ELEMENT))
    {
        std::cout << "ERROR: " << element << " subelement not recognized" << std::endl;
        print_usage = true;
    }
    print_usage = print_usage || !check_keyed(true, keyed, message.str());
    print_usage = print_usage ||
            (command != CommonCommands::SET && !check_command_arguments(command, 0, values.size(), "the given command",
            true));

    // No subelement.
    if (subelement.empty())
    {
        // SET command requires 6 values: kind, externality, cost, address, mask and port.
        print_usage = print_usage ||
                (command == CommonCommands::SET && !check_command_arguments(command, 6, values.size(), message.str(),
                true));
        // Call library if every validity check has passed
        if (!print_usage)
        {
            try
            {
                switch (command)
                {
                    case CommonCommands::CLEAR:
                        switch (list)
                        {
                            case ExternalLocatorsList::DATAREADER_UNICAST:
                                // TODO
                                break;
                            case ExternalLocatorsList::DATAWRITER_UNICAST:
                                // TODO
                                break;
                            case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                qosprof::domain_participant::default_external_unicast_locators::clear(filename,
                                        profile_name, key);
                                break;
                            case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::clear(
                                    filename, profile_name, key);
                                break;
                        }
                        break;
                    case CommonCommands::PRINT:
                        switch (list)
                        {
                            case ExternalLocatorsList::DATAREADER_UNICAST:
                                // TODO
                                break;
                            case ExternalLocatorsList::DATAWRITER_UNICAST:
                                // TODO
                                break;
                            case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                qosprof::domain_participant::default_external_unicast_locators::print(filename,
                                        profile_name, key);
                                break;
                            case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::print(
                                    filename, profile_name, key);
                                break;
                        }
                        break;
                    case CommonCommands::QUERY:
                        // TODO: query kind should be passed in order to select the corresponding library function
                        break;
                    case CommonCommands::SET:
                        set_every_element = true;
                        break;
                }
            }
            catch (const qosprof::Exception& e)
            {
                std::cout << "Fast DDS QoS Profiles Manager exception caught: " << e.what() << std::endl;
            }
        }
    }

    if (!subelement.empty() || set_every_element)
    {
        if (!subelement.empty())
        {
            std::string dummy_subelement;
            std::string dummy_key;
            keyed = extract_element_subelement_key(subelement, dummy_subelement, dummy_key);
            message << " <" << subelement << "> attribute";
            // Should not be keyed
            print_usage = print_usage || !check_keyed(false, keyed, message.str());
            // Should be final
            print_usage = print_usage || !check_final_element(true, dummy_subelement, message.str());
            // SET command requires only one argument
            print_usage = print_usage || (CommonCommands::SET == command &&
                    !check_command_arguments(command, 1, values.size(), message.str(), true));
        }

        // Call library
        if (!print_usage)
        {
            try
            {
                bool subelement_valid = false;
                if (subelement == ADDRESS_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::clear_address(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            clear_address(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_address(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_address(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string address = set_every_element ? values[3] : values[0];
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_address(
                                        filename, profile_name, address, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_address(filename, profile_name, address, key);
                                    break;
                            }
                            break;
                    }
                }
                if (subelement == COST_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::clear_cost(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            clear_cost(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_cost(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_cost(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string cost = set_every_element ? values[2] : values[0];
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_cost(
                                        filename, profile_name, cost, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_cost(filename, profile_name, cost, key);
                                    break;
                            }
                            break;
                    }
                }
                if (subelement == EXTERNALITY_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::clear_externality(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            clear_externality(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_externality(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_externality(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string externality = set_every_element ? values[1] : values[0];
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_externality(
                                        filename, profile_name, externality, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_externality(filename, profile_name, externality, key);
                                    break;
                            }
                            break;
                    }
                }
                if (subelement == KIND_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_kind(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_kind(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_kind(
                                        filename, profile_name, values[0], key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_kind(filename, profile_name, values[0], key);
                                    break;
                            }
                            break;
                    }
                }
                if (subelement == MASK_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::clear_mask(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            clear_mask(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_mask(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_mask(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string mask = set_every_element ? values[4] : values[0];
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_mask(
                                        filename, profile_name, mask, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_mask(filename, profile_name, mask, key);
                                    break;
                            }
                            break;
                    }
                }
                if (subelement == PORT_SUBELEMENT || set_every_element)
                {
                    subelement_valid = true;
                    switch (command)
                    {
                        case CommonCommands::CLEAR:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::clear_port(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            clear_port(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::PRINT:
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::print_port(
                                        filename, profile_name, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            print_port(filename, profile_name, key);
                                    break;
                            }
                            break;
                        case CommonCommands::QUERY:
                            // TODO: query kind should be passed in order to select the corresponding library function
                            break;
                        case CommonCommands::SET:
                            std::string port = set_every_element ? values[5] : values[0];
                            switch (list)
                            {
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                    qosprof::domain_participant::default_external_unicast_locators::set_port(
                                        filename, profile_name, port, key);
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    qosprof::domain_participant::builtin::metatraffic_external_unicast_locators::
                                            set_port(filename, profile_name, port, key);
                                    break;
                            }
                            break;
                    }
                }

                if (!subelement_valid)
                {
                    std::cout << "ERROR: " << subelement << " subelement not recognized" << std::endl;
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
        // Select usage depending on the element being parsed
        // TODO: usage also depends on QUERY command
        std::string usage;
        switch (list)
        {
            case ExternalLocatorsList::DATAREADER_UNICAST:
                // usage = DATAREADER_EXTERNAL_UNICAST_LOCATORS_USAGE;
                break;
            case ExternalLocatorsList::DATAWRITER_UNICAST:
                // usage = DATAWRITER_EXTERNAL_UNICAST_LOCATORS_USAGE;
                break;
            case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                usage = PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE;
                break;
            case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                usage = PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE;
                break;
        }
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
