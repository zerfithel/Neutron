#include "menu.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

MenuHandler show_menu(FILE *input, size_t options_count,
                      const MenuOption menu[static options_count]) {
  for (size_t i = 0; i < options_count; i++) {
    printf("%zu) %s\n", i, menu[i].name);
  }

  char input_buffer[128] = {};
  if (get_input(input, sizeof input_buffer, input_buffer, "Option: ") == 0) {
    return nullptr;
  }

  long option_num = 0L;
  char *endptr = NULL;

  option_num = strtol(input_buffer, &endptr, 10);

  if (endptr == input_buffer || errno == ERANGE) {
    return nullptr;
  }

  if (option_num < 0 || (uintmax_t)option_num > (uintmax_t)SIZE_MAX) {
    return nullptr;
  }

  size_t n = (size_t)option_num;

  if (n >= options_count) {
    return nullptr;
  }

  MenuHandler handler = menu[n].handler;
  if (handler == nullptr) {
    return nullptr;
  }

  return handler;
}
