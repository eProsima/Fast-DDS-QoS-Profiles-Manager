cmake_minimum_required(VERSION 3.10)

###############################################################################
# Project for cxxopts library:
###############################################################################

project(poc_cxxopts VERSION "0.1.0" LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/cxxopts/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cxxopts/lib
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

###############################################################################
# Project for docopt library:
###############################################################################

project(poc_docopt VERSION "0.1.0" LANGUAGES CXX)

find_package(docopt COMPONENTS CXX REQUIRED)
include_directories(${DOCOPT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/docopt/main.cpp)

target_link_libraries(${PROJECT_NAME} docopt)

#target_include_directories(${PROJECT_NAME} PUBLIC
    #${PROJECT_SOURCE_DIR}
    #${CMAKE_CURRENT_SOURCE_DIR}/src/docopt/lib/docopt
    #)

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
