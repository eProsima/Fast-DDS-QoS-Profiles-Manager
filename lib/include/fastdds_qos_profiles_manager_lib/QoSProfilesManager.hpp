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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_HPP_

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

#include <string>

namespace eprosima {
namespace qosprof {

/**
 * @brief Initialize eProsima QoS Profiles Manager Library XML workspace. This workspace gets related to the given
 *  XML file, and all the Library API calls would be related to that XML file.
 *
 * @param xml_file Absolute/relative path to the XML file.
 *
 * @throw Error Exception if the workspace could not be initialized, or it was already initialized.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void initialize(
        const std::string& xml_file);

/**
 * @brief Terminate the initialized eProsima QoS Profiles Manager Library XML workspace. This function must be called
 *  before initializing a new workspace. If changes required to be applied in the XML configuration file, this method
 *  would also apply them in filesystem. If error occurred or resultant XML configuration is not valid, the XML
 *  configuration will not be modified.
 *
 * @throw Error Exception if the XML file could not be written in filesystem
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void terminate();

} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_HPP_
