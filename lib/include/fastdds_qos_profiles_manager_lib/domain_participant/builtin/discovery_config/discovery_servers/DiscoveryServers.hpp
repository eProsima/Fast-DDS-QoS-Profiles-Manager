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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_SERVERS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_SERVERS_HPP_

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace discovery_config {
namespace discovery_servers {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/**
 * @brief Parse XML file and print specific Domain Participant builtin remote discovery server (Discovery Server
 *        specific).
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] prefix GUID prefix of the remote server to be printed. If empty, the complete list is printed.
 *
 * @return std::string Specific Domain Participant builtin remote discovery server.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or the
 *        builtin remote discovery servers list does not exist, or the list does not contain any element with the
 *        provided GUID prefix.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix);

/************************************************************************/
/* Query functions                                                      */
/************************************************************************/

/**
 * @brief Number of builtin remote discovery servers in the Domain Participant list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return uint32_t Number of builtin remote discovery servers.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or there
 *        are no remote discovery servers configured.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI uint32_t size(
        const std::string& xml_file,
        const std::string& profile_id);

/**
 * @brief List of the identifiers for every remote server included in the Domain Participant profile.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 *
 * @return std::vector<std::string> Identifier list.
 *         Empty list if there are no remote servers.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI std::vector<std::string> keys(
        const std::string& xml_file,
        const std::string& profile_id);

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/**
 * @brief Remove specific Domain Participant discovery remote server from the list.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Domain participant profile identifier.
 * @param[in] prefix GUID prefix of the remote server to be removed. If empty, the complete list is removed.
 *
 * @throw FileNotFound Exception if the provided XML file is not found/readable.
 * @throw ElementNotFound Exception if the specified Domain Participant profile is not found in the XML file or if the
 *        specified GUID prefix does not exist either.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix);

} // discovery_servers
} // discovery_config
} // builtin
} // domain_participant
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DOMAIN_PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DISCOVERY_SERVERS_HPP_
