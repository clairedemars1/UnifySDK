add_library(uic_main_fd SHARED src/uic_main_externals.c)
target_link_libraries(uic_main_fd uic_contiki uic_log)
target_include_directories(
  uic_main_fd
  PUBLIC include/
  PRIVATE src/)

target_add_mock(uic_main_fd)
