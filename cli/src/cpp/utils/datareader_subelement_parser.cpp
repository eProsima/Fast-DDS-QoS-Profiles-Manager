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

#include <string>
#include <vector>

#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void datareader_subelement_parser(
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    std::string subelement;
    std::string key;
    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message << "DataReader <" << element << ">";

    bool print_usage = false;
    if (element == ALLOCATIONS_SUBELEMENT)
    {
        std::cout << "DataReader allocations configuration not yet supported" << std::endl;
    }
    else if (element == BINARY_PROPERTY_SUBELEMENT)
    {
        std::cout << "DataReader binary properties configuration not yet supported" << std::endl;
    }
    else if (element == DEFAULT_PROFILE_SUBELEMENT)
    {
        std::cout << "DataReader default attribute configuration not yet supported" << std::endl;
    }
    else if (element == ENTITY_ID_SUBELEMENT)
    {
        std::cout << "DataReader entity ID configuration not yet supported" << std::endl;
    }
    else if (element == EXPECT_INLINE_QOS_SUBELEMENT)
    {
        std::cout << "DataReader expect inline qos flag configuration not yet supported" << std::endl;
    }
    else if (element == EXTERNAL_LOCATORS_SUBELEMENT)
    {
        std::cout << "DataReader external locators not yet supported" << std::endl;
    }
    else if (element == HISTORY_MEMORY_POLICY_SUBELEMENT)
    {
        std::cout << "DataReader history memory policy configuration not yet supported" << std::endl;
    }
    else if (element == IGNORE_NON_MATCHING_LOCATORS_SUBELEMENT)
    {
        std::cout << "DataReader ignore non matching locators configuration flag not yet supported" << std::endl;
    }
    else if (element == LOCATORS_SUBELEMENT)
    {
        std::cout << "DataReader locators configuration not yet supported" << std::endl;
    }
    else if (element == PROPERTY_SUBELEMENT)
    {
        std::cout << "DataReader properties configuration not yet supported" << std::endl;
    }
    else if (element == QOS_SUBELEMENT)
    {
        std::cout << "DataReader QoS configuration not yet supported" << std::endl;
    }
    else if (element == TIMES_SUBELEMENT)
    {
        std::cout << "DataReader time related parameters configuration not yet supported" << std::endl;
    }
    else if (element == USER_DEFINED_ID_SUBELEMENT)
    {
        std::cout << "DataReader user defined ID configuration not yet supported" << std::endl;
    }
    else
    {
        if (!check_help(values))
        {
            std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        }

        if (CommonCommands::QUERY != command)
        {
            std::cout << DATAREADER_USAGE << std::endl;
        }
        else
        {
            // TODO
            // std::cout << DATAREADER_QUERY_USAGE << std::endl;
        }
    }
}

} // qosprof_cli
} // eprosima
