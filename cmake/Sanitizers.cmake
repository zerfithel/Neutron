if(MSVC)
  if(ENABLE_ASAN)
    add_compile_options(/fsanitize=address)
  endif()

  if(ENABLE_UBSAN)
    message(FATAL_ERROR
      "UndefinedBehaviorSanitizer is not supported by this MSVC configuration"
    )
  endif()

  if(ENABLE_MSAN)
    message(FATAL_ERROR "MemorySanitizer is not supported by MSVC")
  endif()
else()
  if(ENABLE_ASAN)
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
  endif()

  if(ENABLE_UBSAN)
    add_compile_options(-fsanitize=undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=undefined)
  endif()

  if(ENABLE_MSAN)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
      message(FATAL_ERROR "MemorySanitizer is not supported by GCC")
    endif()

    add_compile_options(-fsanitize=memory -fno-omit-frame-pointer)
    add_link_options(-fsanitize=memory)
  endif()
endif()

