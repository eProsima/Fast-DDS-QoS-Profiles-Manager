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

#include <cassert>
#include <string>
#include <vector>

#include <parser_constants.hpp>
#include <usages.hpp>
#include <utils/utils.hpp>

namespace eprosima {
namespace qosprof_cli {

void endpoint_subelement_parser(
        DDSEntity endpoint,
        CommonCommands command,
        const std::string& filename,
        const std::string& profile_name,
        std::string& element,
        const std::vector<std::string>& values)
{
    // This method must be called only for DataReader or DataWriter entities
    assert(endpoint == DDSEntity::DATAREADER || endpoint == DDSEntity::DATAWRITER);

    std::string subelement;
    std::string key;
    bool keyed = extract_element_subelement_key(element, subelement, key);

    // Initialize message in case of error
    std::ostringstream message;
    message << ((endpoint == DDSEntity::DATAREADER) ? "DataReader <" : "DataWriter <") << element << ">";

    bool print_usage = false;
    print_usage = subelement.empty() && check_help(values);

    if (!print_usage)
    {
        if (element == ALLOCATIONS_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "allocations configuration not yet supported" << std::endl;
        }
        else if (element == BINARY_PROPERTY_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "binary properties configuration not yet supported" << std::endl;
        }
        else if (element == DEFAULT_PROFILE_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "default profile attribute configuration not yet supported" << std::endl;
        }
        else if (element == ENTITY_ID_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "entity ID configuration not yet supported" << std::endl;
        }
        else if (element == EXPECT_INLINE_QOS_SUBELEMENT)
        {
            if (DDSEntity::DATAREADER == endpoint)
            {
                std::cout << "DataReader expect inline qos flag configuration not yet supported" << std::endl;
            }
            else
            {
                std::cout << "ERROR: " << element << " element not recognized" << std::endl;
                print_usage = true;
            }
        }
        else if (element == EXTERNAL_LOCATORS_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "external locators not yet supported" << std::endl;
        }
        else if (element == HISTORY_MEMORY_POLICY_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "history memory policy configuration not yet supported" << std::endl;
        }
        else if (element == IGNORE_NON_MATCHING_LOCATORS_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "ignore non matching locators configuration flag not yet supported" << std::endl;
        }
        else if (element == LOCATORS_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "locators configuration not yet supported" << std::endl;
        }
        else if (element == PROPERTY_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "properties configuration not yet supported" << std::endl;
        }
        else if (element == QOS_SUBELEMENT)
        {
            print_usage = subelement.empty() && check_help(values);
            print_usage = print_usage || !check_keyed(false, keyed, message.str());
            print_usage = print_usage || !check_final_element(false, subelement, message.str());

            if (!print_usage)
            {
                qos_parser(endpoint, command, filename, profile_name, subelement, values);
            }
        }
        else if (element == TIMES_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "time related parameters configuration not yet supported" << std::endl;
        }
        else if (element == USER_DEFINED_ID_SUBELEMENT)
        {
            std::cout << ((DDSEntity::DATAREADER == endpoint) ? "DataReader " : "DataWriter ")
                      << "user defined ID configuration not yet supported" << std::endl;
        }
        else
        {
            print_usage = true;
            std::cout << "ERROR: " << element << " element not recognized" << std::endl;
        }
    }

    if (print_usage)
    {
        if (CommonCommands::QUERY != command)
        {
            std::cout << ((endpoint == DDSEntity::DATAREADER) ? DATAREADER_USAGE : DATAWRITER_USAGE) << std::endl;
        }
        else
        {
            // TODO
            // std::cout << ((endpoint == DDSEntity::DATAREADER) ? DATAREADER_QUERY_USAGE :
            //        DATAWRITER_QUERY_USAGE) << std::endl;
        }
    }
}

} // qosprof_cli
} // eprosima
