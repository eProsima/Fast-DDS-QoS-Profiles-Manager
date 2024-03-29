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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_CONFIG_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_CONFIG_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace discovery_config {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery configuration section.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the specific Domain Participant builtin discovery configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery configuration section does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery protocol.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery protocol.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery protocol element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_discovery_protocol(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery ignore participant flags.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery ignore participant flags.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_ignore_participant_flags(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery EDP flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery EDP flag.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_edp(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery simple EDP configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery simple EDP configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery simple EDP configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_simple_edp(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery simple EDP pubwriter_subreader flag configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery simple EDP configuration flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_simple_edp_pubwriter_subreader(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery simple EDP pubreader_subwriter flag configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery simple EDP configuration flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_simple_edp_pubreader_subwriter(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease duration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease duration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease duration element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_duration(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease duration (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease duration (seconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease duration seconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_duration_sec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease duration (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease duration (nanoseconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease duration nanoseconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_duration_nanosec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease announcement.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease announcement.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease announcement element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_announcement(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease announcement (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease announcement (seconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease announcement seconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_announcement_sec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease announcement (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease announcement (nanoseconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease announcement nanoseconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_lease_announcement_nanosec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery initial announcements configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery initial announcements configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery initial announcements element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_initial_announcements(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery number of initial announcements.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery number of initial announcements.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery initial announcements count element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_initial_announcements_count(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery initial announcements duration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery initial announcements duration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery initial announcements duration element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_initial_announcements_period(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery initial announcement duration
 *        (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery initial announcement duration (seconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery initial announcement duration seconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_initial_announcements_period_sec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery lease announcement duration
 *        (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery lease announcement duration (nanoseconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery lease announcement duration nanoseconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_initial_announcements_period_nanosec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery client announcement period.
 *        Discovery Server configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery client announcement period.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery client announcement period element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_client_announcement_period(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery client announcement period (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery client announcement period (seconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery client announcement period seconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_client_announcement_period_sec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery client announcement period
 *        (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific builtin discovery client announcement period (nanoseconds member).
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin discovery client announcement period nanoseconds element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_client_announcement_period_nanosec(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin discovery specific Static EDP XML configuration
 *        file.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed. If empty, the complete collection is printed.
 *
 * @return std::string Domain Participant specific builtin discovery specific Static EDP XML configuration file.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        Static EDP XML configuration files element is not defined, or the list does not contain any element in index
 *        position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& index);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of builtin discovery Static EDP XML configuration files in the Domain Participant.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of builtin discovery Static EDP XML configuration files.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or there
 *        are no Static EDP XML files configured.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t static_edp_xml_config_size(
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant builtin discovery configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery protocol.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_discovery_protocol(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery ignore participant flags.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_ignore_participant_flags(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery EDP flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_edp(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery simple EDP configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_simple_edp(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_simple_edp_pubwriter_subreader(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_simple_edp_edp_pubreader_subwriter(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease duration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_duration(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease duration (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_duration_sec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease duration (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_duration_nanosec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease announcement.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_announcement(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease announcement (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_announcement_sec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery lease announcement (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_lease_announcement_nanosec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery initial announcements configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_initial_announcements(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery number of initial announcements.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_initial_announcements_count(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery initial announcements duration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_initial_announcements_period(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery initial announcements duration (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_initial_announcements_period_sec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery initial announcements duration (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_initial_announcements_period_nanosec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery client announcement period (Discovery Server specific).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_client_announcement_period(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery client announcement period (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_client_announcement_period_sec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery client announcement period (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_client_announcement_period_nanosec(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin discovery specific Static EDP XML configuration file.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be removed. If empty, the complete collection is erased.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection if an index is provided..
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& index);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the Domain Participant builtin discovery protocol.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] discovery_protocol Builtin discovery protocol.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided discovery protocol is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_discovery_protocol(
        const std::string& profile_id,
        const std::string& discovery_protocol);

/**
 * @brief Set the Domain Participant builtin discovery ignore participant flags.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] ignore_participant_flags Builtin discovery ignore participant flags.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_ignore_participant_flags(
        const std::string& profile_id,
        const std::string& ignore_participant_flags);

/**
 * @brief Set the Domain Participant builtin discovery EDP flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] edp Builtin discovery EDP flag.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_edp(
        const std::string& profile_id,
        const std::string& edp);

/**
 * @brief Set the Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] simple_edp_pubwriter_subreader Builtin discovery simple EDP configuration flag.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_simple_edp_pubwriter_subreader(
        const std::string& profile_id,
        const std::string& simple_edp_pubwriter_subreader);

/**
 * @brief Set the Domain Participant builtin discovery simple EDP configuration flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] simple_edp_pubreader_subwriter Builtin discovery simple EDP configuration flag.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided flag is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_simple_edp_pubreader_subwriter(
        const std::string& profile_id,
        const std::string& simple_edp_pubreader_subwriter);

/**
 * @brief Set the Domain Participant builtin discovery lease duration (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] duration_sec Builtin discovery lease duration seconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided seconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_lease_duration_sec(
        const std::string& profile_id,
        const std::string& duration_sec);

/**
 * @brief Set the Domain Participant builtin discovery lease duration (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] duration_nanosec Builtin discovery lease duration nanoseconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided nanoseconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_lease_duration_nanosec(
        const std::string& profile_id,
        const std::string& duration_nanosec);

/**
 * @brief Set the Domain Participant builtin discovery lease announcement (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] announcement_sec Builtin discovery lease announcement seconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided seconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_lease_announcement_sec(
        const std::string& profile_id,
        const std::string& announcement_sec);

/**
 * @brief Set the Domain Participant builtin discovery lease announcement (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] announcement_nanosec Builtin discovery lease announcement nanoseconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided nanoseconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_lease_announcement_nanosec(
        const std::string& profile_id,
        const std::string& announcement_nanosec);

/**
 * @brief Set the Domain Participant builtin discovery number of initial announcements.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] count Builtin discovery number of initial announcements.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided number of initial announcements is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_initial_announcements_count(
        const std::string& profile_id,
        const std::string& count);

/**
 * @brief Set the Domain Participant builtin discovery initial announcements duration (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] period_sec Builtin discovery initial announcements duration seconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided seconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_initial_announcements_period_sec(
        const std::string& profile_id,
        const std::string& period_sec);

/**
 * @brief Set the Domain Participant builtin discovery initial announcements duration (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] period_nanosec Builtin discovery initial announcements duration nanoseconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided nanoseconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_initial_announcements_period_nanosec(
        const std::string& profile_id,
        const std::string& period_nanosec);

/**
 * @brief Set the Domain Participant builtin discovery client announcement period (seconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] period_sec Builtin discovery client announcement period seconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided seconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_client_announcement_period_sec(
        const std::string& profile_id,
        const std::string& period_sec);

/**
 * @brief Set the Domain Participant builtin discovery client announcement period (nanoseconds).
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] period_nanosec Builtin discovery client announcement period nanoseconds.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementInvalid Exception if the provided nanoseconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_client_announcement_period_nanosec(
        const std::string& profile_id,
        const std::string& period_nanosec);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a builtin discovery Static EDP XML configuration file or update a builtin discovery Static EDP XML
 *        configuration file.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] static_edp_xml_config Builtin discovery Static EDP XML configuration file.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided path is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw Error Exception if the workspace was not initialized.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_static_edp_xml_config(
        const std::string& profile_id,
        const std::string& static_edp_xml_config,
        const std::string& index);

} // discovery_config
} // builtin
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_CONFIG_HPP_
