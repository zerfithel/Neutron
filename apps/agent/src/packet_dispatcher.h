#pragma once

/**
 * @file packet_dispatcher.h
 * @brief Declarations for packet dispatcher.
 */

#include <xsocket/protocol.h>

#include "execute.h"

/**
 * Handles packet and executes what should be.
 * @param packet Packet to handle.
 * @param execute Function to use to execute commands.
 * @return True on success, false on failure.
 */
bool dispatch_packet(const XSocketPacket *packet, ExecuteFunction execute);
