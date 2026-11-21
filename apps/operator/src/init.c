#include <xsocket/packet_crypto.h>
#include <xsocket/packet_encoder.h>
#include <xsocket/protocol.h>
#include <xsocket/xsocket.h>

#include "app.h"
#include "input.h"
#include "logger.h"

/**
 * @brief Connects to agent by IP.
 * @param ip Agent IP (IPv4 only).
 * @return Socket with connection with agent on success, INVALID_SOCKET on
 * failure.
 */
static inline Socket connect_to_agent(const char *ip) {
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(XSOCKET_PORT);

  if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
    return INVALID_SOCKET;
  }

  Socket sock = socket(AF_INET, SOCK_STREAM, 0);
  if (!xsocket_valid(sock)) {
    return INVALID_SOCKET;
  }

  if (connect(sock, (struct sockaddr *)&addr, sizeof addr) != 0) {
    close_socket(sock);
    return INVALID_SOCKET;
  }

  return sock;
}

int main() {
  int rc = 0;
  Socket agent = INVALID_SOCKET;
  bool xsocket_ok = false;

  do {
    if (!xsocket_init()) {
      log_error("Failed to initialize xsocket library");
      break;
    }
    xsocket_ok = true;

    char agent_ip[128] = {};
    get_input(stdin, sizeof agent_ip, agent_ip, "Agent IP: ");

    agent = connect_to_agent(agent_ip);
    if (!xsocket_valid(agent)) {
      log_error("Failed to connect to agent: %s", agent_ip);
      rc = 1;
      break;
    }

    rc = main_loop(agent);
  } while (false);

  if (xsocket_valid(agent)) {
    close_socket(agent);
  }

  if (xsocket_ok) {
    xsocket_cleanup();
  }

  return rc;
}
