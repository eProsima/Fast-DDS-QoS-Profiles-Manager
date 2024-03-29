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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_lib/fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {
namespace data_writer {

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
 * @brief Set the selected DataWriter profile as default profile.
 *        As only one default profile is allowed, if another default profile exists, it is overridden and its
 *        is_default_profile attribute is set to false.
 *
 * @param[in] profile_id DataWriter profile identifier.
 *
 * @throw Error Exception if the workspace was not initialized.
 * @throw ElementNotFound Exception if the specified profile is not found in the XML file.
 */
FASTDDS_QOS_PROFILES_MANAGER_DllAPI void set_default_profile(
        const std::string& profile_id);

} // data_writer
} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DATA_WRITER_HPP_
