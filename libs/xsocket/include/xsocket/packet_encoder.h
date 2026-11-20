#pragma once

/**
 * @file packet_encoder.h
 * @brief Declarations for XSocket packet encoding.
 */

#include <xsocket/protocol.h>

/**
 * @brief Encodes packet for XSocket protocol.
 * @param buffer_size Size of output buffer.
 * @param buffer Output buffer.
 * @param packet Input packet.
 */
size_t xsocket_encode_message(size_t buffer_size,
                              uint8_t buffer[static buffer_size],
                              const XSocketPacket *packet);
