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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_ALLOCATIONS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_ALLOCATIONS_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace allocations {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant allocations configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the allocations configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        allocations configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant remote locators limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section with the remote locators limit configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        remote locators configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_remote_locators(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant remote unicast locators limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Remote unicast locators limit.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        remote unicast locators limit does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_remote_locators_max_unicast(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant remote multicast locators limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Remote multicast locators limit.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        remote multicast locators limit does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_remote_locators_max_multicast(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant total participants limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section with the total participants allocation configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        total participants configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_participants(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant initial participants (preallocated).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Initial number of preallocated participants.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        initial participants configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_participants_initial(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum number of participants allowed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum number of participants.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum participants configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_participants_maximum(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant number of allocated participants when the allocated
 *        memory is consumed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Increment of participants.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        increment participants configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_participants_increment(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant total readers limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section with the total readers allocation configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        total readers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_readers(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant initial readers (preallocated).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Initial number of preallocated readers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        initial readers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_readers_initial(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum number of readers allowed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum number of readers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum readers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_readers_maximum(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant number of allocated readers when the allocated memory is
 *        consumed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Increment of readers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        increment readers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_readers_increment(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant total writers limit.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section with the total writers allocation configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        total writers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_writers(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant initial writers (preallocated).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Initial number of preallocated writers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        initial writers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_writers_initial(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum number of writers allowed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum number of writers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum writers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_writers_maximum(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant number of allocated writers when the allocated memory is
 *        consumed.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Increment of writers.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        increment writers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_total_writers_increment(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum number of partitions.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum number of partitions allowed in the Domain Participant.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum number of partitions is not set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_partitions(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum size of user data message.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum allowed size for user data message in the Domain Participant.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum size is not set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_user_data(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant maximum number of properties.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Maximum allowed number of properties in the Domain Participant.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        maximum property number is not set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_max_properties(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant send buffers allocations configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section with the send buffers allocation configuration.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        send buffers configuration does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_send_buffers(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant initially preallocated send buffers.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Number of send buffers preallocated.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        send buffers preallocations are not set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_send_buffers_preallocated_number(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant send buffers dynamic flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Send buffers dynamic flag.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        send buffers configuration flag is not set.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_send_buffers_dynamic(
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove allocations configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& profile_id);

/**
 * @brief Remove remote locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_remote_locators(
        const std::string& profile_id);

/**
 * @brief Remove remote unicast locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_remote_locators_max_unicast(
        const std::string& profile_id);

/**
 * @brief Remove remote multicast locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_remote_locators_max_multicast(
        const std::string& profile_id);

/**
 * @brief Remove remote multicast locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_remote_locators_max_multicast(
        const std::string& profile_id);

/**
 * @brief Remove total participants limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_participants(
        const std::string& profile_id);

/**
 * @brief Remove initial participants (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_participants_initial(
        const std::string& profile_id);

/**
 * @brief Remove maximum number of participants allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_participants_maximum(
        const std::string& profile_id);

/**
 * @brief Remove participant increment configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_participants_increment(
        const std::string& profile_id);

/**
 * @brief Remove total readers limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_readers(
        const std::string& profile_id);

/**
 * @brief Remove initial readers (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_readers_initial(
        const std::string& profile_id);

/**
 * @brief Remove maximum number of readers allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_readers_maximum(
        const std::string& profile_id);

/**
 * @brief Remove readers increment configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_readers_increment(
        const std::string& profile_id);

/**
 * @brief Remove total writers limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_writers(
        const std::string& profile_id);

/**
 * @brief Remove initial writers (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_writers_initial(
        const std::string& profile_id);

/**
 * @brief Remove maximum number of writers allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_writers_maximum(
        const std::string& profile_id);

/**
 * @brief Remove writers increment configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_total_writers_increment(
        const std::string& profile_id);

/**
 * @brief Remove maximum number of partitions in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_partitions(
        const std::string& profile_id);

/**
 * @brief Remove maximum size of user data message in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_user_data(
        const std::string& profile_id);

/**
 * @brief Remove maximum number of properties in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_max_properties(
        const std::string& profile_id);

/**
 * @brief Remove send buffers allocations configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_send_buffers(
        const std::string& profile_id);

/**
 * @brief Remove initially preallocated send buffers configuration in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_send_buffers_preallocated_number(
        const std::string& profile_id);

/**
 * @brief Remove send buffers dynamic flag in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_send_buffers_preallocated_dynamic(
        const std::string& profile_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the remote unicast locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] max_unicast Maximum number of allowed remote unicast locators.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_remote_locators_max_unicast(
        const std::string& profile_id,
        const std::string& max_unicast);

/**
 * @brief Set the remote multicast locators limit in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] max_multicast Maximum number of allowed remote multicast locators.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_remote_locators_max_multicast(
        const std::string& profile_id,
        const std::string& max_multicast);

/**
 * @brief Set the initial participants (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] initial Initial number of preallocated participants.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_participants_initial(
        const std::string& profile_id,
        const std::string& initial);

/**
 * @brief Set the maximum number of participants allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] maximum Maximum number of participants.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_participants_maximum(
        const std::string& profile_id,
        const std::string& maximum);

/**
 * @brief Set the number of allocated participants when the allocated memory is consumed in the Domain Participant
 *        profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] increment Increment of participants.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_participants_increment(
        const std::string& profile_id,
        const std::string& increment);

/**
 * @brief Set the initial readers (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] initial Initial number of preallocated readers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_readers_initial(
        const std::string& profile_id,
        const std::string& initial);

/**
 * @brief Set the maximum number of readers allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] maximum Maximum number of readers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_readers_maximum(
        const std::string& profile_id,
        const std::string& maximum);

/**
 * @brief Set the number of allocated readers when the allocated memory is consumed in the Domain Participant
 *        profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] increment Increment of readers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_readers_increment(
        const std::string& profile_id,
        const std::string& increment);

/**
 * @brief Set the initial writers (preallocated) in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] initial Initial number of preallocated writers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_writers_initial(
        const std::string& profile_id,
        const std::string& initial);

/**
 * @brief Set the maximum number of writers allowed in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] maximum Maximum number of writers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_writers_maximum(
        const std::string& profile_id,
        const std::string& maximum);

/**
 * @brief Set the number of allocated writers when the allocated memory is consumed in the Domain Participant
 *        profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] increment Increment of writers.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_total_writers_increment(
        const std::string& profile_id,
        const std::string& increment);

/**
 * @brief Set the maximum number of partitions in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] max_partitions Maximum number of partitions allowed in the Domain Participant.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_partitions(
        const std::string& profile_id,
        const std::string& max_partitions);

/**
 * @brief Set the maximum size of user data message in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] max_user_data Maximum allowed size for user data message in the Domain Participant.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_user_data(
        const std::string& profile_id,
        const std::string& max_user_data);

/**
 * @brief Set the maximum number of properties in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] max_properties Maximum allowed number of properties in the Domain Participant.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_max_properties(
        const std::string& profile_id,
        const std::string& max_properties);

/**
 * @brief Set the initially preallocated send buffers in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] send_buffers_preallocated_number Number of send buffers preallocated.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_send_buffers_preallocated_number(
        const std::string& profile_id,
        const std::string& send_buffers_preallocated_number);

/**
 * @brief Set the send buffers dynamic flag in the Domain Participant profile.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] send_buffers_dynamic Send buffers dynamic flag.
 *
 * @throw ElementInvalid Exception if the provided value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_send_buffers_dynamic(
        const std::string& profile_id,
        const std::string& send_buffers_dynamic);

} // allocations
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_ALLOCATIONS_HPP_
