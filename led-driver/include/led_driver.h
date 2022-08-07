#pragma once

#include <stdbool.h>

#include "data_type_defs.h"

void LedDriver_create(u16 *address);
void LedDriver_destroy();
void LedDriver_turn_on(i32 ledNumber);
void LedDriver_turn_on_all();
void LedDriver_turn_off_all();
void LedDriver_turn_off(i32 ledNumber);
bool LedDriver_is_on(i32 led_number);
bool LedDriver_is_off(i32 led_number);
