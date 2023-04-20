# Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.16.3...3.20.3)

project(fastdds_qos_profiles_manager_lib VERSION "0.1.0" LANGUAGES CXX)

# Search for Xerces package
find_package(XercesC)

###############################################################################
# Installation paths
###############################################################################
set(BIN_INSTALL_DIR bin/ CACHE PATH "Installation directory for binaries")
set(DATA_INSTALL_DIR share/ CACHE PATH "Installation directory for data")
set(DOC_INSTALL_DIR docs/ CACHE PATH "Installation directory for documentation")
set(HTML_INSTALL_DIR docs/doxygen/html CACHE PATH "Installation directory for API reference")
set(INCLUDE_INSTALL_DIR include/ CACHE PATH "Installation directory for C++ headers")
set(LIB_INSTALL_DIR lib${LIB_SUFFIX}/ CACHE PATH "Installation directory for libraries")
set(LICENSE_INSTALL_DIR ${DATA_INSTALL_DIR}/${PROJECT_NAME} CACHE PATH "Installation directory for licenses")
set(XML_INSTALL_DIR docs/doxygen/xml CACHE PATH "Installation directory for API reference")

set(INSTALL_DESTINATION_PATH ${DATA_INSTALL_DIR}/${CMAKE_PROJECT_NAME}/cmake)

###############################################################################
# Download and install external files
###############################################################################
# Download XML schema
file(DOWNLOAD "https://raw.githubusercontent.com/eProsima/Fast-DDS/master/resources/xsd/fastRTPS_profiles.xsd"
    ${PROJECT_BINARY_DIR}/${DATA_INSTALL_DIR}/fastdds_profiles.xsd)
# Install XML schema
install(FILES ${PROJECT_BINARY_DIR}/${DATA_INSTALL_DIR}/fastdds_profiles.xsd
    DESTINATION ${DATA_INSTALL_DIR})
# Set XML absolute path
file(REAL_PATH ${CMAKE_INSTALL_PREFIX}/${DATA_INSTALL_DIR}/fastdds_profiles.xsd XML_SCHEMA_PATH)

###############################################################################
# Configuration steps
###############################################################################
# Configure template doxyfile
configure_file(doxyfile.in ${PROJECT_BINARY_DIR}/docs/doxyfile @ONLY IMMEDIATE)

# Configure config file
configure_file(${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/config.h.in
    ${PROJECT_BINARY_DIR}/include/${PROJECT_NAME}/config.h)

###############################################################################
# Default shared libraries
###############################################################################
# Global flag to cause add_library() to create shared libraries if on.
# If set to true, this will cause all libraries to be built shared
# unless the library was explicitly added as a static library.
option(BUILD_SHARED_LIBS "Create shared libraries by default" ON)

if(BUILD_SHARED_LIBS)
    set(FASTDDS_QOS_PROFILES_MANAGER_DYNAMIC ON)
endif()

# Obtain all headers
file(GLOB_RECURSE ALL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/cpp/*.hpp
    ${PROJECT_SOURCE_DIR}/src/cpp/*.h
    )

set(${PROJECT_NAME}_source_files
    ${ALL_HEADERS}

    src/cpp/common/Duration.cpp
    src/cpp/common/LocatorList.cpp
    src/cpp/common/qos/Durability.cpp
    src/cpp/common/qos/Reliability.cpp
    src/cpp/data_reader/DataReader.cpp
    src/cpp/data_writer/DataWriter.cpp
    src/cpp/data_reader/Qos.cpp
    src/cpp/data_writer/Qos.cpp
    src/cpp/domain_participant/Allocation.cpp
    src/cpp/domain_participant/builtin/Builtin.cpp
    src/cpp/domain_participant/builtin/discovery_config/DiscoveryConfig.cpp
    src/cpp/domain_participant/builtin/discovery_config/discovery_servers/DiscoveryServers.cpp
    src/cpp/domain_participant/builtin/discovery_config/discovery_servers/MetatrafficMulticastLocators.cpp
    src/cpp/domain_participant/builtin/discovery_config/discovery_servers/MetatrafficUnicastLocators.cpp
    src/cpp/domain_participant/builtin/InitialPeers.cpp
    src/cpp/domain_participant/builtin/MetatrafficExternalUnicastLocators.cpp
    src/cpp/domain_participant/builtin/MetatrafficMulticastLocators.cpp
    src/cpp/domain_participant/builtin/MetatrafficUnicastLocators.cpp
    src/cpp/domain_participant/DefaultExternalUnicastLocators.cpp
    src/cpp/domain_participant/DefaultMulticastLocators.cpp
    src/cpp/domain_participant/DefaultUnicastLocators.cpp
    src/cpp/domain_participant/DomainParticipant.cpp
    src/cpp/domain_participant/Port.cpp
    src/cpp/domain_participant/PropertiesPolicy.cpp
    src/cpp/exception/Exception.cpp
    src/cpp/transport_descriptor/TransportDescriptor.cpp
    src/cpp/utils/ErrorHandlerXMLManager.cpp
    src/cpp/utils/StringXMLManager.cpp
    src/cpp/utils/XMLManager.cpp
)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_source_files})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src/cpp
    ${XercesC_INCLUDE_DIR})

# Include XML library links
target_link_libraries(${PROJECT_NAME} ${XercesC_LIBRARIES})

###############################################################################
# Testing options
###############################################################################

option(EPROSIMA_BUILD_TESTS "Activate the tests building and execution" OFF)

if(EPROSIMA_BUILD_TESTS)
    enable_testing()
    include(CTest)
    add_subdirectory(test)
endif()

###############################################################################
# Packaging
###############################################################################

# Install library
install(TARGETS ${PROJECT_NAME}
    COMPONENT libraries
    EXPORT ${PROJECT_NAME}-targets
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
)

# Generate different target names depending on linking
get_target_property(TARGET_TYPE ${PROJECT_NAME} TYPE)
if(TARGET_TYPE STREQUAL "SHARED_LIBRARY")
    set(FASTDDS_QOS_PROFILES_MANAGER_LINKING shared)
else()
    set(FASTDDS_QOS_PROFILES_MANAGER_LINKING static)
endif()

install(EXPORT ${PROJECT_NAME}-targets
    DESTINATION ${INSTALL_DESTINATION_PATH}
    FILE ${PROJECT_NAME}-${FASTDDS_QOS_PROFILES_MANAGER_LINKING}-targets.cmake
    COMPONENT cmake
    )

# Install public headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
    DESTINATION ${INCLUDE_INSTALL_DIR}
    COMPONENT headers
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    )

# Install config.h header
install(FILES ${PROJECT_BINARY_DIR}/include/${PROJECT_NAME}/config.h
    DESTINATION ${INCLUDE_INSTALL_DIR}/${PROJECT_NAME}
    COMPONENT headers
)

# Install doxyfile
install(FILES ${PROJECT_BINARY_DIR}/docs/doxyfile
    DESTINATION ${DOC_INSTALL_DIR}
    COMPONENT documentation)

# Create docs directory
install(DIRECTORY DESTINATION ${HTML_INSTALL_DIR})
install(DIRECTORY DESTINATION ${XML_INSTALL_DIR})

###############################################################################
# Create CMake package config file
###############################################################################
include(CMakePackageConfigHelpers)

configure_package_config_file(${PROJECT_SOURCE_DIR}/cmake/packaging/Config.cmake.in
    ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}-config.cmake
    INSTALL_DESTINATION ${INSTALL_DESTINATION_PATH}
    PATH_VARS BIN_INSTALL_DIR INCLUDE_INSTALL_DIR LIB_INSTALL_DIR DOC_INSTALL_DIR HTML_INSTALL_DIR XML_INSTALL_DIR
    )
write_basic_package_version_file(${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
    )
install(FILES ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}-config.cmake
    ${PROJECT_BINARY_DIR}/cmake/config/${PROJECT_NAME}-config-version.cmake
    DESTINATION ${INSTALL_DESTINATION_PATH}
    COMPONENT cmake
    )
