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

    // Parse element using regular expression
    std::regex dot_pattern("[^\\.]+");
    std::smatch match;
    std::regex_search(element, match, dot_pattern);
    // Main element
    if (match[0] == DATAREADER_ELEMENT)
    {
        std::cout << "DataReader configuration not yet supported" << std::endl;
    }
    else if (match[0] == DATAWRITER_ELEMENT)
    {
        std::cout << "DataWriter configuration not yet supported" << std::endl;
    }
    else if (match[0] == HELP_COMMAND)
    {
        std::cout << SET_SUBPARSER_USAGE << std::endl;
    }
    else if (match[0] == INTRAPROCESS_ELEMENT)
    {
        std::cout << "Intra-process configuration not yet supported" << std::endl;
    }
    else if (match[0] == LOG_ELEMENT)
    {
        std::cout << "Log module configuration not yet supported" << std::endl;
    }
    else if (match[0] == PARTICIPANT_ELEMENT)
    {
        element = match.suffix();
        participant_subelement_parser(command, filename, element, dot_pattern);
    }
    else if (match[0] == TRANSPORT_ELEMENT)
    {
        std::cout << "Transport descriptor configuration not yet supported" << std::endl;
    }
    else if (match[0] == TYPES_ELEMENT)
    {
        std::cout << "Dynamic types configuration not yet supported" << std::endl;
    }
    else
    {
        std::cout << "ERROR: " << match[0] << " element not recognized" << std::endl;
        std::cout << SET_SUBPARSER_USAGE << std::endl;
        exit(1);
    }
}

} // qosprof_cli
} // eprosima
