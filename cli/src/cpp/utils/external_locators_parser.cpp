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

#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void external_locators_parser(
        ExternalLocatorsList list,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    // Select usage depending on the element being parsed
    std::string usage;
    switch (list)
    {
        case ExternalLocatorsList::DATAREADER_UNICAST:
            // usage = DATAREADER_EXTERNAL_UNICAST_LOCATORS_USAGE;
            break;
        case ExternalLocatorsList::DATAWRITER_UNICAST:
            // usage = DATAWRITER_EXTERNAL_UNICAST_LOCATORS_USAGE;
            break;
        case ExternalLocatorsList::PARTICIPANT_DEFAULT_UNICAST:
            usage = PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE;
            break;
        case ExternalLocatorsList::PARTICIPANT_METATRAFFIC_UNICAST:
            // usage = PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE;
            break;
    }

    std::string subelement;
    std::string key;

    // External locator list must be keyed
    if (!extract_element_subelement_key(element, subelement, key))
    {
        std::cout << "ERROR: external locator <" << element << "> list must be keyed []" << std::endl;
        std::cout << usage << std::endl;
    }
}

} // qosprof_cli
} // eprosima
