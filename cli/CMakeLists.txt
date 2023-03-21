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

project(fastdds_qos_profiles_manager_cli VERSION "0.1.0" LANGUAGES CXX)

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

###############################################################################
# Load external dependencies
###############################################################################
find_package(fastdds_qos_profiles_manager REQUIRED)
find_package(docopt COMPONENTS CXX REQUIRED)

###############################################################################
# Compilation
###############################################################################
file(GLOB_RECURSE ALL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.h
    )

set(${PROJECT_NAME}_source_files
    ${ALL_HEADERS}

    src/cpp/fastdds_qos_profiles_manager_cli.cpp
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_source_files})

target_link_libraries(${PROJECT_NAME}
    docopt
    fastdds_qos_profiles_manager
)

###############################################################################
# Packaging
###############################################################################
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    COMPONENT bin
    )
