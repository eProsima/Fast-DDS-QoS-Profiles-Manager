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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_TRANSPORT_DESCRIPTOR_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_TRANSPORT_DESCRIPTOR_HPP_

#include <string>
#include <vector>

namespace eprosima {
namespace qosprof {
namespace transport_descriptor {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print every transport descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return std::string XML section containing the transport descriptor profiles.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 */
std::string print(
        const std::string& xml_file);

/**
 * @brief Parse XML file and print specific transport descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the specific transport descriptor profile.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
std::string print(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport Descriptor kind
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
std::string print_kind(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor send buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Transport descriptor send buffer size.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        send buffer size element has not been set in the profile.
 */
uint32_t print_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor receive buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Transport descriptor receive buffer size.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        receive buffer size element has not been set in the profile.
 */
uint32_t print_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor maximum message size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Transport descriptor maximum message size.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum message size element has not been set in the profile.
 */
uint32_t print_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor maximum initial peers range.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Transport descriptor maximum initial peers range.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum initial peers range element has not been set in the profile.
 */
uint32_t print_max_initial_peers_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor whitelisted network interfaces collection.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the list of the transport descriptor network interfaces whitelisted.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        interface whitelist element has not been set in the profile.
 */
std::string print_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the Transport Descriptor specific whitelisted network interface element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Transport descriptor specific network interface whitelisted.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
std::string print_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Transport Descriptor TTL (Time to live).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint8_t Transport descriptor TTL in number of hops.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TTL element has not been set in the profile.
 */
uint8_t print_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific UDP Transport Descriptor non blocking send flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return bool Transport descriptor non blocking send flag.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        non blocking send flag has not been set in the profile.
 */
bool print_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific UDP Transport Descriptor output port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint16_t UDP Transport descriptor output port.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        ouput port has not been set in the profile.
 */
uint16_t print_output_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCPv4 Transport Descriptor WAN address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::String TCPv4 Transport descriptor WAN address.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        WAN address has not been set in the profile.
 */
std::string print_wan_addr(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific frequency of TCP Transport Descriptor keep alive requests.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Frequency of TCP keep alive requests (in milliseconds).
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        keep alive frequency has not been set in the profile.
 */
uint32_t print_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific timeout (in milliseconds) to consider a TCP connection broken if no keep
 *        alive is received.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t TCP keep alive timeout (in milliseconds).
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        keep alive timeout has not been set in the profile.
 */
uint32_t print_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific maximum number of logical ports to try during TCP negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint16_t Maximum number of logical ports to try during TCP negotiation.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum number of logical ports has not been set in the profile.
 */
uint16_t print_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific maximum number of logical ports per request to try during TCP
 *        negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint16_t Maximum number of logical ports per request to try during TCP negotiation.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum number of logical ports per request has not been set in the profile.
 */
uint16_t print_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific increment between logical ports to try during TCP negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint16_t Increment between logical ports to try during TCP negotiation.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        logical port increment has not been set in the profile.
 */
uint16_t print_logical_port_increment(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor listening ports collection.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the list of the listening ports in the TCP Transport Descriptor.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening ports element has not been set in the profile.
 */
std::string print_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the TCP Transport Descriptor specific listening port element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return uint16_t TCP Transport descriptor specific listening port.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
uint16_t print_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS configuration.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the specific TCP Transport Descriptor TLS configuration.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS configuration element has not been set in the profile.
 */
std::string print_tls(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS password.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor TLS password.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS password element has not been set in the profile.
 */
std::string print_tls_password(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS private key certificate path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor path to the TLS private key certificate file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS private key certificate path element has not been set in the profile.
 */
std::string print_tls_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS private key RSA certificate path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor path to the TLS private key RSA certificate file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS private key RSA certificate path element has not been set in the profile.
 */
std::string print_tls_rsa_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS public certificate chain file path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor path to the TLS public certificate chain file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS public certificate chain file path element has not been set in the profile.
 */
std::string print_tls_cert_chain_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS Diffie-Hellman parameters file path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor path to the TLS Diffie-Hellman parameters file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS Diffie-Hellman parameters file path element has not been set in the profile.
 */
std::string print_tls_tmp_dh_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS CA (Certification Authority) file path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor path to the CA file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS CA file path element has not been set in the profile.
 */
std::string print_tls_verify_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS verification mode mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the TLS verification modes enabled in the TCP Transport Descriptor.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify mode element has not been set in the profile.
 */
std::string print_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the TCP Transport Descriptor specific TLS verification mode element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string TCP Transport descriptor specific TLS verification mode.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
std::string print_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS supported features mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the TLS options in the TCP Transport Descriptor.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS options element has not been set in the profile.
 */
std::string print_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the TCP Transport Descriptor specific TLS supported feature.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string TCP Transport descriptor specific TLS supported feature.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
std::string print_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS paths to verification files.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the TLS verification paths in the TCP Transport Descriptor.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify paths element has not been set in the profile.
 */
std::string print_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the TCP Transport Descriptor specific TLS path to verification files.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string TCP Transport descriptor specific TLS verification path.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
std::string print_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS maximum verification depth.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return int32_t Specific TCP Transport Descriptor maximum allowed depth for verifying intermediate certificates.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify depth element has not been set in the profile.
 */
int32_t print_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS verify default paths flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return bool Specific TCP Transport Descriptor verify default paths flag.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify default paths flag has not been set in the profile.
 */
bool print_tls_default_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS handshake role.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor handshake role.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS handshake role has not been set in the profile.
 */
std::string print_tls_handshake_role(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS SNI server name.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor SNI server name.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS SNI server name has not been set in the profile.
 */
std::string print_tls_server_name(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor calculate CRC flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return bool Specific TCP Transport Descriptor calculate CRC flag.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        calculate CRC flag has not been set in the profile.
 */
bool print_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor check CRC flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return bool Specific TCP Transport Descriptor check CRC flag.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        check CRC flag has not been set in the profile.
 */
bool print_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TCP_NODELAY socket option flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return bool Specific TCP Transport Descriptor TCP_NODELAY socket option flag.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TCP_NODELAY socket option flag has not been set in the profile.
 */
bool print_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor shared memory segment size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Specific SHM Transport Descriptor shared memory segment size.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        shared memory segment size has not been set in the profile.
 */
uint32_t print_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor listening port capacity.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Specific SHM Transport Descriptor listening port capacity in number of messages.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening port capacity has not been set in the profile.
 */
uint32_t print_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor listening port liveliness timeout.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Specific SHM Transport Descriptor listening port liveliness timeout (in milliseconds).
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening port liveliness timeout has not been set in the profile.
 */
uint32_t print_healthy_check_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor debugging file path.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific SHM Transport Descriptor debugging file path.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        debugging file path has not been set in the profile.
 */
std::string print_rtps_dump_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of transport descriptor profiles contained in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return uint32_t Number of transport descriptor profiles in the XML file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 */
uint32_t size(
        const std::string& xml_file);

/**
 * @brief List of the identifiers for every transport descriptor profile in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return std::vector<std::string> Identifier list.
 *         Empty list if there are no transport descriptor profiles.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 */
std::vector<std::string> keys(
        const std::string& xml_file);

/**
 * @brief Number of whitelisted network interfaces in the Transport Descriptor list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of network interfaces whitelisted in the list.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        interface whitelist element has not been set in the profile.
 */
uint32_t interface_whitelist_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Number of listening ports in the TCP Transport Descriptor list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of listening ports in the list.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening ports element has not been set in the profile.
 */
uint32_t listening_ports_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Number of TLS verification modes enabled in the mask in the TCP Transport Descriptor.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of TLS verification modes enabled in the mask.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify mode element has not been set in the profile.
 */
uint32_t tls_verify_mode_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Number of TLS supported features enabled in the mask in the TCP Transport Descriptor.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of TLS supported features enabled in the mask.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS options element has not been set in the profile.
 */
uint32_t tls_options_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Number of TLS verification paths included in the TCP Transport Descriptor.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of TLS paths to look for verification files.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify paths element has not been set in the profile.
 */
uint32_t tls_verify_paths_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Delete XML file
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 */
void clear(
        const std::string& xml_file);

/**
 * @brief Remove specific transport descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove send buffer size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove receive buffer size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum message size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum initial peers range element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_max_initial_peers_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every whitelisted network interface from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific whitelisted network interface from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
void clear_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TTL (Time to live) element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove non blocking send flag from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove output port from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_output_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove WAN address from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_wan_addr(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP keep alive frequency from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP keep alive timeout from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum number of logical ports from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum number of logical ports per request from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove logical port increment element from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_logical_port_increment(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every listening port from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific listening port from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
void clear_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TLS configuration from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS password from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_password(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS private key certificate path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS private key RSA certificate path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_rsa_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS public certificate chain file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_cert_chain_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS Diffie-Hellman parameters file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_tmp_dh_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS CA (Certification Authority) file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_verify_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every TLS verification mode from specific TCP Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS verification mode from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
void clear_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove every TLS supported features from specific TCP Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS supported feature from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
void clear_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove every TLS verification paths from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS verification path from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
void clear_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TLS maximum verification depth from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS verify default paths flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_default_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS handshake role from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_handshake_role(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS SNI server name from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_tls_server_name(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove calculate CRC flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove check CRC flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP_NODELAY socket option flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory segment size from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory listening port capacity from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory listening port liveliness timeout from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_healthy_check_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory debugging file path from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw file_not_found Exception if the provided XML file is not found/readable.
 * @throw element_not_found Exception if the specified transport descriptor profile is not found in the XML file.
 */
void clear_rtps_dump_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the Transport Descriptor kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] kind Transport descriptor kind.
 *
 * @throw element_invalid Exception if the provided kind is not valid.
 */
void set_kind(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& kind);

/**
 * @brief Set the Transport Descriptor send buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] send_buffer_size Transport descriptor send buffer size.
 *
 * @throw element_invalid Exception if the provided send buffer size is not valid.
 */
void set_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t send_buffer_size);

/**
 * @brief Set the Transport Descriptor receive buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] receive_buffer_size Transport descriptor receive buffer size.
 *
 * @throw element_invalid Exception if the provided receive buffer size is not valid.
 */
void set_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t receive_buffer_size);

/**
 * @brief Set the Transport Descriptor maximum message size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_message_size Transport descriptor maximum message size.
 *
 * @throw element_invalid Exception if the provided maximum message size is not valid.
 */
void set_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t max_message_size);

/**
 * @brief Set the Transport Descriptor maximum initial peers range.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_message_size Transport descriptor maximum initial peers range.
 *
 * @throw element_invalid Exception if the provided maximum initial peers range is not valid.
 */
void set_max_initial_peers_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t max_initial_peers_range);

/**
 * @brief Set the Transport Descriptor TTL (Time to live).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] ttl Transport descriptor TTL (Time to live) in number of hops.
 *
 * @throw element_invalid Exception if the provided TTL is not valid.
 */
void set_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint8_t ttl);

/**
 * @brief Set the Transport Descriptor non blocking send flag (UDP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] non_blocking_send Enable/disable this flag in the Transport Descriptor.
 *
 * @throw element_invalid Exception if the flag does not apply to the Transport Descriptor.
 */
void set_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        bool non_blocking_send);

/**
 * @brief Set the Transport Descriptor output port (UDP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] output_port UDP Transport output port.
 *
 * @throw element_invalid Exception if the output port provided is not valid.
 */
void set_output_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t output_port);

/**
 * @brief Set the Transport Descriptor WAN address (TCPv4 Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] wan_addr TCPv4 Transport WAN address.
 *
 * @throw element_invalid Exception if the output port provided is not valid.
 */
void set_wan_addr(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& wan_addr);

/**
 * @brief Set the TCP Transport Descriptor frequency for keep alive requests in milliseconds (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] keep_alive_frequency_ms Frequency of TCP keep alive requests (in ms).
 *
 * @throw element_invalid Exception if the provided keep alive frequency is not valid.
 */
void set_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t keep_alive_frequency_ms);

/**
 * @brief Set the TCP Transport Descriptor timeout to consider a connection broken if no keep alive request is received
 *       in milliseconds (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] keep_alive_timeout_ms Time since the last keep alive request to consider the connection broken (in ms).
 *
 * @throw element_invalid Exception if the provided keep alive timeout is not valid.
 */
void set_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t keep_alive_timeout_ms);

/**
 * @brief Set the TCP Transport Descriptor maximum number of logical ports to try during TCP negotiation (TCP Transport
 *        specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_logical_port Maximum number of logical ports to try during TCP negotiation.
 *
 * @throw element_invalid Exception if the provided maximum number of logical ports is not valid.
 */
void set_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t max_logical_port);

/**
 * @brief Set the TCP Transport Descriptor maximum number of logical ports per request to try during TCP negotiation
 *        (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] logical_port_range Maximum number of logical ports per request to try during TCP negotiation.
 *
 * @throw element_invalid Exception if the provided maximum number of logical ports per request is not valid.
 */
void set_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t logical_port_range);

/**
 * @brief Set the TCP Transport Descriptor increment between logical ports to try during TCP negotiation (TCP Transport
 *        specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] logical_port_increment Increment between logical ports to try during TCP negotiation.
 *
 * @throw element_invalid Exception if the provided maximum number of logical ports per request is not valid.
 */
void set_logical_port_increment(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t logical_port_increment);

/**
 * @brief Set the TCP Transport Descriptor TLS password (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_password TCP Transport Descriptor TLS password.
 *
 * @throw element_invalid Exception if the provided TLS password is not valid.
 */
void set_tls_password(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_password);

/**
 * @brief Set the TCP Transport Descriptor TLS private key certificate path (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_private_key_file Path to the private key certificate file.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_tls_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_private_key_file);

/**
 * @brief Set the TCP Transport Descriptor TLS private key RSA certificate path (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_rsa_private_key_file Path to the private key RSA certificate file.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_tls_rsa_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_rsa_private_key_file);

/**
 * @brief Set the TCP Transport Descriptor TLS public certificate chain file path (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_cert_chain_file Path to the public certificate chain file.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_tls_cert_chain_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_cert_chain_file);

/**
 * @brief Set the TCP Transport Descriptor TLS Diffie-Hellman parameters file path (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_tmp_dh_file Path to the Diffie-Hellman parameters file.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_tls_tmp_dh_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_tmp_dh_file);

/**
 * @brief Set the TCP Transport Descriptor TLS CA (Certification Authority) file path (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_file Path to the CA file.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_tls_verify_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_file);

/**
 * @brief Set the TCP Transport Descriptor TLS maximum allowed depth for verifying intermediate certificates (TCP
 *        Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_depth Maximum allowed depth for verifying intermediate certificates.
 *
 * @throw element_invalid Exception if the provided depth is not valid.
 */
void set_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t tls_verify_depth);

/**
 * @brief Set the TCP Transport Descriptor TLS verify default paths flag (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_default_verify_path Flag that enables looking for verification files on the default paths.
 *
 * @throw element_invalid Exception if the provided flag value is not valid.
 */
void set_tls_default_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        bool tls_default_verify_path);

/**
 * @brief Set the TCP Transport Descriptor TLS handshake role (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_handshake_role Role that the Transport will take on handshaking.
 *
 * @throw element_invalid Exception if the provided handshake role is not valid.
 */
void set_tls_handshake_role(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_handshake_role);

/**
 * @brief Set the TCP Transport Descriptor TLS SNI server name (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_server_name SNI (Server Name Indication) server name.
 *
 * @throw element_invalid Exception if the provided SNI server name is not valid.
 */
void set_tls_server_name(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_server_name);

/**
 * @brief Set the TCP Transport Descriptor calculate CRC flag (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] calculate_crc Flag to enable CRC calculation and sending.
 *
 * @throw element_invalid Exception if the provided CRC calculation flag is not valid.
 */
void set_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        bool calculate_crc);

/**
 * @brief Set the TCP Transport Descriptor check CRC flag (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] check_crc Flag to enable CRC checking of incoming messages.
 *
 * @throw element_invalid Exception if the provided check CRC flag is not valid.
 */
void set_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        bool check_crc);

/**
 * @brief Enable the TCP Transport Descriptor TCP_NODELAY socket option (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] enable_tcp_nodelay Flag to enable TCP_NODELAY socket option.
 *
 * @throw element_invalid Exception if the TCP_NODELAY flag is not valid.
 */
void set_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        bool enable_tcp_nodelay);

/**
 * @brief Set the SHM Transport Descriptor shared memory segment size (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] segment_size Shared memory segment size.
 *
 * @throw element_invalid Exception if the provided segment size is not valid.
 */
void set_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t segment_size);

/**
 * @brief Set the SHM Transport Descriptor listening port capacity (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] port_queue_capacity Listening port capacity in number of messages.
 *
 * @throw element_invalid Exception if the provided listening port capacity is not valid.
 */
void set_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t port_queue_capacity);

/**
 * @brief Set the SHM Transport Descriptor listening port liveliness timeout (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] healthy_check_timeout_ms Listening port liveliness timeout in milliseconds.
 *
 * @throw element_invalid Exception if the provided listening port liveliness timeout is not valid.
 */
void set_healthy_check_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint32_t healthy_check_timeout_ms);

/**
 * @brief Set the SHM Transport Descriptor path to the debug file (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] rtps_dump_file Path to the file where RTPS messsages will be stored for debugging purposes.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void set_rtps_dump_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& rtps_dump_file);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append an IP address to the whitelisted network interfaces collection.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] ip_address IP address to be included in the whitelist collection.
 *
 * @throw element_invalid Exception if the provided IP address is not valid.
 */
void push_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& ip_address);

/**
 * @brief Update IP address in the whitelisted network interfaces collection.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] ip_address IP address to be updated in the whitelist collection.
 * @param[in] index Collection element to be changed.
 *
 * @throw element_invalid Exception if the provided IP address is not valid.
 * @throw element_not_found Exception if the list does not contain any element in index position.
 */
void update_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& ip_address,
        int32_t index);

/**
 * @brief Append a listening port to the TCP Transport Descriptor collection (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] port Port to listen as server.
 *
 * @throw element_invalid Exception if the provided port is not valid.
 */
void push_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t port);

/**
 * @brief Update a listening port to the TCP Transport Descriptor collection (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] port Updated port to listen as server.
 * @param[in] index Collection element to be changed.
 *
 * @throw element_invalid Exception if the provided port is not valid.
 * @throw element_not_found Exception if the list does not contain any element in index position.
 */
void update_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        uint16_t port,
        int32_t index);

/**
 * @brief Append a TLS verification mode to the TCP Transport Descriptor mask (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_mode TLS verification mode to add into the mask.
 *
 * @throw element_invalid Exception if the provided TLS verification mode is not valid.
 */
void push_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_mode);

/**
 * @brief Update a TLS verification mode to the TCP Transport Descriptor mask (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_mode TLS verification mode to update in the mask.
 * @param[in] index Collection element to be changed.
 *
 * @throw element_invalid Exception if the provided TLS verification mode is not valid.
 * @throw element_not_found Exception if the list does not contain any element in index position.
 */
void update_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_mode,
        int32_t index);

/**
 * @brief Append TLS supported features to the TCP Transport Descriptor mask (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_options TLS supported feature to add into the mask.
 *
 * @throw element_invalid Exception if the provided TLS supported feature is not valid.
 */
void push_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_options);

/**
 * @brief Update a TLS supported feature to the TCP Transport Descriptor mask (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_options TLS supported feature to update in the mask.
 * @param[in] index Collection element to be changed.
 *
 * @throw element_invalid Exception if the provided TLS supported feature is not valid.
 * @throw element_not_found Exception if the list does not contain any element in index position.
 */
void update_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_options,
        int32_t index);

/**
 * @brief Append TLS verification path to the TCP Transport Descriptor (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_path TLS path to look for verification files.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 */
void push_tls_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_path);

/**
 * @brief Update a TLS verification path to the TCP Transport Descriptor (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_path TLS verification path to be updated in the list.
 * @param[in] index Collection element to be changed.
 *
 * @throw element_invalid Exception if the provided path is not valid.
 * @throw element_not_found Exception if the list does not contain any element in index position.
 */
void update_tls_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_path,
        int32_t index);

} // transport_descriptor
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_TRANSPORT_DESCRIPTOR_HPP_
