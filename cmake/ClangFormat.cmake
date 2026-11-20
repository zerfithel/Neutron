find_program(CLANG_FORMAT_EXE NAMES clang-format)
if(NOT CLANG_FORMAT_EXE)
  message(FATAL_ERROR "clang-format was not found")
endif()

file(GLOB_RECURSE NEUTRON_FORMAT_FILES CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/apps/*.c"
  "${CMAKE_SOURCE_DIR}/apps/*.h"
  "${CMAKE_SOURCE_DIR}/libs/*.c"
  "${CMAKE_SOURCE_DIR}/libs/*.h"
)

add_custom_target(format
  COMMAND "${CLANG_FORMAT_EXE}" -i ${NEUTRON_FORMAT_FILES}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  VERBATIM
)

