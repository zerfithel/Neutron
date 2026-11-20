#include "packet_dispatcher.h"

#include <xsocket/protocol.h>

#include "execute.h"

bool dispatch_packet(const XSocketPacket *packet, ExecuteFunction execute) {
  if (packet == nullptr || execute == nullptr) {
    return false;
  }

  switch (packet->type) {

  case XSOCKET_PACKET_TYPE_EXECUTE: {
    execute((const char *)packet->payload);
    break;
  }

  default: {
    return false;
  }
  }

  return true;
}
