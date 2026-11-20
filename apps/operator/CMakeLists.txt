add_library(operator_core
  src/app.c
  src/input.c
  src/menu.c
)

target_include_directories(operator_core
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(operator_core PUBLIC xsocket)

add_executable(operator
  src/init.c
)

target_link_libraries(operator PRIVATE operator_core)
