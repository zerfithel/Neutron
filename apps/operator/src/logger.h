#pragma once

/*
 * @file logger.h
 * @brief Implementation for logging utils.
 */

#include <stdarg.h>
#include <stdio.h>

#if defined(__GNUC__) || defined(__clang__)
__attribute__((format(printf, 1, 2)))
#endif
static inline void log_error(const char *format, ...) {
  va_list args;
  va_start(args, format);

  vfprintf(stderr, format, args);

  va_end(args);
}
