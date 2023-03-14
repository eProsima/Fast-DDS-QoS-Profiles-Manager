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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DEFAULT_MULTICAST_LOCATORS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DEFAULT_MULTICAST_LOCATORS_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace default_multicast_locators {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant default multicast locator list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the specific Domain Participant default multicast locator list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        default multicast locator list element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string XML section containing the Domain Participant specific default multicast locator.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator kind.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator port.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator physical port.
 *        TCP only.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator TCP physical port.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator IP address.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator unique LAN ID.
 *        TCPv4 only.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator TCPv4 unique LAN ID.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific default multicast locator WAN IPv4 address.
 *        TCPv4 only.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific default multicast locator TCPv4 WAN IP address.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of default multicast locators in the Domain Participant.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of default multicast locators in the list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the list
 *        has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant default multicast locator list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant default multicast locator.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Remove specific Domain Participant default multicast locator port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Remove specific Domain Participant default multicast locator physical port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Remove specific Domain Participant default multicast locator IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Remove specific Domain Participant default multicast locator unique LAN ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Remove specific Domain Participant default multicast locator WAN IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be modified.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a default multicast locator with specified kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] kind Default multicast locator kind.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Update the default multicast locator kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] kind Default multicast locator kind.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind,
        int32_t index);

/**
 * @brief Append a default multicast locator with specified port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port Default multicast locator port.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port);

/**
 * @brief Update the default multicast locator port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port Default multicast locator port.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port,
        int32_t index);

/**
 * @brief Append a default multicast locator with specified physical port (TCP only).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] physical_port Default multicast locator TCP physical port.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& physical_port);

/**
 * @brief Update the default multicast locator physical port (TCP only).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] physical_port Default multicast locator TCP physical port.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& physical_port,
        int32_t index);

/**
 * @brief Append a default multicast locator with specified IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] address Default multicast locator IP address.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address);

/**
 * @brief Update the default multicast locator IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] address Default multicast locator IP address.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        int32_t index);

/**
 * @brief Append a default multicast TCPv4 locator with specified unique LAN ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] unique_lan_id Default multicast TCPv4 locator unique LAN ID.
 *
 * @throw ElementInvalid Exception if the provided identifier is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& unique_lan_id);

/**
 * @brief Update the default multicast TCPv4 locator unique LAN ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] unique_lan_id Default multicast TCPv4 locator unique LAN ID.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator identifier is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& unique_lan_id,
        int32_t index);

/**
 * @brief Append a default multicast TCPv4 locator with specified WAN address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] wan_address Default multicast TCPv4 locator WAN address.
 *
 * @throw ElementInvalid Exception if the provided IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& wan_address);

/**
 * @brief Update the default multicast TCPv4 locator WAN address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] wan_address Default multicast TCPv4 locator WAN address.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& wan_address,
        int32_t index);

} // default_multicast_locators
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DEFAULT_MULTICAST_LOCATORS_HPP_
