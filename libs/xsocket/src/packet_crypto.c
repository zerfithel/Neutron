#include <xsocket/packet_crypto.h>

#include "xmemory.h"

void xsocket_rotate_message(size_t message_len,
                            uint8_t message[static message_len], XorKey key) {
  uint8_t key_buffer[8] = {};
  xmemcpy(key_buffer, &key, sizeof key_buffer);

  for (size_t i = 0; i < message_len; i++) {
    message[i] ^= key_buffer[i % sizeof key_buffer];
  }
}
