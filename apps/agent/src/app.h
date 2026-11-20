#pragma once

/**
 * @file app.h
 * @brief Declarations for the agent applications main loop and logic.
 */

#include <xsocket/xsocket.h>

/**
 * @brief Main app logic.
 * @param shell Server socket
 * @return App return code.
 */
int main_loop(Socket shell);
