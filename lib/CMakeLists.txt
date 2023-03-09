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

cmake_minimum_required(VERSION 3.16.3)
cmake_policy(VERSION 3.16.3...3.20.3)

project(fastdds_qos_profiles_manager VERSION "0.1.0" LANGUAGES CXX)

# Configure template doxyfile
configure_file(doxyfile.in ${PROJECT_BINARY_DIR}/doc/doxyfile @ONLY IMMEDIATE)

# Configure config file
configure_file(${PROJECT_SOURCE_DIR}/include/config.h.in
    ${PROJECT_BINARY_DIR}/include/config.h)

file(GLOB_RECURSE ALL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.h
    )

set(${PROJECT_NAME}_source_files
    ${ALL_HEADERS}

    src/cpp/domain_participant/builtin/Builtin.cpp
    src/cpp/domain_participant/builtin/discovery_config/DiscoveryConfig.cpp
    src/cpp/domain_participant/builtin/InitialPeers.cpp
    src/cpp/domain_participant/builtin/MetatrafficExternalUnicastLocators.cpp
    src/cpp/domain_participant/builtin/MetatrafficMulticastLocators.cpp
    src/cpp/domain_participant/builtin/MetatrafficUnicastLocators.cpp
    src/cpp/domain_participant/DefaultExternalUnicastLocators.cpp
    src/cpp/domain_participant/DefaultMulticastLocators.cpp
    src/cpp/domain_participant/DefaultUnicastLocators.cpp
    src/cpp/domain_participant/DomainParticipant.cpp
    src/cpp/exception/Exception.cpp
    src/cpp/transport_descriptor/TransportDescriptor.cpp
)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_source_files})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src)

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

# install binaries
install(TARGETS ${PROJECT_NAME}
    COMPONENT bin
    EXPORT ${PROJECT_NAME}_Targets
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
    )

# Install public headers
install(DIRECTORY include/
    DESTINATION include/
    COMPONENT headers
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    )

# Install config.h header
install(FILES ${PROJECT_BINARY_DIR}/include/config.h
    DESTINATION include/
    COMPONENT headers
)
