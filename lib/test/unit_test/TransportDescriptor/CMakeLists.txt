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

set(MODULE_NAME transport_descriptor_utest)

###############################################################################
# Files
###############################################################################
file(GLOB_RECURSE HEADERS
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/TransportDescriptor.cpp
)

###############################################################################
# Create executable
###############################################################################
add_executable( ${MODULE_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(${MODULE_NAME} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES})

target_include_directories(${MODULE_NAME} PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
        ${GTEST_INCLUDE_DIRS}>
        ${GMOCK_INCLUDE_DIRS}>
)

add_test(NAME ${MODULE_NAME} COMMAND ${MODULE_NAME})
