#include <xsocket/packet_encoder.h>

#include <stddef.h>
#include <stdint.h>

#include "xmemory.h"

size_t xsocket_encode_message(size_t buffer_size,
                              uint8_t buffer[static buffer_size],
                              const XSocketPacket *packet) {
  if (buffer_size < sizeof packet->type ||
      packet->payload_len > buffer_size - sizeof packet->type) {
    return 0;
  }

  uint32_t network_type = htonl(packet->type);
  xmemcpy(buffer, &network_type, sizeof packet->type);

  if (packet->payload_len > 0) {
    xmemcpy(buffer + sizeof packet->type, packet->payload, packet->payload_len);
  }

  return sizeof packet->type + packet->payload_len;
}
