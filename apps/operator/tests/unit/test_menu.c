/**
 * @file test_menu.c
 * @brief Test TUI menu.
 */

#include "unity.h"

#include <stdio.h>

#include "menu.h"

static FILE *input_stream = nullptr;

[[nodiscard]] static bool test_handler(Socket agent) {
  (void)agent;
  return true;
}

static const MenuOption menu[] = {
    {"Test option", test_handler},
};

void setUp(void) {
  input_stream = tmpfile();
  TEST_ASSERT_NOT_NULL(input_stream);
}

void tearDown(void) {
  if (input_stream != nullptr) {
    fclose(input_stream);
    input_stream = nullptr;
  }
}

static void set_input(const char *text) {
  rewind(input_stream);
  clearerr(input_stream);

  TEST_ASSERT_TRUE(fputs(text, input_stream) >= 0);
  rewind(input_stream);
}

static void test_show_menu_returns_handler_for_valid_option(void) {
  set_input("0\n");

  MenuHandler handler =
      show_menu(input_stream, sizeof menu / sizeof menu[0], menu);

  TEST_ASSERT_EQUAL_PTR(test_handler, handler);
}

static void test_show_menu_returns_null_for_option_out_of_range(void) {
  set_input("1\n");

  MenuHandler handler =
      show_menu(input_stream, sizeof menu / sizeof menu[0], menu);

  TEST_ASSERT_NULL(handler);
}

static void test_show_menu_returns_null_for_non_numeric_input(void) {
  set_input("abc\n");

  MenuHandler handler =
      show_menu(input_stream, sizeof menu / sizeof menu[0], menu);

  TEST_ASSERT_NULL(handler);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_show_menu_returns_handler_for_valid_option);
  RUN_TEST(test_show_menu_returns_null_for_option_out_of_range);
  RUN_TEST(test_show_menu_returns_null_for_non_numeric_input);

  return UNITY_END();
}
