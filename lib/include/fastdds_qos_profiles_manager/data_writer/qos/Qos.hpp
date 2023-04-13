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

#include <fastdds_qos_profiles_manager/fastdds_qos_profiles_manager_dll.h>

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
 * @brief Set the Data writer durability QoS kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Data writer profile identifier.
 * @param[in] kind Durability QoS kind value.
 *
 * @throw ElementInvalid Exception if the provided durability QoS kind value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_durability_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Set the Data writer reliability QoS kind.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Data writer profile identifier.
 * @param[in] kind Reliability QoS kind value.
 *
 * @throw ElementInvalid Exception if the provided reliability QoS kind value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind);

/**
 * @brief Save the Data writer reliability QoS durability as second value.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Data writer profile identifier.
 * @param[in] sec Reliability QoS duration second value to be set
 *
 * @throw ElementInvalid Exception if the provided reliability QoS duration second value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_max_blocking_time_sec(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& sec);

/**
 * @brief Save the Data writer reliability QoS durability as nanosecond value.
 *
 * @param[in] xml_file Absolute/relative path to the XML file.
 * @param[in] profile_id Data writer profile identifier.
 * @param[in] nanosec Reliability QoS duration nanosecond value to be set
 *
 * @throw ElementInvalid Exception if the provided reliability QoS duration nanosecond value is not valid.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_reliability_max_blocking_time_nanosec(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& nanosec);

} // qos
} // data_writer
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_QOS_QOS_HPP_
