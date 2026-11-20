#pragma once

/**
 * @file xmemory.h
 * @brief Declarations for safer memory utils.
 */

#include <stddef.h>

/**
 * @brief Safely copy memory area. Destination and source may not overlap.
 * @param dest Destination pointer that does not overlap with src.
 * @param src Source pointer that does not overlap with dest.
 * @param n Bytes to copy to dest.
 * @return Pointer to dest or nullptr on failure.
 */
void *xmemcpy(void *restrict dest, const void *restrict src, size_t n);
