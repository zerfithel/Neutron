/**
 * @file test_packet_dispatcher.c
 * @brief Tests packet dispatching for supported and unsupported packet types.
 */

#include "unity.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "packet_dispatcher.h"

static constexpr char PAYLOAD[] = "firefox";

static bool callback_called = false;

void setUp(void) {
  callback_called = false;
}

void tearDown(void) {
}

static bool fake_execute_command(const char *command) {
  callback_called = true;
  TEST_ASSERT_NOT_NULL(command);
  TEST_ASSERT_EQUAL_INT(0, strcmp(command, PAYLOAD));

  return true;
}

static void test_dispatch_PacketTypeExecute_valid_packet(void) {
  const XSocketPacket packet = {
      .payload = (const uint8_t *)PAYLOAD,
      .payload_len = sizeof PAYLOAD - 1,
      .type = XSOCKET_PACKET_TYPE_EXECUTE,
  };

  dispatch_packet(&packet, fake_execute_command);

  TEST_ASSERT_TRUE(callback_called);
}

static void test_dispatch_PacketTypeUnknown_invalid_type(void) {
  const XSocketPacket packet = {
      .payload = (const uint8_t *)PAYLOAD,
      .payload_len = sizeof PAYLOAD - 1,
      .type = XSOCKET_PACKET_TYPE_UNKNOWN,
  };

  dispatch_packet(&packet, fake_execute_command);

  TEST_ASSERT_FALSE(callback_called);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_dispatch_PacketTypeExecute_valid_packet);
  RUN_TEST(test_dispatch_PacketTypeUnknown_invalid_type);

  return UNITY_END();
}

