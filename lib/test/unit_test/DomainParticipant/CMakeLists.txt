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

set(MODULE_NAME domain_participant_utest)

###############################################################################
# Files
###############################################################################
file(GLOB_RECURSE LIBRARY_HEADERS
    ${PROJECT_SOURCE_DIR}/include/.*hpp
    ${PROJECT_SOURCE_DIR}/include/.*h
    ${PROJECT_SOURCE_DIR}/include/exception/.*hpp
    ${PROJECT_SOURCE_DIR}/include/utils/.*hpp
)

file(GLOB_RECURSE LIBRARY_SOURCES
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/Allocation.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/Builtin.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/discovery_config/DiscoveryConfig.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/discovery_config/discovery_servers/DiscoveryServers.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/discovery_config/discovery_servers/MetatrafficMulticastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/discovery_config/discovery_servers/MetatrafficUnicastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/InitialPeers.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/MetatrafficExternalUnicastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/MetatrafficMulticastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/builtin/MetatrafficUnicastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/DefaultExternalUnicastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/DefaultMulticastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/DefaultUnicastLocators.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/DomainParticipant.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/Port.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/domain_participant/PropertiesPolicy.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/exception/Exception.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/utils/ParseXML.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/utils/ParseXMLString.cpp
    ${PROJECT_SOURCE_DIR}/src/cpp/utils/ParseXMLErrorHandler.cpp
)

file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/DomainParticipant.cpp
)

###############################################################################
# Create executable
###############################################################################
add_executable( ${MODULE_NAME}
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
    ${TEST_SOURCES}
)

target_link_libraries(${MODULE_NAME} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} ${XercesC_LIBRARIES})

target_include_directories(${MODULE_NAME} PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include/>
        ${PROJECT_SOURCE_DIR}/src/cpp
        ${GTEST_INCLUDE_DIRS}>
        ${GMOCK_INCLUDE_DIRS}>
        ${XercesC_INCLUDE_DIR}
)

add_test(NAME ${MODULE_NAME} COMMAND ${MODULE_NAME})
