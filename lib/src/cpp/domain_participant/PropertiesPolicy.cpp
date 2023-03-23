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

#include <fastdds_qos_profiles_manager/domain_participant/PropertiesPolicy.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace properties_policy {

std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

std::string print_value(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

std::string print_propagate(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

uint32_t size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::vector<std::string> keys(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

void clear_value(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

void clear_propagate(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

void set_value(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id,
        const std::string& value)
{
    throw Unsupported("Unsupported");
}

void set_propagate(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id,
        const std::string& propagate)
{
    throw Unsupported("Unsupported");
}

void push(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& property_id)
{
    throw Unsupported("Unsupported");
}

} // properties_policy
} // domain_participant
} // qosprof
} // eprosima
