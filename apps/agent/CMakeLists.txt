add_library(agent_core
  src/app.c
  src/packet_dispatcher.c
  src/execute.c
)

target_include_directories(agent_core
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(agent_core PUBLIC xsocket)

add_executable(agent
  src/init.c
)

target_link_libraries(agent PRIVATE agent_core)
