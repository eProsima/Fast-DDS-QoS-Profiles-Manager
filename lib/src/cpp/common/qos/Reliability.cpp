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

#include <common/qos/Reliability.hpp>

#include <string>

#include <common/Duration.hpp>
#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace qos {
namespace reliability {

void set_kind(
        utils::XMLManager& manager,
        const std::string& kind)
{
    // Obtain kind node
    manager.move_to_node(utils::tag::KIND, true);

    // Set value to node
    manager.set_value_to_node(kind);
}

void set_max_blocking_time_sec(
        utils::XMLManager& manager,
        const std::string& sec)
{
    // Obtain max blocking time node
    manager.move_to_node(utils::tag::MAX_BLOCKING_TIME, true);

    // Use the common api
    common::duration::set_sec(manager, sec);
}

void set_max_blocking_time_nanosec(
        utils::XMLManager& manager,
        const std::string& nanosec)
{
    // Obtain max blocking time node
    manager.move_to_node(utils::tag::MAX_BLOCKING_TIME, true);

    // Use the common api
    common::duration::set_nanosec(manager, nanosec);
}

} // reliability
} // qos
} // common
} // qosprof
} // eprosima
