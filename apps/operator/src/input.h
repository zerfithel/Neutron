#pragma once

/**
 * @file input.h
 * @brief Declarations for TUI (Terminal User Interface).
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Reads input from stdin and writes to out buffer.
 * @param input Input strema.
 * @param out_len Length of out buffer.
 * @param out Output buffer.
 * @param prompt Printed prompt. Nullable.
 * @return Written bytes to out.
 */
size_t get_input(FILE *input, size_t out_len, char out[static out_len],
                 const char *prompt);
