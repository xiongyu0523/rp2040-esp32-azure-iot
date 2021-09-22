target_sources(${PROJECT_NAME} PRIVATE 
                ${CMAKE_CURRENT_LIST_DIR}/dns.c
                ${CMAKE_CURRENT_LIST_DIR}/http_server.c
                ${CMAKE_CURRENT_LIST_DIR}/mqtt_client_api_cayenne.c
                ${CMAKE_CURRENT_LIST_DIR}/mqtt_client_api.c
                ${CMAKE_CURRENT_LIST_DIR}/mqtt_client.c
                ${CMAKE_CURRENT_LIST_DIR}/netconn_client.c
                ${CMAKE_CURRENT_LIST_DIR}/netconn_server_1thread.c
                ${CMAKE_CURRENT_LIST_DIR}/netconn_server.c
                ${CMAKE_CURRENT_LIST_DIR}/sntp.c
                ${CMAKE_CURRENT_LIST_DIR}/station_manager.c
                ${CMAKE_CURRENT_LIST_DIR}/telnet_server.c
                ${CMAKE_CURRENT_LIST_DIR}/utils.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
