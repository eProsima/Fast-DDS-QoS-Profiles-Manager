cmake_minimum_required(VERSION 3.10)

project(fastdds_qos_profiles_manager VERSION "0.1.0" LANGUAGES CXX)

# Configure template doxyfile
configure_file(doxyfile.in ${PROJECT_BINARY_DIR}/doc/doxyfile @ONLY IMMEDIATE)

file(GLOB_RECURSE ALL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.h
    )

set(${PROJECT_NAME}_source_files
    ${ALL_HEADERS}

    src/main.cpp
)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_source_files})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src)

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
