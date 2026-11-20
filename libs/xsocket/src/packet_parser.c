#include <xsocket/packet_parser.h>

#include "xmemory.h"

bool xsocket_parse_message(size_t message_len,
                           const uint8_t message[static message_len],
                           XSocketPacket *out) {
  if (message_len < sizeof(XSocketPacketType)) {
    return false;
  }

  XSocketPacketType network_type = XSOCKET_PACKET_TYPE_UNKNOWN;
  xmemcpy(&network_type, message, sizeof(XSocketPacketType));
  out->type = ntohl(network_type);
  out->payload = message + sizeof(XSocketPacketType);
  out->payload_len = message_len - sizeof(XSocketPacketType);

  return true;
}
