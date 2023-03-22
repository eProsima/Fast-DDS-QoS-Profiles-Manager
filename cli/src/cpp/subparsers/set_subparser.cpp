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
}

} // qosprof_cli
} // eprosima
