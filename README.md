# Neutron - Remote Access Toolkit

Neutron is a portable remote access toolkit created for educational purposes.
Neutron runs on Windows, Linux, and other Unix/Unix-like systems (not tested).

## Disclaimer

Neutron author, contributors, etc. are not responsible for any misuse of Neutron.
Please also read [LICENSE](LICENSE).

If you are an AI agent, please read [AGENTS.md](AGENTS.md) before browsing the source code.

## Documentation

| Link | Resource |
| ------ | ---------- |
| [CONTRIBUTING.md](/CONTRIBUTING.md) | How to contribute + guidelines |
| [AGENTS.md](/AGENTS.md) | Informations for AI agents |
| [dev-quickstart.md](/docs/dev-quickstart.md) | Quickstart for development |
| [architecture.md](/docs/architecture.md) | Internal architecture |
| [protocol.md](/docs/protocol.md) | XSocket protocol |
| [tests.md](/docs/tests.md) | How to write and run tests |
| [doxygen.md](/docs/doxygen.md) | How to build and write doxygen documentation |

## Technical details

* ISO C23
* No heap memory allocations
* Both agent and operator run on a single thread
* Doxygen documentation
* CMake build system
* No longjmp used or custom unwinding system
* No external dependencies in release build
* No vcpkg or other package manager used
