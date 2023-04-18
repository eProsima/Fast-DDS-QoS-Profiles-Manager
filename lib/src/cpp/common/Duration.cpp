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

#include <common/Duration.hpp>

#include <string>

#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace duration {

void set_sec(
        utils::XMLManager& manager,
        const std::string& sec)
{
    // Obtain second node
    manager.move_to_node(utils::tag::SEC, true);

    // Set duration value to node
    manager.set_value_to_node(sec);
}

void set_nanosec(
        utils::XMLManager& manager,
        const std::string& nanosec)
{
    // Obtain nanosecond node
    manager.move_to_node(utils::tag::NANOSEC, true);

    // Set duration value to node
    manager.set_value_to_node(nanosec);
}

} // duration
} // common
} // qosprof
} // eprosima
