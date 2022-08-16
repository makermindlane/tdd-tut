#pragma once

#include "data_type_defs.h"
#include "time_service.h"

void LightScheduler_create();
void LightScheduler_destroy();
void LightScheduler_wakeup();
void LightScheduler_schedule_turn_on(i32 id, Day day, i32 minute_of_day);
