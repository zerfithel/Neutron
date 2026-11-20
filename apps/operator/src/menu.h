#pragma once

/**
 * @file menu.h
 * @brief Declarations for TUI menu.
 */

#include <stddef.h>
#include <stdio.h>

#include <xsocket/xsocket.h>

/**
 * @brief A handler function that should be called upon given option being
 * picked.
 * @param agent Socket with connection with agent.
 * @return New 'is running' condition state for main loop.
 */
typedef bool (*MenuHandler)(Socket agent);

/**
 * @brief A single menu option.
 */
typedef struct {
  /// Display name of an option.
  const char *name;

  /// Pointer to a handler function that will be called after picking this menu
  /// option.
  MenuHandler handler;
} MenuOption;

/**
 * @brief Show given menu and handle input.
 * @param input Input stream.
 * @param options_count Count of options in menu.
 * @param menu Menu to show and with handlers in it.
 * @return A pointer to MenuHandler function that should be called.
 */
MenuHandler show_menu(FILE *input, size_t options_count,
                      const MenuOption menu[static options_count]);
