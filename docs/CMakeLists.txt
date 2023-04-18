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

project(fastdds_qos_profiles_manager_docs VERSION 0.1.0 LANGUAGES CXX)

###############################################################################
# Load external dependencies
###############################################################################
find_package(fastdds_qos_profiles_manager REQUIRED)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})
find_package(Sphinx REQUIRED)

####################################################################################################
# Build documentation
####################################################################################################
set(PROJECT_SOURCE_DOCS_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_BINARY_DOCS_DIR ${PROJECT_BINARY_DIR}/docs)
set(DOCS_OUTPUT_HTML_DIR ${PROJECT_BINARY_DOCS_DIR}/html)

# Create docs directories
add_custom_target(doc-dirs
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DOCS_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DOCS_OUTPUT_HTML_DIR}
    COMMENT "Creating documentation directories" VERBATIM)

####################################################################################################
# Build Fast DDS QoS Profiles Manager Library Doxygen documentation
####################################################################################################

# TODO

####################################################################################################
# Build Sphinx documentation
####################################################################################################
set(DOCS_BUILDER html)

add_custom_target(Sphinx ALL
    COMMAND
    ${SPHINX_EXECUTABLE} -b ${DOCS_BUILDER}
    -d "${PROJECT_BINARY_DOCS_DIR}/doctrees"
    ${PROJECT_SOURCE_DOCS_DIR}
    ${DOCS_OUTPUT_HTML_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating documentation with Sphinx")

####################################################################################################
# Install documentation
####################################################################################################
install(DIRECTORY ${DOCS_OUTPUT_HTML_DIR}
    DESTINATION docs/${PROJECT_NAME}/sphinx
    COMPONENT fastdds_qos_profiles_manager-sphinx
    PATTERN ".buildinfo" EXCLUDE)
set(CPACK_COMPONENT_fastdds_qos_profiles_manager-sphinx_DISPLAY_NAME "Fast DDS QoS Profiles Manager Sphinx")
set(CPACK_COMPONENT_fastdds_qos_profiles_manager-sphinx_DESCRIPTION
    "eProsima Fast DDS QoS Profiles Manager documentation in ${DOCS_BUILDER} format")
set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} ${DOCS_BUILDER})

####################################################################################################
# Build documentation tests
####################################################################################################
if (BUILD_DOCUMENTATION_TESTS)
# TODO
endif()
