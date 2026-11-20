cmake_minimum_required(VERSION 3.21)
project(Neutron LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AddUnityTest)

option(ENABLE_CLANG_TIDY "Add the clang-tidy target" ON)
option(ENABLE_CLANG_FORMAT "Add the clang-format target" ON)
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
option(ENABLE_MSAN "Enable MemorySanitizer" OFF)

include(CompilerOptions)
include(Sanitizers)

if(ENABLE_CLANG_TIDY)
  include(ClangTidy)
endif()

if(ENABLE_CLANG_FORMAT)
  include(ClangFormat)
endif()

add_library(unity STATIC
  external/Unity/src/unity.c
)
target_include_directories(unity PUBLIC
  external/Unity/src
)

add_subdirectory(libs/xsocket)
add_subdirectory(apps/agent)
add_subdirectory(apps/operator)

if(BUILD_TESTING)
  add_subdirectory(apps/agent/tests/unit)
  add_subdirectory(apps/operator/tests/unit)
endif()

