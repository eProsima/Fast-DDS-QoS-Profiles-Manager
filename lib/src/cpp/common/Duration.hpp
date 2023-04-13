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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_DURATION_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_DURATION_HPP_

#include <string>

#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace duration {

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
 * @brief Save the given seconds value in the duration type node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] sec seconds value to be set
 */
void set_sec(
        utils::XMLManager& manager,
        const std::string& sec);

/**
 * @brief Save the given nanosecond value in the duration type node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] nanosec nanosecond value to be set
 */
void set_nanosec(
        utils::XMLManager& manager,
        const std::string& nanosec);

} // duration
} // common
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_DURATION_HPP_
