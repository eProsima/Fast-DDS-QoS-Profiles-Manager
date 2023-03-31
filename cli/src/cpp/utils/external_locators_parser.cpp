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
    // External locator list must be keyed
    if (!extract_element_subelement_key(element, subelement, key))
    {
        std::cout << "ERROR: external locator <" << element << "> list must be keyed []" << std::endl;
        print_usage = true;
    }

    // HELP command has been handled in the upper level so usage should be printed in case of wrong arguments.
    bool set_every_element = false;
    // Not SET commands require no values at all.
    if (values.size() != 0 && command != CommonCommands::SET && !print_usage)
    {
        std::cout << "ERROR: the given command does not require any value" << std::endl;
        print_usage = true;
    }
    // No subelement.
    else if (subelement.empty() && !print_usage)
    {
        // Invalid arguments check
        // SET command requires 6 values: kind, externality, cost, address, mask and port.
        if (values.size() != 6 && command == CommonCommands::SET)
        {
            std::cout << "ERROR: external locator <" << element
                      << "> list requires 6 configuration paramenters if no <subelement> is configured" << std::endl;
            print_usage = true;
        }
        // Call library
        else
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
                                // TODO
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
                                // TODO
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

    if (!print_usage && (!subelement.empty() || set_every_element))
    {
        if (!subelement.empty())
        {
            std::string dummy_subelement;
            std::string dummy_key;
            // Subelement should not be keyed
            if (extract_element_subelement_key(subelement, dummy_subelement, dummy_key))
            {
                std::cout << "ERROR: external locator <" << subelement << "> attribute is not keyed" << std::endl;
                print_usage = true;
            }
            // Subelement should be final
            else if (!dummy_subelement.empty())
            {
                std::cout << "ERROR: external locator <" << subelement << "> attribute is FINAL element" << std::endl;
                print_usage = true;
            }
            // SET command requires only one argument
            else if (values.size() != 1 && command == CommonCommands::SET)
            {
                std::cout << "ERROR: external locator <" << element << "[]." << subelement <<
                    "> requires only 1 configuration parameter" << std::endl;
                print_usage = true;
            }
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
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    std::string address = set_every_element ? values[3] : values[0];
                                    qosprof::domain_participant::default_external_unicast_locators::set_address(
                                        filename, profile_name, address, key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    std::string cost = set_every_element ? values[2] : values[0];
                                    qosprof::domain_participant::default_external_unicast_locators::set_cost(
                                        filename, profile_name, cost, key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    std::string externality = set_every_element ? values[1] : values[0];
                                    qosprof::domain_participant::default_external_unicast_locators::set_externality(
                                        filename, profile_name, externality, key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    qosprof::domain_participant::default_external_unicast_locators::set_kind(
                                        filename, profile_name, values[0], key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    std::string mask = set_every_element ? values[4] : values[0];
                                    qosprof::domain_participant::default_external_unicast_locators::set_mask(
                                        filename, profile_name, mask, key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                                    // TODO
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
                                case ExternalLocatorsList::DATAREADER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::DATAWRITER_UNICAST:
                                    // TODO
                                    break;
                                case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
                                {
                                    std::string port = set_every_element ? values[5] : values[0];
                                    qosprof::domain_participant::default_external_unicast_locators::set_port(
                                        filename, profile_name, port, key);
                                }
                                break;
                                case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
                                    // TODO
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
                // usage = PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE;
                break;
        }
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
