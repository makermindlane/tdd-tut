#pragma once

#include "data_type_defs.h"

void LedDriver_create(u16 *address);
void LedDriver_destroy();
void LedDriver_turn_on(i32 ledNumber);
void LedDriver_turn_on_all();
void LedDriver_turn_off(i32 ledNumber);