#pragma once

/**
 * @file xsocket.h
 * @brief API wrapper for compability between WinSock and BSD Sockets
 */

// Types and headers
#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <ws2tcpip.h>

typedef int SocketLen;
typedef SOCKET Socket;

#else

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

constexpr int INVALID_SOCKET = -1;
constexpr int SOCKET_ERROR = -1;

typedef socklen_t SocketLen;
typedef int Socket;

#endif // Types and headers

#include <stdint.h>

typedef uint16_t port_t;

/**
 * @brief Compability layer for closing socket
 * @param sock Socket to close
 */
static inline void close_socket(Socket sock) {
#ifdef _WIN32
  closesocket(sock);
#else
  close(sock);
#endif
}

static inline bool xsocket_valid(Socket sock) { return sock != INVALID_SOCKET; }

[[nodiscard]] static inline bool xsocket_init() {
#ifdef _WIN32
  WSADATA wsa;
  return WSAStartup(MAKEWORD(2, 2), &wsa) == 0;
#else
  return true;
#endif
}

static inline void xsocket_cleanup() {
#ifdef _WIN32
  WSACleanup();
#endif
  return;
}

static inline ssize_t xsocket_recv(Socket sock, void *buffer, size_t length,
                                   int flags) {
#ifdef _WIN32
  if (length > INT_MAX) {
    return -1;
  }

  return (ssize_t)recv(sock, (char *)buffer, (int)length, flags);
#else
  return (ssize_t)recv(sock, buffer, length, flags);
#endif
}

static inline ssize_t xsocket_send(Socket sock, uint8_t *buffer, size_t length,
                                   int flags) {
#ifdef _WIN32
  if (length > INT_MAX) {
    return -1;
  }

  return (ssize_t)send(sock, (char *)buffer, (int)length, flags);
#else
  return (ssize_t)send(sock, buffer, length, flags);
#endif
}
