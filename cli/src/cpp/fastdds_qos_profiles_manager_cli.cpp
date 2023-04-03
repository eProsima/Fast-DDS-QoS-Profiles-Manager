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

#include <config.h>
#include <parser_constants.hpp>
#include <utils/utils.hpp>
#include <usages.hpp>

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

    std::string command = args[PARSER_COMMAND].asString();
    if (command == SET_COMMAND)
    {
        // Set command requires at least one more follow-up arguments: element being set
        if (0 < args[PARSER_ARGS].asStringList().size())
        {
            main_element_parser(CommonCommands::SET, args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: set command requires at least one follow-up argument" << std::endl;
            std::cout << SET_USAGE << std::endl;
        }
    }
    else if (command == VALIDATE_COMMAND)
    {
        // Validate command is already parsed. Ensure that no follow-up argument has been included.
        if (args[PARSER_ARGS].asStringList().empty())
        {
            // Call validate method from library and handle return to output information to CLI user.
            std::cout << "Validate feature not yet implemented" << std::endl;
        }
        else
        {
            std::cout << "ERROR: validate command does not support any follow-up argument" << std::endl;
            std::cout << VALIDATE_USAGE << std::endl;
        }
    }
    else if (command == PRINT_COMMAND)
    {
        if (args[PARSER_ARGS].asStringList().empty())
        {
            // Call file print method from library
            std::cout << "Print of file feature not yet implemented" << std::endl;
        }
        else if (1 == args[PARSER_ARGS].asStringList().size())
        {
            main_element_parser(CommonCommands::PRINT, args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: print command required none or only one follow-up argument" << std::endl;
            std::cout << PRINT_USAGE << std::endl;
        }
    }
    else if (command == QUERY_COMMAND)
    {
        // Query command requires at least one more follow-up arguments: element being queried
        if (0 < args[PARSER_ARGS].asStringList().size())
        {
            // Specific parser is required to check if there is an option (size | keys) or if the default is being used
            std::cout << "Query subparser not yet implemented" << std::endl;
        }
        else
        {
            std::cout << "ERROR: query command requires at least one follow-up argument" << std::endl;
            std::cout << QUERY_USAGE << std::endl;
        }
    }
    else if (command == CLEAR_COMMAND)
    {
        // Clear command requires only one follow-up argument: element to be cleared
        if (1 == args[PARSER_ARGS].asStringList().size())
        {
            main_element_parser(CommonCommands::CLEAR, args[PARSER_FILE].asString(), argc - 2, argv + 2);
        }
        else
        {
            std::cout << "ERROR: clear command requires only one follow-up argument" << std::endl;
            std::cout << CLEAR_USAGE << std::endl;
        }
    }
    else if (command == COMPARE_COMMAND)
    {
        // Compare command is already parsed. Ensure that only one follow-up argument has been included.
        if (1 == args[PARSER_ARGS].asStringList().size())
        {
            // Call compare method from library and handle return to output information to CLI user.
            std::cout << "Compare feature not yet implemented" << std::endl;
        }
        else
        {
            std::cout << "ERROR: compare command requires only one follow-up argument" << std::endl;
            std::cout << COMPARE_USAGE << std::endl;
        }
    }
    else if (command == HELP_COMMAND || command == HELP_SHORTHAND_FLAG || command == HELP_FLAG)
    {
        if (args[PARSER_ARGS].asStringList().empty())
        {
            std::cout << USAGE << std::endl;
        }
        else
        {
            std::cout << "ERROR: help command requires no follow-up element" << std::endl;
            std::cout << HELP_USAGE << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: " << command << " command not recognized" << std::endl;
        std::cout << USAGE << std::endl;
    }

    return 0;
}
