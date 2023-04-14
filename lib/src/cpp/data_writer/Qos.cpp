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

#include <fastdds_qos_profiles_manager/data_writer/Qos.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <common/qos/Durability.hpp>
#include <common/qos/Reliability.hpp>
#include <utils/TagsXMLManager.hpp>
#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {
namespace data_writer {
namespace qos {

/**
 * @brief Private common method for all the functions that belong to this namespace to obtain base node position.
 *
 * @param[in] manager utils::XMLManager to obtain the base node position in the XML document
 * @param[in] profile_id DataWriter profile identifier
 * @param[in] create_if_not_existent flag that enables the creation of the  element if it does not exist
 * @param[in] required_qos Required QoS TAG
 *
 * @throw ElementNotFound exception if expected node was not found and node creation was not required
 */
void initialize_namespace(
        utils::XMLManager& manager,
        const std::string& profile_id,
        const bool create_if_not_existent,
        const std::string& required_qos)
{
    // Iterate through required elements, and create them if not existent
    manager.get_node(utils::tag::PROFILES, create_if_not_existent);
    manager.get_node(utils::tag::DATA_WRITER, utils::tag::PROFILE_NAME, profile_id, create_if_not_existent);
    manager.get_node(utils::tag::QOS, create_if_not_existent);
    manager.get_node(required_qos, create_if_not_existent);
}

void set_durability_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::DURABILITY);

    // Set the value using commons
    common::qos::durability::set_kind(manager, kind);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_reliability_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::RELIABILITY);

    // Set the value using commons
    common::qos::reliability::set_kind(manager, kind);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_reliability_max_blocking_time_sec(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& sec)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::RELIABILITY);

    // Set the value using commons
    common::qos::reliability::set_max_blocking_time_sec(manager, sec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

void set_reliability_max_blocking_time_nanosec(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& nanosec)
{
    // Create XML manager and initialize the document
    utils::XMLManager manager(xml_file, true);

    // Obtain base node position
    initialize_namespace(manager, profile_id, true, utils::tag::RELIABILITY);

    // Set the value using commons
    common::qos::reliability::set_max_blocking_time_nanosec(manager, nanosec);

    // Validate new XML element and save it
    manager.validate_and_save_document();
}

} // qos
} // data_writer
} // qosprof
} // eprosima

