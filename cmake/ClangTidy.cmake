find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(NOT CLANG_TIDY_EXE)
  message(FATAL_ERROR "clang-tidy was not found")
endif()

file(GLOB_RECURSE NEUTRON_C_FILES CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/apps/*.c"
  "${CMAKE_SOURCE_DIR}/libs/*.c"
)

add_custom_target(tidy
  COMMAND "${CLANG_TIDY_EXE}" -p "${CMAKE_BINARY_DIR}" ${NEUTRON_C_FILES}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  VERBATIM
)

