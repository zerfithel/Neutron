# Internal Architecture of Neutron

This document gives a high-level overview of Neutron's main components and how they communicate.

## XSocket

Both the agent and the operator use **XSocket**, a statically-linked library that provides a portable socket API across Windows (WinSock) and BSD sockets.

XSocket also contains communication-protocol functionality, including packet encoding and parsing, cryptographic utilities, and related helpers.

For implementation details, see the [XSocket Doxygen documentation](doxygen.md) and the [protocol documentation](protocol.md).

## Communication

The agent listens for incoming connections on the port defined by the `XSOCKET_PORT` constant in XSocket. When a connection is established, the agent receives and parses packets using the shared library.

The agent's packet dispatcher receives parsed packets and routes them to the relevant handler. See [`packet_dispatcher.c`](../apps/agent/src/packet_dispatcher.c) for the dispatcher implementation. Packet types are documented in the XSocket Doxygen documentation.

The operator also uses XSocket to prepare packets for communication with the agent, keeping protocol handling consistent across both components.
