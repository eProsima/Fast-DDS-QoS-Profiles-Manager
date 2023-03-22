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

#include <subparsers/set_subparser.hpp>

#include <iostream>
#include <map>
#include <regex>
#include <string>

#include <docopt/docopt.h>

#include <parser_constants.hpp>
#include <subparsers/subparsers_usages.hpp>

namespace eprosima {
namespace qosprof_cli {

void set_subparser(
        std::string /*filename*/,
        int argc,
        char** argv)
{
    std::map<std::string, docopt::value> args = docopt::docopt(
        SET_SUBPARSER_USAGE,
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
        std::cout << "Participant configuration not yet supported" << std::endl;
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
