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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_INITIAL_PEERS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_INITIAL_PEERS_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace initial_peers {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed. If empty, the complete list is printed.
 *
 * @return std::string XML section containing the Domain Participant specific builtin initial peers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers kind.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers kind.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_kind(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers port.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers port.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_port(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers physical
 *        port.
 *        TCP only.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers TCP physical port.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_physical_port(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers IP
 *        address.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers IP address.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_address(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers unique
 *        LAN ID.
 *        TCPv4 only.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers TCPv4 unique LAN ID.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_unique_lan_id(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific builtin initial peers WAN IPv4
 *        address.
 *        TCPv4 only.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific builtin initial peers TCPv4 WAN IP address.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_wan_address(
        const std::string& profile_id,
        const std::string& index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of builtin initial peerss in the Domain Participant.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of builtin initial peerss in the list.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the list
 *        has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant builtin initial peers.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be removed. If empty, the complete list is removed.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove specific Domain Participant builtin initial peers port.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_port(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove specific Domain Participant builtin initial peers physical port.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_physical_port(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove specific Domain Participant builtin initial peers IP address.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_address(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove specific Domain Participant builtin initial peers unique LAN ID.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_unique_lan_id(
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove specific Domain Participant builtin initial peers WAN IP address.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_wan_address(
        const std::string& profile_id,
        const std::string& index);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a builtin initial peers with specified kind or update the builtin initial peers kind.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] kind Initial peers kind.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_kind(
        const std::string& profile_id,
        const std::string& kind,
        const std::string& index);

/**
 * @brief Append a builtin initial peers with specified port or update the builtin initial peers port.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port Initial peers port.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_port(
        const std::string& profile_id,
        const std::string& port,
        const std::string& index);

/**
 * @brief Append a builtin initial peers with specified physical port or update the builtin initial peers physical port
 *        (TCP only).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] physical_port Initial peers TCP physical port.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_physical_port(
        const std::string& profile_id,
        const std::string& physical_port,
        const std::string& index);

/**
 * @brief Append a builtin initial peers with specified IP address or update the builtin initial peers IP address.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] address Initial peers IP address.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_address(
        const std::string& profile_id,
        const std::string& address,
        const std::string& index);

/**
 * @brief Append a builtin initial peers TCPv4 locator with specified unique LAN ID or update the builtin initial peers
 *        TCPv4 locator unique LAN ID.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] unique_lan_id Initial peers TCPv4 locator unique LAN ID.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator identifier is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_unique_lan_id(
        const std::string& profile_id,
        const std::string& unique_lan_id,
        const std::string& index);

/**
 * @brief Append a builtin initial peers TCPv4 locator with specified WAN address or update the builtin initial peers
 *        TCPv4 locator WAN address.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] wan_address Initial peers TCPv4 locator WAN address.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_wan_address(
        const std::string& profile_id,
        const std::string& wan_address,
        const std::string& index);

} // initial_peers
} // builtin
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_INITIAL_PEERS_HPP_
