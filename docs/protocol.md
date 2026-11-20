# Neutron Protocol

Neutron uses the `xsocket` library to provide a portable socket API across Windows (WinSock) and POSIX systems (BSD sockets).

XSocket also provides a binary protocol that the agent and operator use to exchange packets.

## Packet frame

At a high level, a packet consists of a packet type followed by its payload:

```text
[XSocketPacketType: 32 bits][Payload: variable length]
```

The packet type is a 32-bit unsigned value. The payload contains the data associated with that packet type.

All packets should be first serialized and encoded with `<xsocket/packet_encoder.h>` and then parsed to local values with `<xsocket/packet_parser.h>`.

## Enums and constants

To browse XSocket enums, constants, and API documentation, generate the [Doxygen documentation](doxygen.md).
