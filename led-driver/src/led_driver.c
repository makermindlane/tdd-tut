#include "led_driver.h"

#include <stdbool.h>

#include "runtime_error.h"

enum { ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON };
enum { FIRST_LED = 1, LAST_LED = 16 };

/****************************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ***************************************************************************************/
static u16 num_to_bit(i32 num);
static void update_hardware();
static bool is_led_out_of_bounds(i32 led_number);
static void set_led_image_bit(i32 led_number);
static void clear_led_image_bit(i32 leds_number);

/****************************************************************************************
 * GLOBAL PRIVATE VARIABLES
 ***************************************************************************************/
static u16* leds_address;
static u16 leds_image;

/****************************************************************************************
 * PUBLIC FUNCTION DEFINITIONS
 ***************************************************************************************/

void LedDriver_create(u16* address) {
    leds_address = address;
    leds_image = ALL_LEDS_OFF;
    update_hardware();
}
void LedDriver_destroy() {}

void LedDriver_turn_on(i32 led_number) {
    if (is_led_out_of_bounds(led_number)) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", led_number);
        return;
    }

    set_led_image_bit(led_number);
    update_hardware();
}

void LedDriver_turn_on_all() {
    leds_image = ALL_LEDS_ON;
    update_hardware();
}

void LedDriver_turn_off(i32 led_number) {
    if (is_led_out_of_bounds(led_number)) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", led_number);
        return;
    }

    clear_led_image_bit(led_number);
    update_hardware();
}

/****************************************************************************************
 * PRIVATE FUNCTION DEFINITIONS
 ***************************************************************************************/

static u16 num_to_bit(i32 num) { return 1 << (num - 1); }

static void update_hardware() { *leds_address = leds_image; }

static bool is_led_out_of_bounds(i32 led_number) {
    if (led_number < FIRST_LED || led_number > LAST_LED) {
        return true;
    } else {
        return false;
    }
}

static void set_led_image_bit(i32 led_number) { leds_image |= num_to_bit(led_number); }

static void clear_led_image_bit(i32 leds_number) {
    leds_image &= ~num_to_bit(leds_number);
}
