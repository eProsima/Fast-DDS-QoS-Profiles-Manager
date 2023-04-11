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

#include <common/LocatorList.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace locator_list {

std::string print(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_port(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_physical_port(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_address(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_unique_lan_id(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_wan_address(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

uint32_t size(
        utils::XMLManager& manager,
        const xercesc::DOMElement& xml_node)
{
    throw Unsupported("Unsupported");
}

void clear(
        utils::XMLManager& manager,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_port(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_physical_port(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_address(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_unique_lan_id(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_wan_address(
        utils::XMLManager& manager,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_kind(
        utils::XMLManager& manager,
        const std::string& kind,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_port(
        utils::XMLManager& manager,
        const std::string& port,
        const std::string& index,
        const bool is_external)
{
    // append the new kind node directly to the given parent
    if (is_external)
    {
        manager.get_locator_node(index, utils::tag::UDP_V4_LOCATOR, true);
    }
    // create <locator> tag if required
    else
    {
        manager.get_locator_node(index, utils::tag::LOCATOR, true);
    }

    // add port node to the kind node
    manager.get_node(utils::tag::PORT, true);

    // set port node value
    manager.set_value_to_node(port);
}

void set_physical_port(
        utils::XMLManager& manager,
        const std::string& physical_port,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_address(
        utils::XMLManager& manager,
        const std::string& address,
        const std::string& index,
        const bool is_external)
{
    // append the new kind node directly to the given parent
    if (is_external)
    {
        manager.get_locator_node(index, utils::tag::UDP_V4_LOCATOR, true);
    }
    // create <locator> tag if required
    else
    {
        manager.get_locator_node(index, utils::tag::LOCATOR, true);
    }

    // add address node to the kind node
    manager.get_node(utils::tag::ADDRESS, true);

    // set address node value
    manager.set_value_to_node(address);
}

void set_unique_lan_id(
        utils::XMLManager& manager,
        const std::string& unique_lan_id,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_wan_address(
        utils::XMLManager& manager,
        const std::string& wan_address,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

} // locator_list
} // common
} // qosprof
} // eprosima
