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

#include <fastdds_qos_profiles_manager_lib/domain_participant/builtin/discovery_config/DiscoveryConfig.hpp>

#include <string>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <common/Duration.hpp>
#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace discovery_config {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] profile_id Domain participant profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 * @param[in] additional_tag additional tag to obtain base node
 *
 * @throw Error exception if XML workspace was not initialized
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& profile_id,
        const bool create_if_not_existent,
        const std::string& additional_tag)
{
    // Check if workspace was initialized
    manager.is_initialized();

    // Iterate through required elements, and create them if not existent
    manager.move_to_root_node(create_if_not_existent);
    manager.move_to_node(utils::tag::PROFILES, create_if_not_existent);
    manager.move_to_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);
    manager.move_to_node(utils::tag::RTPS, create_if_not_existent);
    manager.move_to_node(utils::tag::BUILTIN, create_if_not_existent);
    manager.move_to_node(utils::tag::DISCOVERY_CONFIG, create_if_not_existent);
    if (!additional_tag.empty())
    {
        manager.move_to_node(additional_tag, create_if_not_existent);
    }
}

std::string print(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_discovery_protocol(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_ignore_participant_flags(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_edp(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_simple_edp(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_simple_edp_pubwriter_subreader(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_simple_edp_pubreader_subwriter(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_duration(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_duration_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_duration_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_announcement(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_announcement_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_lease_announcement_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_initial_announcements(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_initial_announcements_count(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_initial_announcements_period(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_initial_announcements_period_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_initial_announcements_period_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_client_announcement_period(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_client_announcement_period_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_client_announcement_period_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

uint32_t static_edp_xml_config_size(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_discovery_protocol(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_ignore_participant_flags(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_edp(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_simple_edp(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_simple_edp_pubwriter_subreader(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_simple_edp_edp_pubreader_subwriter(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_duration(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_duration_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_duration_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_announcement(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_announcement_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_lease_announcement_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_initial_announcements(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_initial_announcements_count(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_initial_announcements_period(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_initial_announcements_period_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_initial_announcements_period_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_client_announcement_period(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_client_announcement_period_sec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_client_announcement_period_nanosec(
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_discovery_protocol(
        const std::string& profile_id,
        const std::string& discovery_protocol)
{
    throw Unsupported("Unsupported");
}

void set_ignore_participant_flags(
        const std::string& profile_id,
        const std::string& ignore_participant_flags)
{
    throw Unsupported("Unsupported");
}

void set_edp(
        const std::string& profile_id,
        const std::string& edp)
{
    throw Unsupported("Unsupported");
}

void set_simple_edp_pubwriter_subreader(
        const std::string& profile_id,
        const std::string& simple_edp_pubwriter_subreader)
{
    throw Unsupported("Unsupported");
}

void set_simple_edp_pubreader_subwriter(
        const std::string& profile_id,
        const std::string& simple_edp_pubreader_subwriter)
{
    throw Unsupported("Unsupported");
}

void set_lease_duration_sec(
        const std::string& profile_id,
        const std::string& duration_sec)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::LEASE_DURATION);

    // Set duration value
    common::duration::set_sec(manager, duration_sec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_lease_duration_nanosec(
        const std::string& profile_id,
        const std::string& duration_nanosec)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::LEASE_DURATION);

    // Set duration value
    common::duration::set_nanosec(manager, duration_nanosec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_lease_announcement_sec(
        const std::string& profile_id,
        const std::string& announcement_sec)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::LEASE_ANNOUNCEMENT);

    // Set duration value
    common::duration::set_sec(manager, announcement_sec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_lease_announcement_nanosec(
        const std::string& profile_id,
        const std::string& announcement_nanosec)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::LEASE_ANNOUNCEMENT);

    // Set duration value
    common::duration::set_nanosec(manager, announcement_nanosec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_initial_announcements_count(
        const std::string& profile_id,
        const std::string& count)
{
    throw Unsupported("Unsupported");
}

void set_initial_announcements_period_sec(
        const std::string& profile_id,
        const std::string& period_sec)
{
    throw Unsupported("Unsupported");
}

void set_initial_announcements_period_nanosec(
        const std::string& profile_id,
        const std::string& period_nanosec)
{
    throw Unsupported("Unsupported");
}

void set_client_announcement_period_sec(
        const std::string& profile_id,
        const std::string& period_sec)
{
    throw Unsupported("Unsupported");
}

void set_client_announcement_period_nanosec(
        const std::string& profile_id,
        const std::string& period_nanosec)
{
    throw Unsupported("Unsupported");
}

void set_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& static_edp_xml_config,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // discovery_config
} // builtin
} // domain_participant
} // qosprof
} // eprosima
