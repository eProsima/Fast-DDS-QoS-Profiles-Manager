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
 * @brief Initialize XML workspace
 *
 * @param xml_file Absolute/relative path to the XML file.
 * @param create_file bool create file if the flag is set
 *
 * @throw Error Exception if the workspace could not be initialized
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void initialize(
        const std::string& xml_file,
        const bool create_file);

/**
 * @brief Terminate XML workspace
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void terminate();

} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_HPP_
