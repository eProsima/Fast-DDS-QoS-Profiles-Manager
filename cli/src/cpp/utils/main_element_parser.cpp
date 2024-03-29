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
#include <map>
#include <string>
#include <vector>

#include <docopt/docopt.h>

#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void main_element_parser(
        CommonCommands command,
        int argc,
        char** argv)
{
    std::string usage;
    switch (command)
    {
        case CommonCommands::CLEAR:
            // usage = CLEAR_SUBPARSER_USAGE;
            std::cout << "Clear subparser not yet implemented" << std::endl;
            break;
        case CommonCommands::PRINT:
            // usage = PRINT_SUBPARSER_USAGE;
            std::cout << "Print subparser not yet implemented" << std::endl;
            break;
        case CommonCommands::QUERY:
            // usage = QUERY_SUBPARSER_USAGE;
            std::cout << "Query subparser not yet implemented" << std::endl;
            break;
        case CommonCommands::SET:
            usage = SET_SUBPARSER_USAGE;
            break;
            // No default because this method is only called with these CommonCommands.
    }

    std::map<std::string, docopt::value> args = docopt::docopt(
        usage,
        {argv + 1, argv + argc },
        true,
        {},
        true);

    std::string element = args[PARSER_ELEMENT].asString();
    std::vector<std::string> values = args[PARSER_VALUES].asStringList();

    std::string subelement;
    std::string profile_name;
    extract_element_subelement_key(element, subelement, profile_name);

    bool print_usage = false;
    if (element == DATAREADER_ELEMENT || element == DATAWRITER_ELEMENT)
    {
        print_usage = subelement.empty() && check_help(values);
        // TODO: this would need to be refactored and check in the lower level because if the subelement is
        // default_profile, then the profile name is only mandatory in the SET command.
        print_usage = print_usage || !check_profile(profile_name, element);
        print_usage = print_usage || !check_final_element(false, subelement, element);

        if (!print_usage)
        {
            endpoint_subelement_parser(((element == DATAREADER_ELEMENT) ?
                    DDSEntity::DATAREADER : DDSEntity::DATAWRITER), command, profile_name, subelement,
                    values);
        }
        else
        {
            if (CommonCommands::QUERY != command)
            {
                std::cout << ((element == DATAREADER_ELEMENT) ? DATAREADER_USAGE : DATAWRITER_USAGE) << std::endl;
            }
            else
            {
                // TODO
                // std::cout << ((element == DATAREADER_ELEMENT) ? DATAREADER_QUERY_USAGE : DATAWRITER_QUERY_USAGE)
                //           << std::endl;
            }
        }
    }
    else if (element == HELP_COMMAND)
    {
        std::cout << usage << std::endl;
    }
    else if (element == INTRAPROCESS_ELEMENT)
    {
        std::cout << "Intra-process configuration not yet supported" << std::endl;
    }
    else if (element == LOG_ELEMENT)
    {
        std::cout << "Log module configuration not yet supported" << std::endl;
    }
    else if (element == PARTICIPANT_ELEMENT)
    {
        // If there is no subelement and the last value is (help | -h | --help), print usage
        print_usage = subelement.empty() && check_help(values);
        // Participant element requires a profile name
        // TODO: this would need to be refactored and check in the lower level because if the subelement is
        // default_profile, then the profile name is only mandatory in the SET command.
        print_usage = print_usage || !check_profile(profile_name, element);
        // Participant element requires a subelement
        print_usage = print_usage || !check_final_element(false, subelement, element);

        if (!print_usage)
        {
            participant_subelement_parser(command, profile_name, subelement, values);
        }
        else
        {
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
    else if (element == TOPIC_ELEMENT)
    {
        std::cout << "Topic configuration not yet supported" << std::endl;
    }
    else if (element == TRANSPORT_ELEMENT)
    {
        // If there is no subelement and the last value is (help | -h | --help), print usage
        print_usage = subelement.empty() && check_help(values);
        // Transport element requires a transport identifier
        print_usage = print_usage || !check_profile(profile_name, element);
        // Transport element requires a subelement
        print_usage = print_usage || !check_final_element(false, subelement, element);

        if (!print_usage)
        {
            transport_subelement_parser(command, profile_name, subelement, values);
        }
        else
        {
            if (CommonCommands::QUERY != command)
            {
                std::cout << TRANSPORT_USAGE << std::endl;
            }
            else
            {
                // TODO
                // std::cout << TRANSPORT_QUERY_USAGE << std::endl;
            }
        }
    }
    else if (element == TYPES_ELEMENT)
    {
        std::cout << "Dynamic types configuration not yet supported" << std::endl;
    }
    else
    {
        std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
