#include "input.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_input(FILE *input, size_t out_len, char out[static out_len],
                 const char *prompt) {
  if (input == nullptr) {
    return 0;
  }

  if (prompt) {
    fputs(prompt, stdout);
  }

  size_t len = 0;
  int n = out_len > INT_MAX ? INT_MAX : (int)out_len;

  if (fgets(out, n, input) != NULL) {
    len = strlen(out);
    out[len - 1] = '\0';
  }

  return len;
}
