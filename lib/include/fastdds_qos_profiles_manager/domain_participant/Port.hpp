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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PORT_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PORT_HPP_

#include <string>

#include <fastdds_qos_profiles_manager/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace port {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant port parameters configuration.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the port parameters configuration.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        port parameters configuration element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant base port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Base port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        base port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_base(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant domain ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain ID gain port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        domain ID gain port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_domain_id_gain(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant participant ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Participant ID gain port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        participant ID gain port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_participant_id_gain(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant multicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Multicast metadata offset port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        multicast metadata offset port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_offset_d0(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant unicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Unicast metadata offset port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        unicast metadata offset port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_offset_d1(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant multicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Multicast user data offset port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        multicast user data offset port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_offset_d2(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant unicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Unicast user data offset port parameter.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        user data metadata offset port parameter has not been set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_offset_d3(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant port parameters configuration.
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
 * @brief Remove specific Domain Participant base port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_base(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant domain ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_domain_id_gain(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant participant ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_participant_id_gain(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant multicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_offset_d0(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant unicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_offset_d1(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant multicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_offset_d2(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant unicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_offset_d3(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the Domain Participant base port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] port_base Base port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_base(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port_base);

/**
 * @brief Set the Domain Participant domain ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] domain_id_gain Domain ID gain port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_domain_id_gain(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& domain_id_gain);

/**
 * @brief Set the Domain Participant participant ID gain port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] participant_id_gain Participant ID gain port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_participant_id_gain(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& participant_id_gain);

/**
 * @brief Set the Domain Participant multicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] offset_d0 Multicast metadata offset port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_offset_d0(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& offset_d0);

/**
 * @brief Set the Domain Participant unicast metadata offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] offset_d1 Unicast metadata offset port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_offset_d1(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& offset_d1);

/**
 * @brief Set the Domain Participant multicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] offset_d2 Multicast user data offset port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_offset_d2(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& offset_d2);

/**
 * @brief Set the Domain Participant unicast user data offset port parameter.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] offset_d3 Unicast user data offset port parameter.
 *
 * @throw ElementInvalid Exception if the provided parameter value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_offset_d3(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& offset_d3);

} // port
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_PORT_HPP_
