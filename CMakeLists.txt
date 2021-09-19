cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

include(pico_sdk_import.cmake)

project(rp2040-esp32-azure-iot VERSION 0.0.1)

add_executable(${PROJECT_NAME} "")

pico_sdk_init()
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})

set(THREADX_ARCH        "cortex_m0")
set(THREADX_TOOLCHAIN   "gnu")
set(TX_USER_FILE        ${CMAKE_CURRENT_LIST_DIR}/app/config/tx_user.h)
set(NX_USER_FILE        ${CMAKE_CURRENT_LIST_DIR}/app/config/nx_user.h)
set(LWESP_OS            "threadx")
set(LWESP_PLATFORM_FILE ${CMAKE_CURRENT_LIST_DIR}/app/bsp/lwesp_ll_raspberry_pi_pico_threadx.c)
set(LWESP_MEMHEAP_FILE  ${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp/src/system/lwesp_mem_threadx.c)
set(LWESP_CFG_FILE      ${CMAKE_CURRENT_LIST_DIR}/app/config/lwesp_opts.h)

add_subdirectory(threadx)
add_subdirectory(netxduo)
add_subdirectory(lwesp)
add_subdirectory(app)

target_link_libraries(${PROJECT_NAME} pico_stdlib cmsis_core azrtos::threadx azrtos::netxduo lwesp)