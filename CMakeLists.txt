cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

include(pico_sdk_import.cmake)

project(rp2040-esp32-azure-iot VERSION 0.0.1)

add_executable(${PROJECT_NAME} "")

pico_sdk_init()
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_add_extra_outputs(${PROJECT_NAME})

set(THREADX_ARCH        "cortex_m0")
set(THREADX_TOOLCHAIN   "gnu")
set(TX_USER_FILE        ${CMAKE_CURRENT_LIST_DIR}/app/config/tx_user.h)
set(NX_USER_FILE        ${CMAKE_CURRENT_LIST_DIR}/app/config/nx_user.h)

option(NXD_ENABLE_AZURE_IOT     "Enbale Azure IoT in NetX Duo (default is ON)"              ON)
option(NXD_ENABLE_FILE_SERVERS  "Enable File Server feature in NetX Duo (default is OFF)"   OFF)
set(NX_AZURE_DISABLE_IOT_SECURITY_MODULE ON CACHE BOOL "Disable Azure IoT Security Module (default is OFF)")

set(LWESP_OPTION_OS             "threadx")
set(LWESP_OPTION_PORT_PATH      ${CMAKE_CURRENT_LIST_DIR}/app/port/lwesp)
set(LWESP_OPTION_USER_CFG_FILE  ${CMAKE_CURRENT_LIST_DIR}/app/config/lwesp_opts.h)
set(LWESP_OPTION_SNIPPETS       ON)

add_subdirectory(threadx)
add_subdirectory(netxduo)
add_subdirectory(lwesp)
add_subdirectory(app)

target_link_libraries(${PROJECT_NAME} pico_stdlib cmsis_core threadx netxduo lwesp)