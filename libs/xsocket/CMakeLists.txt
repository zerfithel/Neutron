add_library(xsocket STATIC
  src/packet_parser.c
  src/packet_encoder.c
  src/packet_crypto.c
  src/xmemory.c
)

target_include_directories(xsocket
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(WIN32)
  target_link_libraries(xsocket PUBLIC ws2_32)
endif()
