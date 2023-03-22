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
        set_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
    }
    else if (verb == VALIDATE_VERB)
    {
        // Validate verb is already parsed. Ensure that no follow-up argument has been included.
        if (args[PARSER_ARGS].asStringList().empty())
        {
            // Call validate method from library and handle return to output information to CLI user.
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
        print_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
    }
    else if (verb == QUERY_VERB)
    {
        query_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
    }
    else if (verb == CLEAR_VERB)
    {
        clear_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
    }
    else if (verb == COMPARE_VERB)
    {
        // Compare subparser
    }
    else if (verb == HELP_VERB)
    {
        help_subparser(args[PARSER_FILE].asString(), argc - 2, argv + 2);
    }
    else
    {
        std::cout << "ERROR: " << verb << " verb not supported" << std::endl;
        std::cout << USAGE << std::endl;
        exit(1);
    }

    return 0;
}
