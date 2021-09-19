set(SOURCES
    # {{BEGIN_TARGET_SOURCES}}
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_ap.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_buff.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_cli.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_conn.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_debug.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_dhcp.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_dns.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_evt.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_hostname.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_input.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_int.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_mdns.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_mem.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_parser.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_pbuf.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_ping.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_smart.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_sntp.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_sta.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_threads.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_timeout.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_unicode.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_utils.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_webserver.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp_wps.c
	${CMAKE_CURRENT_LIST_DIR}/lwesp/lwesp.c
	${CMAKE_CURRENT_LIST_DIR}/api/lwesp_netconn.c
    # {{END_TARGET_SOURCES}}
)

list(APPEND SOURCES ${CMAKE_CURRENT_LIST_DIR}/system/lwesp_sys_${LWESP_OS}.c ${LWESP_PLATFORM_FILE})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/system/port/${LWESP_OS})

# Append customized heap implemenation file if user wants it
if(DEFINED LWESP_MEMHEAP_FILE)
    list(APPEND SOURCES ${LWESP_MEMHEAP_FILE})
endif()

# Append MQTT files if the user wants it
if(LWESP_ENABLE_MQTT)
    list(APPEND SOURCES
         ${CMAKE_CURRENT_LIST_DIR}/apps/mqtt/lwesp_mqtt_client_api.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/mqtt/lwesp_mqtt_client_evt.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/mqtt/lwesp_mqtt_client.c
    )
endif()

# TODO: Append HTTP server files if the user wants it
# TODO: Append cayenne files if the user wants it
# TODO: Append cli files if the user wants it

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)
