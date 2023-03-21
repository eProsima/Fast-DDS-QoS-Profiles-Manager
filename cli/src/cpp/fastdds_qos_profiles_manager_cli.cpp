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

#include <docopt/docopt.h>

#include "config.h"

static const char USAGE[] =
        R"(Fast DDS QoS Profiles Manager CLI

    Usage:
      fastddsqosprof <file> <verb> [<args>...]
      fastddsqosprof (-v | --version | -h | --help)

    Options:
      -v --version      CLI version.
      -h --help         CLI general options.

    The allowed <verb> commands are:
      set               Write XML configuration parameter to file.
      validate          Validate XML configuration file against Fast DDS XSD schema.
      print             Print XML configuration parameter.
      query             Query about XML parameter list size or keys.
      clear             Erase XML configuration parameter from file.
      compare           Compare between two XML configuration files.
      help              CLI specific options for the corresponding configuration parameter.
)";

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

    return 0;
}
