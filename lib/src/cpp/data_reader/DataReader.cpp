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

/**
 * @file
 */

#include <fastdds_qos_profiles_manager/data_reader/DataReader.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace data_reader {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] profile_id DataReader profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 * @param[in] additional_tag Additional required TAG
 *
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& profile_id,
        const bool create_if_not_existent,
        const std::string& additional_tag)
{
    // Iterate through required elements, and create them if not existent
    manager.get_node(utils::tag::PROFILES, create_if_not_existent);
    manager.get_node(utils::tag::DATA_READER, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);
    if (!additional_tag.empty())
    {
        manager.get_node(additional_tag, create_if_not_existent);
    }
}

void set_default_profile(
        const std::string& xml_file,
        const std::string& profile_id)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, false);

    // Obtain base node position
    initialize_namespace(manager, profile_id, false, "");

    // Check if default profile already defined
    try
    {
        if (manager.get_node_attribute_value(utils::tag::DEFAULT_PROFILE) == "true")
        {
            // This profile is already the default profile
            return;
        }
    }
    // Default profile attribute not defined
    catch (const ElementNotFound& ex)
    {
        // do nothing
    }
    // Set all domain participant 'is_default_profile' attributes as false
    manager.set_siblings_attribute(utils::tag::DEFAULT_PROFILE, "false");

    // Set this entity as default profile
    manager.set_attribute_to_node(utils::tag::DEFAULT_PROFILE, "true");

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

} // data_reader
} // qosprof
} // eprosima