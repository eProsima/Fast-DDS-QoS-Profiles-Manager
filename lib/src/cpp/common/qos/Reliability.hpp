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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_RELIABILITY_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_RELIABILITY_HPP_

#include <string>

#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace qos {
namespace reliability {

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
 * @brief Save the given kind value in the reliability qos node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] kind reliability kind.
 */
void set_kind(
        utils::XMLManager& manager,
        const std::string& kind);

/**
 * @brief Save the given seconds in the reliability max_blocking_time qos node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] sec seconds to be set
 */
void set_max_blocking_time_sec(
        utils::XMLManager& manager,
        const std::string& sec);

/**
 * @brief Save the given nanoseconds in the reliability max_blocking_time qos node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] nanosec nanoseconds to be set
 */
void set_max_blocking_time_nanosec(
        utils::XMLManager& manager,
        const std::string& nanosec);

} // reliability
} // qos
} // common
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_RELIABILITY_HPP_
