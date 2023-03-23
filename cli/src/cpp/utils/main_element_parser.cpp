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
#include <regex>
#include <string>

#include <docopt/docopt.h>

#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void main_element_parser(
        CommonCommands command,
        const std::string& filename,
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
        {argv +1, argv + argc },
        true,
        {},
        true);

    std::string element = args[PARSER_ELEMENT].asString();
    std::string subelement;
    std::vector<std::string> values = args[PARSER_VALUES].asStringList();

    // Parse element using regular expression
    std::regex dot_pattern("[^\\.]+");
    std::smatch match;
    std::regex_search(element, match, dot_pattern);
    element = match[0];
    subelement = match.suffix();
    // Main element might require a profile name
    std::regex bracket_pattern("\\[([^\\]]*)\\]");
    std::string profile_name;
    if (std::regex_search(element, match, bracket_pattern))
    {
        element = match.prefix();
        profile_name = match[1];
    }

    if (element == DATAREADER_ELEMENT)
    {
        std::cout << "DataReader configuration not yet supported" << std::endl;
    }
    else if (element == DATAWRITER_ELEMENT)
    {
        std::cout << "DataWriter configuration not yet supported" << std::endl;
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
        if (subelement.empty() &&
                (values.back() == HELP_COMMAND ||
                values.back() == HELP_SHORTHAND_FLAG ||
                values.back() == HELP_FLAG))
        {
            std::cout << PARTICIPANT_USAGE << std::endl;
            exit(0);
        }
        // Participant element requires a profile name
        else if (profile_name.empty() && command != CommonCommands::QUERY)
        {
            std::cout << "ERROR: profile name is required to configure the participant" << std::endl;
            if (CommonCommands::QUERY != command)
            {
                std::cout << PARTICIPANT_USAGE << std::endl;
            }
            else
            {
                // TODO
                // std::cout << PARTICIPANT_QUERY_USAGE << std::endl;
            }
            exit(1);
        }
        else
        {
            participant_subelement_parser(command, filename, profile_name, subelement, dot_pattern, values);
        }
    }
    else if (element == TRANSPORT_ELEMENT)
    {
        std::cout << "Transport descriptor configuration not yet supported" << std::endl;
    }
    else if (element == TYPES_ELEMENT)
    {
        std::cout << "Dynamic types configuration not yet supported" << std::endl;
    }
    else
    {
        std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        std::cout << SET_SUBPARSER_USAGE << std::endl;
        exit(1);
    }
}

} // qosprof_cli
} // eprosima
