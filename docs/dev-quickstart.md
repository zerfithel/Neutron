# Neutron Developer Quickstart

This guide explains how to configure, build, test,
and generate documentation for Neutron.

## Prerequisites

Install:

- Git
- CMake
- A C compiler with C23 support
- A build tool, such as Ninja or Make
- CTest (usually included with CMake)
- Doxygen, if you want to generate the API documentation
- `clang-format` and `clang-tidy` for code formatting and checks

See the project's CMake configuration for supported compilers,
platforms, and sanitizer options.

## Clone the repository

```bash
git clone https://github.com/zerfithel/Neutron.git
cd Neutron

# Download git submodules
git submodule update --init --recursive
```

## Configure and build

For a single-configuration generator, such as Ninja or Unix Makefiles:

```bash
cmake --preset <PRESET> <OTHER_FLAGS>

cmake --build build
```

To view available presets:

```bash
cmake --list-presets
```

If you are building `debug`, it is recommended to add sanitizers with:
`-DENABLE_ASAN=ON`, `-DENABLE_UBSAN=ON` (example sanitiezrs).

For a multi-configuration generator,
such as Ninja Multi-Config, Visual Studio or Xcode:

```bash
cmake --preset <PRESET> <OTHER_FLAGS>
cmake --build --preset <PRESET> --config <CONFIG>

```

Code sanitizers from libsanitizer are optional,
but it is recommended to test apps with them,
if you are opening a PR.
You may not mix some sanitizers,
for instance AddressSanitzer (ASAN) is not working with MemorySanitizer (MSAN),
hence you may need to build the app more than once.

## Run tests

```bash
ctest --test-dir build --output-on-failure
```

Make sure all tests are discovered and pass.
To add or update tests, see [the testing guide](tests.md).

## Generate API documentation

With Doxygen installed, run:

```bash
doxygen Doxyfile
```

Then open `docs/doxygen/html/index.html` in a browser.

## Start contributing

Before changing the code, read about project's [architecture](docs/architecture.md)
and [contribution guidelines](../CONTRIBUTING.md).
Follow the project's formatting, testing, and review requirements.
