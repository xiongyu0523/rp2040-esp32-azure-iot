# PROJECT_NAME = ${LWESP_OPTION_OS}
target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lwesp_sys_threadx.c
    ${CMAKE_CURRENT_LIST_DIR}/lwesp_mem_threadx.c
)
