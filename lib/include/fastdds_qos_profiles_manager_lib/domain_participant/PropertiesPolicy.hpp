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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PROPERTIES_POLICY_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PROPERTIES_POLICY_HPP_

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace properties_policy {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant property in the policy list.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name to be printed. If empty, print the complete property policy list.
 *
 * @return std::string XML section containing the specific property.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property name is not found in the XML
 *        file or the properties policy element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& profile_id,
        const std::string& property_id);

/**
 * @brief Parse XML file and print specific Domain Participant property value in the policy list.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which value is printed.
 *
 * @return std::string Property value.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property name is not found in the XML
 *        file or the properties policy element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_value(
        const std::string& profile_id,
        const std::string& property_id);

/**
 * @brief Parse XML file and print specific Domain Participant property propagate attribute in the policy list.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which propagate attribute is printed.
 *
 * @return std::string Property propagate attribute.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property name is not found in the XML
 *        file or the properties policy element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_propagate(
        const std::string& profile_id,
        const std::string& property_id);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of properties defined in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of properties.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& profile_id);

/**
 * @brief List of the property names defined in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::vector<std::string> Identifier list.
 *         Empty list if there are no properties.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::vector<std::string> keys(
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific property in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name to be removed. If empty, every property is removed from the profile.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& profile_id,
        const std::string& property_id);

/**
 * @brief Remove specific property value in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which value is to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_value(
        const std::string& profile_id,
        const std::string& property_id);

/**
 * @brief Remove specific property propagate attribute in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which propagate attribute is to be removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile/Property is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_propagate(
        const std::string& profile_id,
        const std::string& property_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the property value in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which value is being set/updated.
 * @param[in] value New property value.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_value(
        const std::string& profile_id,
        const std::string& property_id,
        const std::string& value);

/**
 * @brief Set the property propagate attribute in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name which value is being set/updated.
 * @param[in] propagate New propagate value.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_propagate(
        const std::string& profile_id,
        const std::string& property_id,
        const std::string& propagate);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a new property with empty value to the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] property_id Property name.
 *
 * @throw ElementInvalid Exception if the provided property name is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void push(
        const std::string& profile_id,
        const std::string& property_id);

} // properties_policy
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PROPERTIES_POLICY_HPP_
