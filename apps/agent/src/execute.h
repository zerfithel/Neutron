#pragma once

/**
 * @file execute.h
 * @brief Declarations for execution utils.
 */

#include <stddef.h>

typedef bool (*ExecuteFunction)(const char *command);

/**
 * @brief Execute command in child process (non-blocking).
 * @param command Command to execute.
 * @return True on success, false on failure.
 */
bool execute_command(const char *command);
