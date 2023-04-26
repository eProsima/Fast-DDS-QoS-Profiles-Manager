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

#include <fastdds_qos_profiles_manager_lib/QoSProfilesManager.hpp>

#include <string>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

#include <utils/XMLManager.hpp>

namespace eprosima {
namespace qosprof {

void initialize(
        const std::string& xml_file,
        const bool create_file)
{
    // Try to initialize XML workspace
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw Error(xercesc::XMLString::transcode(toCatch.getMessage()));
    }

    // Get singleton instance of manager
    eprosima::qosprof::utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // Set up with the basic information
    manager.initialize(xml_file, create_file);
}

void terminate()
{
    // Create singleton instance of manager
    eprosima::qosprof::utils::XMLManager& manager = eprosima::qosprof::utils::XMLManager::get_instance();

    // write if needed the final XML in the given path
    manager.save_xml();

    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();
}

} // qosprof
} // eprosima
