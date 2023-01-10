cmake_minimum_required(VERSION 3.10)

project(graph_distribution)

find_package(fastrtps REQUIRED)

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

# Link library to external libraries.
target_link_libraries(${PROJECT_NAME} ${PRIVACY} fastrtps
)

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
