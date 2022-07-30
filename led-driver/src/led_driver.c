#include "led_driver.h"

enum { ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON };

/****************************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ***************************************************************************************/
static u16 num_to_bit(i32 num);

/****************************************************************************************
 * GLOBAL PRIVATE VARIABLES
 ***************************************************************************************/
static u16* leds_address;

/****************************************************************************************
 * PUBLIC FUNCTION DEFINITIONS
 ***************************************************************************************/

void LedDriver_create(u16* address) {
    leds_address = address;
    *leds_address = ALL_LEDS_OFF;
}
void LedDriver_destroy() {}

void LedDriver_turn_on(i32 led_number) { *leds_address |= num_to_bit(led_number); }

void LedDriver_turn_on_all() { *leds_address = ALL_LEDS_ON; }

void LedDriver_turn_off(i32 led_number) { *leds_address &= num_to_bit(led_number); }

/****************************************************************************************
 * PRIVATE FUNCTION DEFINITIONS
 ***************************************************************************************/

static u16 num_to_bit(i32 num) { return 1 << (num - 1); }
