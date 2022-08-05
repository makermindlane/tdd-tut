#include "CppUTest/TestHarness.h"

extern "C" {
#include "led_driver.h"
#include "runtime_error_stub.h"
}

TEST_GROUP(LedDriver) {
    u16 virtual_leds;
    void setup() { LedDriver_create(&virtual_leds); }
    void teardown() { LedDriver_destroy(); }
};

TEST(LedDriver, LedsAreOffAfterCreate) {
    virtual_leds = 0xffff;
    LedDriver_create(&virtual_leds);
    LONGS_EQUAL(0, virtual_leds);
}

TEST(LedDriver, TurnOnLedOne) {
    LedDriver_turn_on(1);
    LONGS_EQUAL(1, virtual_leds);
}

TEST(LedDriver, TurnOffLedOne) {
    LedDriver_turn_on_all();
    LedDriver_turn_off(1);
    LONGS_EQUAL(0xfffe, virtual_leds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
    LedDriver_turn_on(8);
    LedDriver_turn_on(9);
    LONGS_EQUAL(0x180, virtual_leds);
}

TEST(LedDriver, AllOn) {
    LedDriver_turn_on_all();
    LONGS_EQUAL(0xffff, virtual_leds);
}

TEST(LedDriver, TurnOffAnyLed) {
    LedDriver_turn_on_all();
    LedDriver_turn_off(8);
    LONGS_EQUAL(0xff7f, virtual_leds);
}

TEST(LedDriver, LedMemoryIsNotReadable) {
    virtual_leds = 0xffff;
    LedDriver_turn_on(8);
    LONGS_EQUAL(0x80, virtual_leds);
}

TEST(LedDriver, UpperAndLowerBounds) {
    LedDriver_turn_on(1);
    LedDriver_turn_on(16);
    LONGS_EQUAL(0x8001, virtual_leds);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm) {
    LedDriver_turn_on(-1);
    LedDriver_turn_on(0);
    LedDriver_turn_on(17);
    LedDriver_turn_on(3141);

    LONGS_EQUAL(0, virtual_leds);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm) {
    LedDriver_turn_on_all();

    LedDriver_turn_off(-1);
    LedDriver_turn_off(0);
    LedDriver_turn_off(17);
    LedDriver_turn_off(3141);

    LONGS_EQUAL(0xffff, virtual_leds);
}

TEST(LedDriver, OutOfBoundsProducesRuntimeError) {
    LedDriver_turn_on(-1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_get_last_error());
    LONGS_EQUAL(-1, RuntimeErrorStub_get_last_parameter());
}
