add_subdirectory(libs)

add_library(
  zigpc_gateway
  src/gateway_sleepy_queue.cpp
  src/zigpc_gateway.cpp
  src/zigpc_gateway_bookkeeping.cpp
  src/zigpc_gateway_counters.cpp
  src/zigpc_gateway_datastore.cpp
  src/zigpc_gateway_notify.c
  src/zigpc_gateway_process.cpp
  src/zigpc_gateway_request_queue.cpp)

target_include_directories(
  zigpc_gateway
  PUBLIC include
  PRIVATE src)

target_link_libraries(
  zigpc_gateway
  INTERFACE zigpc_zcl_util
  PRIVATE zigbee_host
          zigpc_common
          zigpc_config
          zigpc_datastore
          zigpc_zcl_util
          zigpc_datastore
          uic_contiki
          uic_datastore
          uic_log)

# create mocks
add_mock(zigpc_gateway_mock include/zigpc_gateway.h
         include/zigpc_gateway_notify.h)
target_interface_libraries(zigpc_gateway_mock zigpc_common_mock
                           zigpc_zcl_util_mock)

add_subdirectory(test)
