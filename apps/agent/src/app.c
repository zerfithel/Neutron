#include "app.h"

#include <stdlib.h>

#include <xsocket/packet_crypto.h>
#include <xsocket/packet_parser.h>
#include <xsocket/protocol.h>
#include <xsocket/xsocket.h>

#include "execute.h"
#include "packet_dispatcher.h"

int main_loop(Socket shell) {
  if (!xsocket_valid(shell)) {
    return 1;
  }

  while (true) {
    struct sockaddr_in client_address = {};
    SocketLen client_address_len = sizeof client_address;

    Socket conn =
        accept(shell, (struct sockaddr *)&client_address, &client_address_len);
    if (!xsocket_valid(conn)) {
      continue;
    }

    uint8_t message[XSOCKET_MAX_PACKET_SIZE] = {};
    ssize_t received = xsocket_recv(conn, message, sizeof message, 0);

    if (received > 0) {
      size_t message_len = (size_t)received;
      xsocket_rotate_message(message_len, message, XSOCKET_KEY);

      XSocketPacket packet = {};
      xsocket_parse_message(message_len, message, &packet);

      dispatch_packet(&packet, execute_command);
    }
    close_socket(conn);
  }

  return 0;
}
