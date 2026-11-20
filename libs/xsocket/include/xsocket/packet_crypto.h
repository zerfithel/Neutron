#pragma once

/**
 * @file packet_crypto.h
 * @brief Declarations for XSocket protocol encryption/decryption with XOR.
 */

#include <stddef.h>
#include <stdint.h>

typedef uint64_t XorKey;

// TODO: Exchange new randomised keys on every connection.
constexpr XorKey XSOCKET_KEY = 12489145;

/**
 * @brief XORs packet raw bytes.
 * @param message_len Length of message.
 * @param message Message to encrypt/decrypt.
 * @param key XOR key.
 */
void xsocket_rotate_message(size_t message_len,
                            uint8_t message[static message_len], XorKey key);
