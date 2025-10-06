project(SSDMMCStore C)

add_library(kvstore
    src/key_value_store/kvs.c
    src/key_value_store/kvs_init.c
    src/key_value_store/kvs_internal.c
    src/ssdmmc_sim/ssdmmc_sim_info.c
    src/ssdmmc_sim/ssdmmc_sim.c
    src/key_value_store/kvs_internal_io.c
    src/key_value_store/kvs_metadata.c
    src/key_value_store/kvs_valid.c
)

target_include_directories(kvstore PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src/common
)
