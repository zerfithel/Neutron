#pragma once

/**
 * @file packet_parser.h
 * @brief Declarations for XSocket packets parser.
 */

#include <xsocket/protocol.h>

/**
 * @brief Parses binary XSocket packet and writes to XSocketPacket structure.
 * @param message_len Length of raw bytes.
 * @param message Raw packet bytes.
 * @param out Output XSocketPacket structure.
 * @return True on success, false on failure.
 */
bool xsocket_parse_message(size_t message_len,
                           const uint8_t message[static message_len],
                           XSocketPacket *out);
