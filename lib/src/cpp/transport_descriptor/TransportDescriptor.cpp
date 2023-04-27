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

#include <fastdds_qos_profiles_manager_lib/transport_descriptor/TransportDescriptor.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace transport_descriptor {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] transport_id Transport descriptor profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 * @param[in] additional_tag additional tag to obtain node
 *
 * @throw Error exception if XML workspace was not initialized
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& transport_id,
        const bool create_if_not_existent,
        const std::string& additional_tag)
{
    // Check if workspace was initialized
    manager.is_initialized();

    // Iterate through required elements, and create them if not existent
    manager.move_to_root_node(create_if_not_existent);
    manager.move_to_node(utils::tag::PROFILES, create_if_not_existent);
    manager.move_to_transport_node(transport_id, create_if_not_existent);
    if (!additional_tag.empty())
    {
        manager.move_to_node(additional_tag, create_if_not_existent);
    }
}

std::string print(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_send_buffer_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_receive_buffer_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_max_message_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_max_initial_peers_range(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_interface_whitelist(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_ttl(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_non_blocking_send(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_output_port(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_wan_addr(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_keep_alive_frequency_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_keep_alive_timeout_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_max_logical_port(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_logical_port_range(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_logical_port_increment(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_listening_ports(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_tls(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_password(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_private_key_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_rsa_private_key_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_cert_chain_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_tmp_dh_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_verify_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_verify_mode(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_options(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_verify_paths(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_verify_depth(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_default_verify_path(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_handshake_role(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_tls_server_name(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_calculate_crc(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_check_crc(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_enable_tcp_nodelay(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_segment_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_port_queue_capacity(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_healthy_check_timeout_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

std::string print_rtps_dump_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

uint32_t size()
{
    throw Unsupported("Unsupported");
}

std::vector<std::string> keys()
{
    throw Unsupported("Unsupported");
}

uint32_t interface_whitelist_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

uint32_t listening_ports_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

uint32_t tls_verify_mode_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

uint32_t tls_options_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

uint32_t tls_verify_paths_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_kind(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_send_buffer_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_receive_buffer_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_max_message_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_max_initial_peers_range(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_interface_whitelist(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_ttl(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_non_blocking_send(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_output_port(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_wan_addr(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_keep_alive_frequency_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_keep_alive_timeout_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_max_logical_port(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_logical_port_range(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_logical_port_increment(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_listening_ports(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_tls(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_password(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_private_key_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_rsa_private_key_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_cert_chain_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_tmp_dh_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_verify_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_verify_mode(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_tls_options(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_tls_verify_paths(
        const std::string& transport_descriptor_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_tls_verify_depth(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_default_verify_path(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_handshake_role(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_tls_server_name(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_calculate_crc(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_check_crc(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_enable_tcp_nodelay(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_segment_size(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_port_queue_capacity(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_healthy_check_timeout_ms(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void clear_rtps_dump_file(
        const std::string& transport_descriptor_id)
{
    throw Unsupported("Unsupported");
}

void set_kind(
        const std::string& transport_descriptor_id,
        const std::string& kind)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, transport_descriptor_id, true, utils::tag::TRANSPORT_KIND);

    // Set the node value
    manager.set_value_to_node(kind);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_send_buffer_size(
        const std::string& transport_descriptor_id,
        const std::string& send_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_receive_buffer_size(
        const std::string& transport_descriptor_id,
        const std::string& receive_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_max_message_size(
        const std::string& transport_descriptor_id,
        const std::string& max_message_size)
{
    throw Unsupported("Unsupported");
}

void set_max_initial_peers_range(
        const std::string& transport_descriptor_id,
        const std::string& max_initial_peers_range)
{
    throw Unsupported("Unsupported");
}

void set_ttl(
        const std::string& transport_descriptor_id,
        const std::string& ttl)
{
    throw Unsupported("Unsupported");
}

void set_non_blocking_send(
        const std::string& transport_descriptor_id,
        const std::string& non_blocking_send)
{
    throw Unsupported("Unsupported");
}

void set_output_port(
        const std::string& transport_descriptor_id,
        const std::string& output_port)
{
    throw Unsupported("Unsupported");
}

void set_wan_addr(
        const std::string& transport_descriptor_id,
        const std::string& wan_addr)
{
    throw Unsupported("Unsupported");
}

void set_keep_alive_frequency_ms(
        const std::string& transport_descriptor_id,
        const std::string& keep_alive_frequency_ms)
{
    throw Unsupported("Unsupported");
}

void set_keep_alive_timeout_ms(
        const std::string& transport_descriptor_id,
        const std::string& keep_alive_timeout_ms)
{
    throw Unsupported("Unsupported");
}

void set_max_logical_port(
        const std::string& transport_descriptor_id,
        const std::string& max_logical_port)
{
    throw Unsupported("Unsupported");
}

void set_logical_port_range(
        const std::string& transport_descriptor_id,
        const std::string& logical_port_range)
{
    throw Unsupported("Unsupported");
}

void set_logical_port_increment(
        const std::string& transport_descriptor_id,
        const std::string& logical_port_increment)
{
    throw Unsupported("Unsupported");
}

void set_tls_password(
        const std::string& transport_descriptor_id,
        const std::string& tls_password)
{
    throw Unsupported("Unsupported");
}

void set_tls_private_key_file(
        const std::string& transport_descriptor_id,
        const std::string& tls_private_key_file)
{
    throw Unsupported("Unsupported");
}

void set_tls_rsa_private_key_file(
        const std::string& transport_descriptor_id,
        const std::string& tls_rsa_private_key_file)
{
    throw Unsupported("Unsupported");
}

void set_tls_cert_chain_file(
        const std::string& transport_descriptor_id,
        const std::string& tls_cert_chain_file)
{
    throw Unsupported("Unsupported");
}

void set_tls_tmp_dh_file(
        const std::string& transport_descriptor_id,
        const std::string& tls_tmp_dh_file)
{
    throw Unsupported("Unsupported");
}

void set_tls_verify_file(
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_file)
{
    throw Unsupported("Unsupported");
}

void set_tls_verify_depth(
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_depth)
{
    throw Unsupported("Unsupported");
}

void set_tls_default_verify_path(
        const std::string& transport_descriptor_id,
        const std::string& tls_default_verify_path)
{
    throw Unsupported("Unsupported");
}

void set_tls_handshake_role(
        const std::string& transport_descriptor_id,
        const std::string& tls_handshake_role)
{
    throw Unsupported("Unsupported");
}

void set_tls_server_name(
        const std::string& transport_descriptor_id,
        const std::string& tls_server_name)
{
    throw Unsupported("Unsupported");
}

void set_calculate_crc(
        const std::string& transport_descriptor_id,
        const std::string& calculate_crc)
{
    throw Unsupported("Unsupported");
}

void set_check_crc(
        const std::string& transport_descriptor_id,
        const std::string& check_crc)
{
    throw Unsupported("Unsupported");
}

void set_enable_tcp_nodelay(
        const std::string& transport_descriptor_id,
        const std::string& enable_tcp_nodelay)
{
    throw Unsupported("Unsupported");
}

void set_segment_size(
        const std::string& transport_descriptor_id,
        const std::string& segment_size)
{
    throw Unsupported("Unsupported");
}

void set_port_queue_capacity(
        const std::string& transport_descriptor_id,
        const std::string& port_queue_capacity)
{
    throw Unsupported("Unsupported");
}

void set_healthy_check_timeout_ms(
        const std::string& transport_descriptor_id,
        const std::string& healthy_check_timeout_ms)
{
    throw Unsupported("Unsupported");
}

void set_rtps_dump_file(
        const std::string& transport_descriptor_id,
        const std::string& rtps_dump_file)
{
    throw Unsupported("Unsupported");
}

void set_interface_whitelist(
        const std::string& transport_descriptor_id,
        const std::string& ip_address,
        const std::string& index)
{
    // Create XML manager and initialize the document
    utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Obtain base node position
    initialize_namespace(manager, transport_descriptor_id, true, utils::tag::INTERFACE_WHITELIST);

    // Obtain the address located in the index position
    manager.move_to_node(index, utils::tag::ADDRESS, true);

    // Set the node value
    manager.set_value_to_node(ip_address);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_listening_ports(
        const std::string& transport_descriptor_id,
        const std::string& port,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_tls_verify_mode(
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_mode,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_tls_options(
        const std::string& transport_descriptor_id,
        const std::string& tls_options,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_tls_verify_path(
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_path,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // transport_descriptor
} // qosprof
} // eprosima
