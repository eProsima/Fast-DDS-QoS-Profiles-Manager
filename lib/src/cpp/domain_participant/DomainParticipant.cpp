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

#include <fastdds_qos_profiles_manager_lib/domain_participant/DomainParticipant.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] profile_id Domain participant profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 * @param[in] additional_RTPS_tag additional RTPS tag to initialize directly
 *
 * @throw Error exception if XML workspace was not initialized
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& profile_id,
        const bool create_if_not_existent,
        const std::string& additional_RTPS_tag)
{
    // Check if workspace was initialized
    manager.is_initialized();

    // Iterate through required elements, and create them if not existent
    manager.move_to_root_node(create_if_not_existent);
    manager.move_to_node(utils::tag::PROFILES, create_if_not_existent);
    manager.move_to_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);

    // there are additional tags to obtain
    if (!additional_RTPS_tag.empty())
    {
        manager.move_to_node(utils::tag::RTPS, create_if_not_existent);
        manager.move_to_node(additional_RTPS_tag, create_if_not_existent);
    }
}

std::string print(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_default_profile()
{
    throw Unsupported("Unsupported");
}

std::string print_domain_id(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_name(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_ignore_non_matching_locators(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_send_socket_buffer_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_listen_socket_buffer_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_participant_id(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_transports(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_use_builtin_transports(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_prefix(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_transports_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_data_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_default_profile()
{
    throw Unsupported("Unsupported");
}

void clear_domain_id(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_name(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_ignore_non_matching_locators(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_send_socket_buffer_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_listen_socket_buffer_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_participant_id(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_use_builtin_transports(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_prefix(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void set_default_profile(
        const std::string& profile_id)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

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

void set_domain_id(
        const std::string& profile_id,
        const std::string& domain_id)
{
    throw Unsupported("Unsupported");
}

void set_name(
        const std::string& profile_id,
        const std::string& name)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::NAME);

    // Set the name node value
    manager.set_value_to_node(name);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_ignore_non_matching_locators(
        const std::string& profile_id,
        const std::string& ignore_non_matching_locators)
{
    throw Unsupported("Unsupported");
}

void set_send_socket_buffer_size(
        const std::string& profile_id,
        const std::string& send_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_listen_socket_buffer_size(
        const std::string& profile_id,
        const std::string& listen_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_participant_id(
        const std::string& profile_id,
        const std::string& participant_id)
{
    throw Unsupported("Unsupported");
}

void set_use_builtin_transports(
        const std::string& profile_id,
        const std::string& use_builtin_transports)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::USE_BUILTIN_TRANSPORTS);

    // Set the name node value
    manager.set_value_to_node(use_builtin_transports);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_prefix(
        const std::string& profile_id,
        const std::string& prefix)
{
    throw Unsupported("Unsupported");
}

void set_user_transports(
        const std::string& profile_id,
        const std::string& transport_id,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::USER_TRANSPORTS);

    // Obtain / create the transport located at the index position in the collection
    manager.move_to_node(index, utils::tag::TRANSPORT_ID, true);

    // set node value
    manager.set_value_to_node(transport_id);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_user_data(
        const std::string& profile_id,
        const std::string& user_data,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
