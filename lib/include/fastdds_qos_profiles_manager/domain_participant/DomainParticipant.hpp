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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DOMAIN_PARTICIPANT_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DOMAIN_PARTICIPANT_HPP_

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier. If empty every Domain Participant profile is printed.
 *
 * @return std::string XML section containing the specific Domain Participant profile.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the name of the Domain Participant default profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return std::string Domain Participant default profile.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if there is no default Domain Participant profile in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_default_profile(
        const std::string& xml_file);

/**
 * @brief Parse XML file and print the Domain Participant Domain ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant Domain ID.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        Domain ID has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_domain_id(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant name.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant name.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        name has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant ignore non matching locators flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant ignore non matching locators flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        ignore non matching locators flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant send socket buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant send socket buffer size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        send socket buffer size has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant listen socket buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant listen socket buffer size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        listen socket buffer size has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant ID.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        Domain Participant ID has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_participant_id(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant specific user transport element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed. If empty, the complete collection is printed.
 *
 * @return std::string Domain Participant specific user transport.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the Domain Participant use builtin trasports flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant use builtin trasports flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        use builtin trasports flag has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Parse XML file and print the Domain Participant specific user data element.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be printed. If empty, the complete collection is printed.
 *
 * @return std::string Domain Participant specific user data.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        list does not contain any element in index position.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Parse XML file and print the Domain Participant GUID prefix.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant GUID prefix.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        GUID prefix has not been set in the profile.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_prefix(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of Domain Participant profiles contained in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return uint32_t Number of Domain Participant profiles in the XML file.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& xml_file);

/**
 * @brief List of the identifiers for every Domain Participant profile in the XML file.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @return std::vector<std::string> Identifier list.
 *         Empty list if there are no Domain Participant profiles.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::vector<std::string> keys(
        const std::string& xml_file);

/**
 * @brief Number of user transports in the Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of user transports in the list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t user_transports_size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Number of user data elements in the Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of user data elements in the list.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t user_data_size(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier. If empty, every Domain Participant profile is deleted.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove the is_default_profile attribute from the default Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_default_profile(
        const std::string& xml_file);

/**
 * @brief Remove Domain ID from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_domain_id(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove Domain Participant name from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_name(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove ignore non matching locators flag from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove send socket buffer size from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove listen socket buffer size from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove Domain Participant ID from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_participant_id(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific user transport from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be removed. If empty, the complete collection is erased.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove use builtin transports flag from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Remove specific user data from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] index Collection element to be removed. If empty, the complete collection is erased.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if
 *        the element does not exist in the collection if an index is provided.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index);

/**
 * @brief Remove GUID prefix from specific Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_prefix(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the given Domain Participant profile as the default profile.
 *        As only one default profile is allowed, if another default profile exists, it is overriden and the
 *        is_default_profile attribute is removed.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_default_profile(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief Set the Domain Participant domain ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] domain_id Domain Participant domain ID.
 *
 * @throw ElementInvalid Exception if the provided domain ID is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_domain_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& domain_id);

/**
 * @brief Set the Domain Participant name.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] name Domain Participant name.
 *
 * @throw ElementInvalid Exception if the provided name is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_name(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& name);

/**
 * @brief Set the Domain Participant ignore non matching locators flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] ignore_non_matching_locators Ignore non matching locators flag.
 *
 * @throw ElementInvalid Exception if the provided flag value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& ignore_non_matching_locators);

/**
 * @brief Set the Domain Participant send socket buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] send_socket_buffer_size Size of the buffer in the socket used for sending data.
 *
 * @throw ElementInvalid Exception if the provided size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& send_socket_buffer_size);

/**
 * @brief Set the Domain Participant listen socket buffer size.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] listen_socket_buffer_size Size of the buffer in the socket used for listening data.
 *
 * @throw ElementInvalid Exception if the provided size is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& listen_socket_buffer_size);

/**
 * @brief Set the Domain Participant ID.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] participant_id Domain Participant ID.
 *
 * @throw ElementInvalid Exception if the provided ID is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_participant_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& participant_id);

/**
 * @brief Set the Domain Participant use builtin transports flag.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] use_builtin_transports Use builtin transports flag.
 *
 * @throw ElementInvalid Exception if the provided flag value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& use_builtin_transports);

/**
 * @brief Set the Domain Participant GUID prefix.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] prefix Domain Participant GUID prefix.
 *
 * @throw ElementInvalid Exception if the provided GUID prefix is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_prefix(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix);

/************************************************************************/
/* Collection functions                                                 */
/************************************************************************/

/**
 * @brief Append a user transport to the collection or update user transport element in the collection.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] transport_id Transport descriptor profile identifier.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided Transport descriptor profile identifier is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        const std::string& index);

/**
 * @brief Append user data or update specific user data.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] user_data User data to be updated.
 * @param[in] index Collection element to be changed. If empty, a new element is added to the list.
 *
 * @throw ElementInvalid Exception if the provided user data is not valid.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file, the list
 *        element does not exist, or the list does not contain any element in index position.
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw BadParameter Exception if the index is not an integer.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        const std::string& index);

} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_DOMAIN_PARTICIPANT_HPP_
