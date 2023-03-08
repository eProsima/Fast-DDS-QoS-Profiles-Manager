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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace metatraffic_external_unicast_locators {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant metatraffic external unicast locator list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the specific Domain Participant metatraffic external unicast locator list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        metatraffic external unicast locator list element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string XML section containing the Domain Participant specific metatraffic external unicast locator.
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
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator kind.
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
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator port.
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
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator IP address.
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
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator
 *        externality.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator externality.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator cost.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator cost.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/**
 * @brief Parse XML file and print the specific Domain Participant specific metatraffic external unicast locator mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed.
 *
 * @return std::string Domain Participant specific metatraffic external unicast locator mask.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of metatraffic external unicast locators in the Domain Participant.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of metatraffic external unicast locators in the list.
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
 * @brief Remove specific Domain Participant metatraffic external unicast locator list.
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
 * @brief Remove specific Domain Participant metatraffic external unicast locator.
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
 * @brief Remove specific Domain Participant metatraffic external unicast locator port.
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
 * @brief Remove specific Domain Participant metatraffic external unicast locator IP address.
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

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a metatraffic external unicast locator with specified kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] kind Metatraffic unicast locator kind.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Update the metatraffic external unicast locator kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] kind Metatraffic unicast locator kind.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator kind is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind,
        int32_t index);

/**
 * @brief Append a metatraffic external unicast locator with specified port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port Metatraffic unicast locator port.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port);

/**
 * @brief Update the metatraffic external unicast locator port.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port Metatraffic unicast locator port.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator port is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port,
        int32_t index);

/**
 * @brief Append a metatraffic external unicast locator with specified IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] address Metatraffic unicast locator IP address.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address);

/**
 * @brief Update the metatraffic external unicast locator IP address.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] address Metatraffic unicast locator IP address.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator IP address is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        int32_t index);

/**
 * @brief Append a metatraffic external unicast locator with specified externality.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] externality Metatraffic unicast locator externality.
 *
 * @throw ElementInvalid Exception if the provided locator externality is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& externality);

/**
 * @brief Update the metatraffic external unicast locator externality.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] externality Metatraffic unicast locator externality.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator externality is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& externality,
        int32_t index);

/**
 * @brief Append a metatraffic external unicast locator with specified cost.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] cost Metatraffic unicast locator cost.
 *
 * @throw ElementInvalid Exception if the provided locator cost is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& cost);

/**
 * @brief Update the metatraffic external unicast locator cost.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] cost Metatraffic unicast locator cost.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator cost is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& cost,
        int32_t index);

/**
 * @brief Append a metatraffic external unicast locator with specified mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] mask Metatraffic unicast locator mask.
 *
 * @throw ElementInvalid Exception if the provided locator mask is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& mask);

/**
 * @brief Update the metatraffic external unicast locator mask.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] mask Metatraffic unicast locator mask.
 * @param[in] index Collection element to be changed.
 *
 * @throw ElementInvalid Exception if the provided locator mask is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        list does not contain any element in index position.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void update_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& mask,
        int32_t index);

} // metatraffic_external_unicast_locators
} // builtin
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_HPP_
