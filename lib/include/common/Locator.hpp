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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_dll.h>

#include <utils/ParseXML.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace locator {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific locator list.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 *
 * @return std::string XML section containing the specific locator list.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const xercesc::DOMElement& xml_node);

/**
 * @brief Parse XML file and print the specific locator.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string XML section containing the locator.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator kind.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator kind.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_kind(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator port.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator port.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_port(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator physical port.
 *        TCP only.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCP physical port.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_physical_port(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator IP address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator IP address.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_address(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator unique LAN ID.
 *        TCPv4 only.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCPv4 unique LAN ID.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_unique_lan_id(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Parse XML file and print the specific locator WAN IPv4 address.
 *        TCPv4 only.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCPv4 WAN IP address.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_wan_address(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of locators in the list.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 *
 * @return uint32_t Number of locators in the list.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const xercesc::DOMElement& xml_node);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific locator list.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const xercesc::DOMElement& xml_node);

/**
 * @brief Remove specific locator.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be removed.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Remove specific locator port.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_port(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Remove specific locator physical port.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_physical_port(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Remove specific locator IP address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_address(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Remove specific locator unique LAN ID.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_unique_lan_id(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/**
 * @brief Remove specific locator WAN IP address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_wan_address(
        const xercesc::DOMElement& xml_node,
        int32_t index);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a locator with specified kind.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] kind Locator kind.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_kind(
        const xercesc::DOMElement& xml_node,
        const std::string& kind);

/**
 * @brief Update the locator kind.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] kind Locator kind.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_kind(
        const xercesc::DOMElement& xml_node,
        const std::string& kind,
        int32_t index);

/**
 * @brief Append a locator with specified port.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] port Locator port.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_port(
        const xercesc::DOMElement& xml_node,
        const std::string& port);

/**
 * @brief Update the locator port.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] port Locator port.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_port(
        const xercesc::DOMElement& xml_node,
        const std::string& port,
        int32_t index);

/**
 * @brief Append a locator with specified physical port (TCP only).
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] physical_port Locator TCP physical port.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_physical_port(
        const xercesc::DOMElement& xml_node,
        const std::string& physical_port);

/**
 * @brief Update the locator physical port (TCP only).
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] physical_port Locator TCP physical port.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_physical_port(
        const xercesc::DOMElement& xml_node,
        const std::string& physical_port,
        int32_t index);

/**
 * @brief Append a locator with specified IP address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] address Locator IP address.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_address(
        const xercesc::DOMElement& xml_node,
        const std::string& address);

/**
 * @brief Update the locator IP address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] address Locator IP address.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_address(
        const xercesc::DOMElement& xml_node,
        const std::string& address,
        int32_t index);

/**
 * @brief Append a default unicast TCPv4 locator with specified unique LAN ID.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] unique_lan_id Default unicast TCPv4 locator unique LAN ID.
 *
 * @throw ElementInvalid Exception if the provided identifier is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_unique_lan_id(
        const xercesc::DOMElement& xml_node,
        const std::string& unique_lan_id);

/**
 * @brief Update the default unicast TCPv4 locator unique LAN ID.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] unique_lan_id Default unicast TCPv4 locator unique LAN ID.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator identifier is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_unique_lan_id(
        const xercesc::DOMElement& xml_node,
        const std::string& unique_lan_id,
        int32_t index);

/**
 * @brief Append a default unicast TCPv4 locator with specified WAN address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] wan_address Default unicast TCPv4 locator WAN address.
 *
 * @throw ElementInvalid Exception if the provided IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_wan_address(
        const xercesc::DOMElement& xml_node,
        const std::string& wan_address);

/**
 * @brief Update the default unicast TCPv4 locator WAN address.
 *
 * @param[in] xml_node Node of the given XML file where the element is located
 * @param[in] wan_address Default unicast TCPv4 locator WAN address.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_wan_address(
        const xercesc::DOMElement& xml_node,
        const std::string& wan_address,
        int32_t index);

} // locators
} // common
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_HPP_
