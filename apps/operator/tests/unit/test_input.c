/**
 * @file test_input.c
 * @brief Test stdin input utils.
 */

#include "unity.h"

#include "input.h"

static constexpr char INPUT_TEXT[] = "Hello world\n";
static constexpr char EXPECTED[] = "Hello world";
static constexpr size_t INPUT_TEXT_LEN =
    sizeof INPUT_TEXT / sizeof INPUT_TEXT[0];
static constexpr size_t EXPECTED_LEN = sizeof EXPECTED / sizeof EXPECTED[0];

void setUp() {}

void tearDown() {}

static void test_get_input() {
  FILE *input = tmpfile();
  TEST_ASSERT_NOT_NULL(input);

  fputs(INPUT_TEXT, input);
  rewind(input);

  char out_buffer[INPUT_TEXT_LEN > EXPECTED_LEN ? INPUT_TEXT_LEN
                                                : EXPECTED_LEN] = {};
  size_t written = get_input(input, sizeof out_buffer, out_buffer, "Prompt: ");

  fclose(input);

  TEST_ASSERT_EQUAL_STRING(EXPECTED, out_buffer);
  TEST_ASSERT_EQUAL_INT(EXPECTED_LEN, written);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_get_input);

  return UNITY_END();
}
