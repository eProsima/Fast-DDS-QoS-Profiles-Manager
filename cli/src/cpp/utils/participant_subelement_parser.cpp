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

#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void participant_subelement_parser(
        CommonCommands /*command*/,
        const std::string& /*filename*/,
        const std::string& /*profile_name*/,
        std::string& subelement,
        const std::regex& pattern,
        const std::vector<std::string>& /*values*/)
{
    std::smatch match;
    std::regex_search(subelement, match, pattern);
}

} // qosprof_cli
} // eprosima
