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

#include <docopt/docopt.h>

#include "config.h"
#include "parser_constants.hpp"
#include "subparsers/clear_subparser.hpp"
#include "subparsers/help_subparser.hpp"
#include "subparsers/print_subparser.hpp"
#include "subparsers/query_subparser.hpp"
#include "subparsers/set_subparser.hpp"
#include "usages.hpp"

using namespace eprosima::qosprof_cli;

int main(
        int argc,
        char* argv[])
{
    std::map<std::string, docopt::value> args = docopt::docopt(
        USAGE,
        {argv + 1, argv + argc },
        true,                                                       // show help if requested
        FASTDDS_QOS_PROFILES_MANAGER_CLI_VERSION_STR,               // version string
        true);                                                      // options first

    std::string verb = args[PARSER_VERB].asString();
    if (verb == SET_VERB)
    {
        // Set verb requires at least one more follow-up arguments: element being set
        if (0 < args[PARSER_ARGS].asStringList().size())
        {
            set_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: set verb requires at least one follow-up argument" << std::endl;
            std::cout << SET_USAGE << std::endl;
            exit(1);
        }
    }
    else if (verb == VALIDATE_VERB)
    {
        // Validate verb is already parsed. Ensure that no follow-up argument has been included.
        if (args[PARSER_ARGS].asStringList().empty())
        {
            // Call validate method from library and handle return to output information to CLI user.
            std::cout << "Validate feature not yet implemented" << std::endl;
        }
        else
        {
            std::cout << "ERROR: validate verb does not support any follow-up argument" << std::endl;
            std::cout << VALIDATE_USAGE << std::endl;
            exit(1);
        }
    }
    else if (verb == PRINT_VERB)
    {
        if (args[PARSER_ARGS].asStringList().empty())
        {
            // Call file print method from library
            std::cout << "Print of file feature not yet implemented" << std::endl;
        }
        else if (1 == args[PARSER_ARGS].asStringList().size())
        {
            print_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: print verb required none or only one follow-up argument" << std::endl;
            std::cout << PRINT_USAGE << std::endl;
            std::exit(1);
        }
    }
    else if (verb == QUERY_VERB)
    {
        // Query verb requires at least one more follow-up arguments: element being queried
        if (0 < args[PARSER_ARGS].asStringList().size())
        {
            query_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: query verb requires at least one follow-up argument" << std::endl;
            std::cout << QUERY_USAGE << std::endl;
            exit(1);
        }
    }
    else if (verb == CLEAR_VERB)
    {
        // Clear verb requires only one follow-up argument: element to be cleared
        if (1 == args[PARSER_ARGS].asStringList().size())
        {
            clear_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: clear verb requires only one follow-up argument" << std::endl;
            std::cout << CLEAR_USAGE << std::endl;
            exit(1);
        }
    }
    else if (verb == COMPARE_VERB)
    {
        // Compare verb is already parsed. Ensure that only one follow-up argument has been included.
        if (1 == args[PARSER_ARGS].asStringList().size())
        {
            // Call compare method from library and handle return to output information to CLI user.
            std::cout << "Compare feature not yet implemented" << std::endl;
        }
        else
        {
            std::cout << "ERROR: compare verb requires only one follow-up argument" << std::endl;
            std::cout << COMPARE_USAGE << std::endl;
            exit(1);
        }
    }
    else if (verb == HELP_VERB)
    {
        if (args[PARSER_ARGS].asStringList().empty())
        {
            std::cout << USAGE << std::endl;
        }
        else if (1 == args[PARSER_ARGS].asStringList().size())
        {
            help_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: help verb requires none or only one follow-up element" << std::endl;
            std::cout << HELP_USAGE << std::endl;
            exit(1);
        }
    }
    else
    {
        std::cout << "ERROR: " << verb << " verb not supported" << std::endl;
        std::cout << USAGE << std::endl;
        exit(1);
    }

    return 0;
}
