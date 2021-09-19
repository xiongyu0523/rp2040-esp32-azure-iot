cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(lwesp LANGUAGES C)

# Define our target library for consumers
add_library(${PROJECT_NAME})

# A place for generated/copied include files (no need to change)
set(CUSTOM_INC_DIR ${CMAKE_CURRENT_BINARY_DIR}/custom_inc)

# Make sure OS port is specified 
if(NOT DEFINED LWESP_OS)
    message(FATAL_ERROR "Error: LWESP_OS not defined")
endif()

# Make sure user provided platform driver file is specified 
if(NOT DEFINED LWESP_PLATFORM_FILE)
    message(FATAL_ERROR "Error: LWESP_PLATFORM_FILE not defined")
endif()

# Add any required dependencies between this library and others
if(LWESP_OS STREQUAL "threadx")
    target_link_libraries(${PROJECT_NAME} PUBLIC "azrtos::threadx")
endif()

# Pick up the sources
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lwesp/src)

# If the user provided configuration file, copy it to the custom directory
if (NOT DEFINED LWESP_CFG_FILE)
    message(STATUS "Using default configurations defined in lwesp_opts.h")
    target_compile_definitions(${PROJECT_NAME} PUBLIC "LWESP_IGNORE_USER_OPTS")
else()
    message(STATUS "Using custom lwesp_opts.h file from ${LWESP_CFG_FILE}")
    configure_file(${LWESP_CFG_FILE} ${CUSTOM_INC_DIR}/lwesp_opts.h COPYONLY)
    target_include_directories(${PROJECT_NAME} PUBLIC ${CUSTOM_INC_DIR})
endif()
