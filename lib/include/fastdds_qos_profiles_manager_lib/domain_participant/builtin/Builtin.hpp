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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_BUILTIN_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_BUILTIN_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant builtin configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string XML section containing the specific Domain Participant builtin configuration.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin avoid_builtin_multicast flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific avoid_builtin_multicast flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_avoid_builtin_multicast(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin use writer liveliness protocol flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant specific use writer liveliness protocol flag.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin flag does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_use_writer_liveliness_protocol(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin DataReaders History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant builtin DataReaders History Memory Policy.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin History Memory Policy does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_reader_history_memory_policy(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin DataWriters History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant builtin DataWriters History Memory Policy.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin History Memory Policy does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_writer_history_memory_policy(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin DataReaders payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant builtin DataReaders payload size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin payload size element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_reader_payload_size(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin DataWriters payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant builtin DataWriters payload size.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        corresponding builtin payload size element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_writer_payload_size(
        const std::string& profile_id);

/**
 * @brief Parse XML file and print specific Domain Participant builtin number of physical ports to try if configured
 *        port is already in use (mutation tries).
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::string Domain Participant builtin mutation tries.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin mutation tries element does not exist.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print_mutation_tries(
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant builtin configuration.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin avoid_builtin_multicast flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_avoid_builtin_multicast(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin use writer liveliness protocol flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_use_writer_liveliness_protocol(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin DataReaders History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_reader_history_memory_policy(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin DataWriters History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_writer_history_memory_policy(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin DataReaders payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_reader_payload_size(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin DataWriters payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_witer_payload_size(
        const std::string& profile_id);

/**
 * @brief Remove specific Domain Participant builtin DataWriters mutation tries.
 *
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear_mutation_tries(
        const std::string& profile_id);

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the Domain Participant builtin avoid_builtin_multicast flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] avoid_builtin_multicast Builtin avoid_builtin_multicast flag.
 *
 * @throw ElementInvalid Exception if the provided flag value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_avoid_builtin_multicast(
        const std::string& profile_id,
        const std::string& avoid_builtin_multicast);

/**
 * @brief Set the Domain Participant builtin use writer liveliness protocol flag.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] use_writer_liveliness_protocol Builtin use writer liveliness protocol flag.
 *
 * @throw ElementInvalid Exception if the provided flag value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_use_writer_liveliness_protocol(
        const std::string& profile_id,
        const std::string& use_writer_liveliness_protocol);

/**
 * @brief Set the Domain Participant builtin DataReaders History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] reader_history_memory_policy Builtin DataReaders History Memory Policy.
 *
 * @throw ElementInvalid Exception if the provided Memory Policy value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reader_history_memory_policy(
        const std::string& profile_id,
        const std::string& reader_history_memory_policy);

/**
 * @brief Set the Domain Participant builtin DataWriters History Memory Policy.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] writer_history_memory_policy Builtin DataWriters History Memory Policy.
 *
 * @throw ElementInvalid Exception if the provided Memory Policy value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_writer_history_memory_policy(
        const std::string& profile_id,
        const std::string& writer_history_memory_policy);

/**
 * @brief Set the Domain Participant builtin DataReaders payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] reader_payload_size Builtin DataReaders payload size.
 *
 * @throw ElementInvalid Exception if the provided payload size value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reader_payload_size(
        const std::string& profile_id,
        const std::string& reader_payload_size);

/**
 * @brief Set the Domain Participant builtin DataWriters payload size.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] writer_payload_size Builtin DataWriters payload size.
 *
 * @throw ElementInvalid Exception if the provided payload size value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_writer_payload_size(
        const std::string& profile_id,
        const std::string& writer_payload_size);

/**
 * @brief Set the Domain Participant builtin mutation tries.
 *
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] mutation_tries Builtin mutation tries.
 *
 * @throw ElementInvalid Exception if the provided mutation tries value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_mutation_tries(
        const std::string& profile_id,
        const std::string& mutation_tries);

} // builtin
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_BUILTIN_HPP_
