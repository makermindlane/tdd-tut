#include "led_driver.h"

enum { ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON };

/****************************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ***************************************************************************************/
static u16 num_to_bit(i32 num);
static void update_hardware();

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
    leds_image |= num_to_bit(led_number);
    update_hardware();
}

void LedDriver_turn_on_all() {
    leds_image = ALL_LEDS_ON;
    update_hardware();
}

void LedDriver_turn_off(i32 led_number) {
    leds_image &= ~num_to_bit(led_number);
    update_hardware();
}

/****************************************************************************************
 * PRIVATE FUNCTION DEFINITIONS
 ***************************************************************************************/

static u16 num_to_bit(i32 num) { return 1 << (num - 1); }

static void update_hardware() { *leds_address = leds_image; }
