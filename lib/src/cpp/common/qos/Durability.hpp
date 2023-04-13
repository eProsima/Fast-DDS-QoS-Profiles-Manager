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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_DURABILITY_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_DURABILITY_HPP_

#include <string>

#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace qos {
namespace durability {

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
 * @brief Save the given kind value in the durability qos node.
 *
 * @param[in] manager Internal util manager to obtain and work with nodes
 * @param[in] kind durability kind.
 */
void set_kind(
        utils::XMLManager& manager,
        const std::string& kind);


} // durability
} // qos
} // common
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_QOS_DURABILITY_HPP_
