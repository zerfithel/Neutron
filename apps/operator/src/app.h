#pragma once

/**
 * @file app.h
 * @brief Declarations for the operator applications main loop and logic.
 */

#include <stddef.h>

#include <xsocket/xsocket.h>

#include "menu.h"

/**
 * @brief Main app logic.
 * @param agent Socket with connection with agent.
 * @return App exit code.
 */
int main_loop(Socket agent);
