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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_QOS_QOS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_QOS_QOS_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace data_writer {
namespace qos {

/************************************************************************/
/* Print functions                                                      */
/************************************************************************/

/************************************************************************/
/* Clear functions                                                      */
/************************************************************************/

/************************************************************************/
/* Set functions                                                        */
/************************************************************************/

/**
 * @brief Set the DataWriter durability QoS kind.
 *
 * @param[in] profile_id DataWriter profile identifier.
 * @param[in] kind Durability QoS kind value.
 *
 * @throw ElementInvalid Exception if the provided durability QoS kind value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_durability_kind(
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Set the DataWriter reliability QoS kind.
 *
 * @param[in] profile_id DataWriter profile identifier.
 * @param[in] kind Reliability QoS kind value.
 *
 * @throw ElementInvalid Exception if the provided reliability QoS kind value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_kind(
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Set the DataWriter reliability QoS max blocking time seconds.
 *
 * @param[in] profile_id DataWriter profile identifier.
 * @param[in] sec Reliability QoS max blocking time seconds to be set
 *
 * @throw ElementInvalid Exception if the provided reliability QoS max blocking time seconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_max_blocking_time_sec(
        const std::string& profile_id,
        const std::string& sec);

/**
 * @brief Set the DataWriter reliability QoS max blocking time nanoseconds.
 *
 * @param[in] profile_id DataWriter profile identifier.
 * @param[in] nanosec Reliability QoS max blocking time nanoseconds to be set
 *
 * @throw ElementInvalid Exception if the provided reliability QoS max blocking time nanoseconds are not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_max_blocking_time_nanosec(
        const std::string& profile_id,
        const std::string& nanosec);

} // qos
} // data_writer
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_QOS_QOS_HPP_
