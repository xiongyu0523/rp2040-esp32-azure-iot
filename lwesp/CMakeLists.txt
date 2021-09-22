# minimum required cmake version is 3.1.0 (for target_sourc() function)
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# project name is `lwesp`
project(lwesp)

# This project is a library for consuming purpose
add_library(${PROJECT_NAME})

# Make sure OS name and OS port folder are specified at the same time
if((NOT DEFINED LWESP_OPTION_OS) OR (NOT DEFINED LWESP_OPTION_PORT_PATH))
    message(FATAL_ERROR "Error: LWESP_OPTION_OS or LWESP_OPTION_PORT_PATH is not defined")
endif()

# Include port path for header file lwesp_sys_port.h
target_include_directories(${PROJECT_NAME} PUBLIC ${LWESP_OPTION_PORT_PATH})

# Building this library requires OS library
target_link_libraries(${PROJECT_NAME} PUBLIC ${LWESP_OPTION_OS})

# Pick up main sources
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lwesp/src)
# Pick up port source folder out of this directory
add_subdirectory(${LWESP_OPTION_PORT_PATH} lwesp_custom_port)
# Pick up snippets code if required
if(LWESP_OPTION_SNIPPETS)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/snippets)
endif()

# A place for generated/copied include files (no need to change)
set(CUSTOM_INC_DIR ${CMAKE_CURRENT_BINARY_DIR}/custom_inc)

# If the user provided configuration file, copy it to the custom directory
if (NOT DEFINED LWESP_OPTION_USER_CFG_FILE)
    message(STATUS "Using default configurations defined in lwesp_opts.h")
    target_compile_definitions(${PROJECT_NAME} PUBLIC "LWESP_IGNORE_USER_OPTS")
else()
    message(STATUS "Using custom lwesp_opts.h file from ${LWESP_OPTION_USER_CFG_FILE}")
    configure_file(${LWESP_OPTION_USER_CFG_FILE} ${CUSTOM_INC_DIR}/lwesp_opts.h COPYONLY)
    target_include_directories(${PROJECT_NAME} PUBLIC ${CUSTOM_INC_DIR})
endif()
