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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_LIST_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_LIST_HPP_

#include <string>

#include <xercesc/dom/DOM.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace locator_list {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML node and print the locator.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed. If empty, the complete list is printed.
 *
 * @return std::string XML section containing the locator.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
std::string print(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator kind.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator kind.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_kind(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator port.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator port.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_port(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator physical port.
 *        TCP only.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCP physical port.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_physical_port(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator IP address.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator IP address.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_address(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator unique LAN ID.
 *        TCPv4 only.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCPv4 unique LAN ID.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_unique_lan_id(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Parse XML node and print the locator WAN IPv4 address.
 *        TCPv4 only.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string locator TCPv4 WAN IP address.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
std::string print_wan_address(
        const xercesc::DOMElement& xml_node,
        const std::string& index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of locators defined.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 *
 * @return uint32_t Number of locators in the list.
 *
 * @throw ElementNotFound Exception if the list has not been set.
 */
uint32_t size(
        const xercesc::DOMElement& xml_node);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove locator or complete locator list. If no index provided (empty string), the complete
 *       locator list would be removed. If provided, then the corresponding locator would be removed.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be removed. If empty, the complete list is removed.
 *
 * @throw ElementNotFound Exception if the element does not exist in the collection if an index is
 *        provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void clear(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Remove locator port.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
void clear_port(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Remove locator physical port.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
void clear_physical_port(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Remove locator IP address.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
void clear_address(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Remove locator unique LAN ID.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
void clear_unique_lan_id(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/**
 * @brief Remove locator WAN IP address.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] index Collection element to be modified.
 *
 * @throw ElementNotFound Exception if the list element does not exist, or the list does not contain
 *        any element in index position.
 * @throw BadParameter Exception if the index is empty or not an integer.
 */
void clear_wan_address(
        xercesc::DOMElement& xml_node,
        const std::string& index);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a locator with specified kind or update the existing locator kind.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] kind locator kind.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_kind(
        xercesc::DOMElement& xml_node,
        const std::string& kind,
        const std::string& index);

/**
 * @brief Append a locator with specified port or update the existing locator port.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] port locator port.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_port(
        xercesc::DOMElement& xml_node,
        const std::string& port,
        const std::string& index);

/**
 * @brief Append a locator with specified physical port or update the existing locator physical port
 *        (TCP only).
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] physical_port locator TCP physical port.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator physical port is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_physical_port(
        xercesc::DOMElement& xml_node,
        const std::string& physical_port,
        const std::string& index);

/**
 * @brief Append a locator with specified IP address or update the existing locator IP address.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] address locator IP address.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_address(
        xercesc::DOMElement& xml_node,
        const std::string& address,
        const std::string& index);

/**
 * @brief Append a TCPv4 locator with specified unique LAN ID or update the existing locator unique
 *        LAN ID.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] unique_lan_id TCPv4 locator unique LAN ID.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator identifier is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_unique_lan_id(
        xercesc::DOMElement& xml_node,
        const std::string& unique_lan_id,
        const std::string& index);

/**
 * @brief Append a TCPv4 locator with specified WAN address or update the existing locator WAN address.
 *
 * @param[in] xml_node Locator list node where all locators are uploaded.
 * @param[in] wan_address TCPv4 locator WAN address.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if index provided and the collection element is not found,
 *        or if the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
void set_wan_address(
        xercesc::DOMElement& xml_node,
        const std::string& wan_address,
        const std::string& index);

} // locator_list
} // common
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_LOCATOR_LIST_HPP_
