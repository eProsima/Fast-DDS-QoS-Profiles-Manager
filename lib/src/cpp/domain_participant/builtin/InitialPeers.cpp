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

#include <fastdds_qos_profiles_manager/domain_participant/builtin/InitialPeers.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <common/LocatorList.hpp>
#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace initial_peers {

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
    manager.get_node(utils::tag::PROFILES, create_if_not_existent);
    manager.get_node(utils::tag::PARTICIPANT, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);
    manager.get_node(utils::tag::RTPS, create_if_not_existent);
    manager.get_node(utils::tag::BUILTIN, create_if_not_existent);
    manager.get_node(utils::tag::INITIAL_PEERS_LIST, create_if_not_existent);
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

std::string print_physical_port(
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

std::string print_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_wan_address(
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

void clear_physical_port(
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

void clear_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_wan_address(
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
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true);

    // Set the port using commons
    common::locator_list::set_port(manager, port, index, false);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& physical_port,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true);

    // Set the address using commons
    common::locator_list::set_address(manager, address, index, false);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& unique_lan_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& wan_address,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // initial_peers
} // builtin
} // domain_participant
} // qosprof
} // eprosima
