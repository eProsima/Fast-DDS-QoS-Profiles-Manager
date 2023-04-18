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

#include <fastdds_qos_profiles_manager_lib/domain_participant/builtin/MetatrafficExternalUnicastLocators.hpp>

#include <string>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <common/LocatorList.hpp>
#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace metatraffic_external_unicast_locators {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] profile_id Domain participant profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 *
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& profile_id,
        const bool create_if_not_existent)
{
    // Iterate through required elements, and create them if not existent
    manager.move_to_root_node();
    manager.move_to_node(utils::tag::PROFILES, create_if_not_existent);
    manager.move_to_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);
    manager.move_to_node(utils::tag::RTPS, create_if_not_existent);
    manager.move_to_node(utils::tag::BUILTIN, create_if_not_existent);
    manager.move_to_node(utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST, create_if_not_existent);
}

std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

uint32_t size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true);

    // Set the port using commons
    common::locator_list::set_port(manager, port, index, true);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true);

    // Set the address using commons
    common::locator_list::set_address(manager, address, index, true);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& externality,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true);

    // Iterate through required elements, and create them if not existent
    manager.move_to_locator_node(index, true, true);

    // Set the externality value
    manager.set_attribute_to_node(utils::tag::EXTERNALITY, externality);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& cost,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& mask,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // metatraffic_external_unicast_locators
} // builtin
} // domain_participant
} // qosprof
} // eprosima
