#include "app.h"

#include <stdio.h>
#include <string.h>

#include <xsocket/packet_crypto.h>
#include <xsocket/packet_encoder.h>
#include <xsocket/protocol.h>
#include <xsocket/xsocket.h>

#include "input.h"
#include "menu.h"

[[nodiscard]] static bool handle_send_command(Socket agent) {
  if (!xsocket_valid(agent)) {
    return false;
  }

  char payload_str[XSOCKET_MAX_PAYLOAD_SIZE] = {};
  get_input(stdin, sizeof payload_str, payload_str, "Command: ");

  XSocketPacket packet = {
      .payload = (const uint8_t *)payload_str,
      .payload_len = strlen(payload_str),
      .type = XSOCKET_PACKET_TYPE_EXECUTE,
  };

  uint8_t buffer[XSOCKET_MAX_PACKET_SIZE] = {};
  size_t len = xsocket_encode_message(sizeof buffer, buffer, &packet);
  xsocket_rotate_message(sizeof buffer, buffer, XSOCKET_KEY);

  ssize_t sent = xsocket_send(agent, buffer, len, 0);
  if (sent > 0) {
    printf("Sent %zd bytes\n", sent);
  } else {
    return false;
  }

  return true;
}

[[nodiscard]] static bool handle_exit(Socket agent) {
  (void)agent;
  return false;
}

int main_loop(Socket agent) {
  const MenuOption menu[] = {
      {"Execute command", handle_send_command},
      {"Exit", handle_exit},
  };
  const size_t menu_len = sizeof menu / sizeof menu[0];

  bool is_running = true;
  while (is_running) {
    MenuHandler handler = show_menu(stdin, menu_len, menu);
    if (handler) {
      is_running = handler(agent);
    }
  }

  return 0;
}
