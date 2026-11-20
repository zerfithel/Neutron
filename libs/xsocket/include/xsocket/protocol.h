#pragma once

/**
 * @file protocol.h
 * @brief Protocol for agent-server communication.
 *
 * XSocket is a binary protocol. Packet structure:
 * [Packet Type][Payload]
 */

#include <xsocket/xsocket.h>

#include <stdint.h>

/**
 * @brief Packet type for communication protocol.
 */
typedef enum : uint32_t {
  /// Unknown packet type.
  XSOCKET_PACKET_TYPE_UNKNOWN,

  /// Execute encrypted payload.
  XSOCKET_PACKET_TYPE_EXECUTE,
} XSocketPacketType;

/**
 * @brief XSocket packet protocol.
 */
typedef struct {
  /// Payload (data)
  const uint8_t *payload;

  /// Length in bytes of payload
  size_t payload_len;

  /// Type of packet
  XSocketPacketType type;
} XSocketPacket;

constexpr port_t XSOCKET_PORT = 2137;
constexpr size_t XSOCKET_MAX_PACKET_SIZE = 4096;
constexpr size_t XSOCKET_MAX_PAYLOAD_SIZE =
    XSOCKET_MAX_PACKET_SIZE - sizeof(XSocketPacketType);
