# Network Co-Processor process module
add_library(aoxpc_ncp_process src/aoxpc_ncp_process.c)

target_include_directories(aoxpc_ncp_process PUBLIC include)

target_link_libraries(aoxpc_ncp_process uic_log aoxpc_config uic_main bluetooth_api aoxpc_ncp_core)
