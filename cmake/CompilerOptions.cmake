if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wshadow
    -Wformat=2
    -Wundef
    -Wstrict-prototypes
    -Wmissing-prototypes
    -Werror
  )
endif()

