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

#include <fastdds_qos_profiles_manager_dll.h>

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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file);

/**
 * @brief Parse XML file and print specific transport descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string XML section containing the specific transport descriptor profile.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_kind(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor send buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor send buffer size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        send buffer size element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor receive buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor receive buffer size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        receive buffer size element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor maximum message size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor maximum message size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum message size element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific Transport Descriptor maximum initial peers range.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor maximum initial peers range.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum initial peers range element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_initial_peers_range(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        interface whitelist element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_interface_whitelist(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Transport Descriptor TTL (Time to live).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor TTL in number of hops.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TTL element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific UDP Transport Descriptor non blocking send flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Transport descriptor non blocking send flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        non blocking send flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific UDP Transport Descriptor output port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string UDP Transport descriptor output port.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        ouput port has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_output_port(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        WAN address has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_wan_addr(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific frequency of TCP Transport Descriptor keep alive requests.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Frequency of TCP keep alive requests (in milliseconds).
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        keep alive frequency has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific timeout (in milliseconds) to consider a TCP connection broken if no keep
 *        alive is received.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string TCP keep alive timeout (in milliseconds).
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        keep alive timeout has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific maximum number of logical ports to try during TCP negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Maximum number of logical ports to try during TCP negotiation.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum number of logical ports has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific maximum number of logical ports per request to try during TCP
 *        negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Maximum number of logical ports per request to try during TCP negotiation.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        maximum number of logical ports per request has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific increment between logical ports to try during TCP negotiation.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Increment between logical ports to try during TCP negotiation.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        logical port increment has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_logical_port_increment(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening ports element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the TCP Transport Descriptor specific listening port element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string TCP Transport descriptor specific listening port.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_listening_ports(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS configuration element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS password element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_password(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS private key certificate path element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_private_key_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS private key RSA certificate path element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_rsa_private_key_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS public certificate chain file path element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_cert_chain_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS Diffie-Hellman parameters file path element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_tmp_dh_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS CA file path element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify mode element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_mode(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_mode(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS options element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_options(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_options(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify paths element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_paths(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS maximum verification depth.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor maximum allowed depth for verifying intermediate certificates.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify depth element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TLS verify default paths flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor verify default paths flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify default paths flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_default_verify_path(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS handshake role has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_handshake_role(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS SNI server name has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_tls_server_name(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor calculate CRC flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor calculate CRC flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        calculate CRC flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor check CRC flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor check CRC flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        check CRC flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific TCP Transport Descriptor TCP_NODELAY socket option flag
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific TCP Transport Descriptor TCP_NODELAY socket option flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TCP_NODELAY socket option flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor shared memory segment size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific SHM Transport Descriptor shared memory segment size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        shared memory segment size has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor listening port capacity.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific SHM Transport Descriptor listening port capacity in number of messages.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening port capacity has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Parse XML file and print the specific SHM Transport Descriptor listening port liveliness timeout.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return std::string Specific SHM Transport Descriptor listening port liveliness timeout (in milliseconds).
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening port liveliness timeout has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_healthy_check_timeout_ms(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        debugging file path has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_rtps_dump_file(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& xml_file);

/**
 * @brief List of the identifiers for every transport descriptor profile in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return std::vector<std::string> Identifier list.
 *         Empty list if there are no transport descriptor profiles.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::vector<std::string> keys(
        const std::string& xml_file);

/**
 * @brief Number of whitelisted network interfaces in the Transport Descriptor list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @return uint32_t Number of network interfaces whitelisted in the list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        interface whitelist element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t interface_whitelist_size(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        listening ports element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t listening_ports_size(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify mode element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t tls_verify_mode_size(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS options element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t tls_options_size(
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
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or the
 *        TLS verify paths element has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t tls_verify_paths_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Delete any TransportDescriptor profile contained in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file);

/**
 * @brief Remove specific transport descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove send buffer size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove receive buffer size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum message size element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum initial peers range element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_initial_peers_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every whitelisted network interface from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific whitelisted network interface from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_interface_whitelist(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TTL (Time to live) element from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove non blocking send flag from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove output port from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_output_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove WAN address from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_wan_addr(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP keep alive frequency from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP keep alive timeout from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum number of logical ports from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove maximum number of logical ports per request from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove logical port increment element from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_logical_port_increment(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every listening port from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific listening port from specific Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TLS configuration from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS password from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_password(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS private key certificate path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS private key RSA certificate path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_rsa_private_key_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS public certificate chain file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_cert_chain_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS Diffie-Hellman parameters file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_tmp_dh_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS CA (Certification Authority) file path from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_file(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove every TLS verification mode from specific TCP Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS verification mode from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_mode(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove every TLS supported features from specific TCP Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS supported feature from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_options(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove every TLS verification paths from specific TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove specific TLS verification path from specific Transport Descriptor profile mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_paths(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        int32_t index);

/**
 * @brief Remove TLS maximum verification depth from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS verify default paths flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_default_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS handshake role from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_handshake_role(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TLS SNI server name from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_tls_server_name(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove calculate CRC flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove check CRC flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove TCP_NODELAY socket option flag from TCP Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory segment size from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory listening port capacity from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory listening port liveliness timeout from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_healthy_check_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id);

/**
 * @brief Remove shared memory debugging file path from SHM Transport Descriptor profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified transport descriptor profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_rtps_dump_file(
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
 * @throw ElementInvalid Exception if the provided kind is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_kind(
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
 * @throw ElementInvalid Exception if the provided send buffer size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_send_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& send_buffer_size);

/**
 * @brief Set the Transport Descriptor receive buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] receive_buffer_size Transport descriptor receive buffer size.
 *
 * @throw ElementInvalid Exception if the provided receive buffer size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_receive_buffer_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& receive_buffer_size);

/**
 * @brief Set the Transport Descriptor maximum message size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_message_size Transport descriptor maximum message size.
 *
 * @throw ElementInvalid Exception if the provided maximum message size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_message_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& max_message_size);

/**
 * @brief Set the Transport Descriptor maximum initial peers range.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_initial_peers_range Transport descriptor maximum initial peers range.
 *
 * @throw ElementInvalid Exception if the provided maximum initial peers range is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_initial_peers_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& max_initial_peers_range);

/**
 * @brief Set the Transport Descriptor TTL (Time to live).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] ttl Transport descriptor TTL (Time to live) in number of hops.
 *
 * @throw ElementInvalid Exception if the provided TTL is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_ttl(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& ttl);

/**
 * @brief Set the Transport Descriptor non blocking send flag (UDP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] non_blocking_send Enable/disable this flag in the Transport Descriptor.
 *
 * @throw ElementInvalid Exception if the flag does not apply to the Transport Descriptor.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_non_blocking_send(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& non_blocking_send);

/**
 * @brief Set the Transport Descriptor output port (UDP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] output_port UDP Transport output port.
 *
 * @throw ElementInvalid Exception if the output port provided is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_output_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& output_port);

/**
 * @brief Set the Transport Descriptor WAN address (TCPv4 Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] wan_addr TCPv4 Transport WAN address.
 *
 * @throw ElementInvalid Exception if the output port provided is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_wan_addr(
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
 * @throw ElementInvalid Exception if the provided keep alive frequency is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_keep_alive_frequency_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& keep_alive_frequency_ms);

/**
 * @brief Set the TCP Transport Descriptor timeout to consider a connection broken if no keep alive request is received
 *       in milliseconds (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] keep_alive_timeout_ms Time since the last keep alive request to consider the connection broken (in ms).
 *
 * @throw ElementInvalid Exception if the provided keep alive timeout is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_keep_alive_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& keep_alive_timeout_ms);

/**
 * @brief Set the TCP Transport Descriptor maximum number of logical ports to try during TCP negotiation (TCP Transport
 *        specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] max_logical_port Maximum number of logical ports to try during TCP negotiation.
 *
 * @throw ElementInvalid Exception if the provided maximum number of logical ports is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_logical_port(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& max_logical_port);

/**
 * @brief Set the TCP Transport Descriptor maximum number of logical ports per request to try during TCP negotiation
 *        (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] logical_port_range Maximum number of logical ports per request to try during TCP negotiation.
 *
 * @throw ElementInvalid Exception if the provided maximum number of logical ports per request is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_logical_port_range(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& logical_port_range);

/**
 * @brief Set the TCP Transport Descriptor increment between logical ports to try during TCP negotiation (TCP Transport
 *        specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] logical_port_increment Increment between logical ports to try during TCP negotiation.
 *
 * @throw ElementInvalid Exception if the provided maximum number of logical ports per request is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_logical_port_increment(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& logical_port_increment);

/**
 * @brief Set the TCP Transport Descriptor TLS password (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_password TCP Transport Descriptor TLS password.
 *
 * @throw ElementInvalid Exception if the provided TLS password is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_password(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_private_key_file(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_rsa_private_key_file(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_cert_chain_file(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_tmp_dh_file(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_verify_file(
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
 * @throw ElementInvalid Exception if the provided depth is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_verify_depth(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_depth);

/**
 * @brief Set the TCP Transport Descriptor TLS verify default paths flag (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_default_verify_path Flag that enables looking for verification files on the default paths.
 *
 * @throw ElementInvalid Exception if the provided flag value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_default_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_default_verify_path);

/**
 * @brief Set the TCP Transport Descriptor TLS handshake role (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_handshake_role Role that the Transport will take on handshaking.
 *
 * @throw ElementInvalid Exception if the provided handshake role is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_handshake_role(
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
 * @throw ElementInvalid Exception if the provided SNI server name is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_tls_server_name(
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
 * @throw ElementInvalid Exception if the provided CRC calculation flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_calculate_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& calculate_crc);

/**
 * @brief Set the TCP Transport Descriptor check CRC flag (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] check_crc Flag to enable CRC checking of incoming messages.
 *
 * @throw ElementInvalid Exception if the provided check CRC flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_check_crc(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& check_crc);

/**
 * @brief Enable the TCP Transport Descriptor TCP_NODELAY socket option (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] enable_tcp_nodelay Flag to enable TCP_NODELAY socket option.
 *
 * @throw ElementInvalid Exception if the TCP_NODELAY flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_enable_tcp_nodelay(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& enable_tcp_nodelay);

/**
 * @brief Set the SHM Transport Descriptor shared memory segment size (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] segment_size Shared memory segment size.
 *
 * @throw ElementInvalid Exception if the provided segment size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_segment_size(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& segment_size);

/**
 * @brief Set the SHM Transport Descriptor listening port capacity (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] port_queue_capacity Listening port capacity in number of messages.
 *
 * @throw ElementInvalid Exception if the provided listening port capacity is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_port_queue_capacity(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& port_queue_capacity);

/**
 * @brief Set the SHM Transport Descriptor listening port liveliness timeout (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] healthy_check_timeout_ms Listening port liveliness timeout in milliseconds.
 *
 * @throw ElementInvalid Exception if the provided listening port liveliness timeout is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_healthy_check_timeout_ms(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& healthy_check_timeout_ms);

/**
 * @brief Set the SHM Transport Descriptor path to the debug file (SHM Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] rtps_dump_file Path to the file where RTPS messsages will be stored for debugging purposes.
 *
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_rtps_dump_file(
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
 * @throw ElementInvalid Exception if the provided IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_interface_whitelist(
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
 * @throw ElementInvalid Exception if the provided IP address is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_interface_whitelist(
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
 * @throw ElementInvalid Exception if the provided port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& port);

/**
 * @brief Update a listening port to the TCP Transport Descriptor collection (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] port Updated port to listen as server.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided port is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_listening_ports(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& port,
        int32_t index);

/**
 * @brief Append a TLS verification mode to the TCP Transport Descriptor mask (TCP Transport specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] transport_descriptor_id Transport descriptor profile identifier.
 * @param[in] tls_verify_mode TLS verification mode to add into the mask.
 *
 * @throw ElementInvalid Exception if the provided TLS verification mode is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_tls_verify_mode(
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
 * @throw ElementInvalid Exception if the provided TLS verification mode is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_tls_verify_mode(
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
 * @throw ElementInvalid Exception if the provided TLS supported feature is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_tls_options(
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
 * @throw ElementInvalid Exception if the provided TLS supported feature is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_tls_options(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_tls_verify_path(
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
 * @throw ElementInvalid Exception if the provided path is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_tls_verify_path(
        const std::string& xml_file,
        const std::string& transport_descriptor_id,
        const std::string& tls_verify_path,
        int32_t index);

} // transport_descriptor
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_TRANSPORT_DESCRIPTOR_HPP_
