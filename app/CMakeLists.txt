target_sources(${PROJECT_NAME}
    PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/bsp/tx_initialize_low_level.S
)
