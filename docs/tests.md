# Quickstart: Writing Tests for Neutron

This guide explains where Neutron's tests are located, how to follow the project's testing conventions, and how to check that a test detects an unexpected behavior change.

## Test locations

Applications are located in the `apps/` directory. Each application's tests are in `apps/<app-name>/tests/`.

End-to-end tests are located in `tests/e2e/` and check how applications work together.

## Write a test

Start by reading an existing test, such as [`test_packet_dispatcher.c`](../apps/agent/tests/unit/test_packet_dispatcher.c). Neutron uses the [Unity test framework](https://github.com/ThrowTheSwitch/Unity), so use Unity's test assertions rather than C's `assert()`.

Add a Doxygen comment to each test file. Include the file name and a brief description of what the tests cover.

## Check that a test detects behavior changes

A useful test should fail when the behavior it checks is changed or removed. To verify this, temporarily alter the relevant code so it no longer performs the behavior expected by the test, then build and run the tests. The test should fail. Revert the temporary change afterward and run the tests again to confirm they pass.

For instructions on building the project and running its tests, see the [developer quickstart](dev-quickstart.md).
