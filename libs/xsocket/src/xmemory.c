#include "xmemory.h"

void *xmemcpy(void *restrict dest, const void *src, size_t n) {
  if (!dest || !src) {
    return nullptr;
  }

  unsigned char *d = dest;
  const unsigned char *s = src;

  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}
