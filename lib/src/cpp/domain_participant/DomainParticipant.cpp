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

#include <fastdds_qos_profiles_manager/domain_participant/DomainParticipant.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {

std::string print(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_default_profile(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

std::string print_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_transport(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_transport_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_data_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_default_profile(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

void clear_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void set_default_profile(
        const std::string& xml_file,
        const std::string& profile_id)
{
    // Define a default_profile node
    xercesc::DOMNode* default_profile_node = nullptr;

    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, false);

    // Iterate through required elements, and create them if not existent
    manager.get_node(utils::tag::PROFILES, false);
    manager.get_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, false);

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
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& domain_id)
{
    throw Unsupported("Unsupported");
}

void set_name(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& name)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Iterate through required elements, and create them if not existent
    manager.get_node(utils::tag::PROFILES, true);
    manager.get_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, true);
    manager.get_node(utils::tag::RTPS, true);
    manager.get_node(utils::tag::NAME, true);

    // Set the name node value
    manager.set_value_to_node(name);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& ignore_non_matching_locators)
{
    throw Unsupported("Unsupported");
}

void set_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& send_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& listen_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_participant_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& participant_id)
{
    throw Unsupported("Unsupported");
}

void set_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& use_builtin_transports)
{
    throw Unsupported("Unsupported");
}

void set_prefix(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix)
{
    throw Unsupported("Unsupported");
}

void set_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
