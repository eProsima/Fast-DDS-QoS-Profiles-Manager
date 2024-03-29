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

project(fastdds_qos_profiles_manager_cli VERSION "0.1.0" LANGUAGES CXX)

set(EXECUTABLE_NAME "fastddsqosprof")

# Configure config file
configure_file(${PROJECT_SOURCE_DIR}/include/config.h.in
    ${PROJECT_BINARY_DIR}/include/config.h)

###############################################################################
# Load external dependencies
###############################################################################
find_package(fastdds_qos_profiles_manager_lib REQUIRED)
find_package(docopt COMPONENTS CXX REQUIRED)

###############################################################################
# Compilation
###############################################################################
file(GLOB_RECURSE ALL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/cpp/*.hpp
    ${PROJECT_SOURCE_DIR}/src/cpp/*.h
    )

set(${PROJECT_NAME}_source_files
    ${ALL_HEADERS}

    src/cpp/fastdds_qos_profiles_manager_cli.cpp
    src/cpp/utils/builtin_parser.cpp
    src/cpp/utils/duration_type_parser.cpp
    src/cpp/utils/endpoint_subelement_parser.cpp
    src/cpp/utils/external_locators_parser.cpp
    src/cpp/utils/locators_parser.cpp
    src/cpp/utils/main_element_parser.cpp
    src/cpp/utils/participant_subelement_parser.cpp
    src/cpp/utils/qos_parser.cpp
    src/cpp/utils/transport_subelement_parser.cpp
    src/cpp/utils/utils.cpp
)

add_executable(${EXECUTABLE_NAME} ${${PROJECT_NAME}_source_files})

target_include_directories(${EXECUTABLE_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src/cpp
    ${fastdds_qos_profiles_manager_lib_INCLUDE_DIR})

target_link_libraries(${EXECUTABLE_NAME}
    docopt
    fastdds_qos_profiles_manager_lib
)

###############################################################################
# Packaging
###############################################################################
install(TARGETS ${EXECUTABLE_NAME}
    EXPORT ${PROJECT_NAME}-targets
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    COMPONENT bin
    )

# Install config.h header
install(FILES ${PROJECT_BINARY_DIR}/include/config.h
    DESTINATION include/
    COMPONENT headers
)
