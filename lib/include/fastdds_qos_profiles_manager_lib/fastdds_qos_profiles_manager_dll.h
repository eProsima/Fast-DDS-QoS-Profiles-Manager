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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_DLL_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_DLL_HPP_

#include <fastdds_qos_profiles_manager_lib/config.h>

// normalize macros
#if !defined(FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK) && !defined(FASTDDS_QOS_PROFILES_MANAGER_STATIC_LINK) \
    && !defined(EPROSIMA_ALL_DYN_LINK) && !defined(EPROSIMA_ALL_STATIC_LINK)
#define FASTDDS_QOS_PROFILES_MANAGER_STATIC_LINK
#endif // STATIC LINK CHECKS

#if defined(EPROSIMA_ALL_DYN_LINK) && !defined(FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK)
#define FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK
#endif // DYNAMIC LINK CHECKS

#if defined(FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK) && defined(FASTDDS_QOS_PROFILES_MANAGER_STATIC_LINK)
#error Must not define both FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK and FASTDDS_QOS_PROFILES_MANAGER_STATIC_LINK
#endif // DYNAMIC AND STATIC SANITY CHECK

#if defined(EPROSIMA_ALL_NO_LIB) && !defined(FASTDDS_QOS_PROFILES_MANAGER_NO_LIB)
#define FASTDDS_QOS_PROFILES_MANAGER_NO_LIB
#endif // NO_LIB CHECK

// enable dynamic linking

#if defined(_WIN32)
#if defined(EPROSIMA_ALL_DYN_LINK) || defined(FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK)
#if defined(FASTDDS_QOS_PROFILES_MANAGER_SOURCE)
#define FASTDDS_QOS_PROFILES_MANAGER_DllAPI __declspec( dllexport )
#else
#define FASTDDS_QOS_PROFILES_MANAGER_DllAPI __declspec( dllimport )
#endif // FASTDDS_QOS_PROFILES_MANAGER_SOURCE
#else
#define FASTDDS_QOS_PROFILES_MANAGER_DllAPI
#endif // DYNAMIC LINK
#else
#define FASTDDS_QOS_PROFILES_MANAGER_DllAPI
#endif // _WIN32

// enabling user dynamic linking
#if defined(_WIN32) && defined(FASTDDS_QOS_PROFILES_MANAGER_USER_DLL_EXPORT)
  #define FASTDDS_QOS_PROFILES_MANAGER_USERDllExport __declspec(dllexport)
#else
  #define FASTDDS_QOS_PROFILES_MANAGER_USERDllExport
#endif // USER_DLL_EXPORT

// Auto linking.

#if !defined(FASTDDS_QOS_PROFILES_MANAGER_SOURCE) && !defined(EPROSIMA_ALL_NO_LIB) \
    && !defined(FASTDDS_QOS_PROFILES_MANAGER_NO_LIB)

// Set properties.
#define EPROSIMA_LIB_NAME FASTDDS_QOS_PROFILES_MANAGER

#if defined(EPROSIMA_ALL_DYN_LINK) || defined(FASTDDS_QOS_PROFILES_MANAGER_DYN_LINK)
#define EPROSIMA_DYN_LINK
#endif // DYNAMIC LINK

#include "eProsima_auto_link.h"
#endif // auto-linking disabled

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_DLL_HPP_
