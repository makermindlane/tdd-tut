#pragma once

#include "data_type_defs.h"

typedef enum Day {
    DAY_UNKNOWN = -1,
    EVERYDAY = 10,
    WEEKDAY,
    WEEKEND,
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;

void LightScheduler_create();
void LightScheduler_destroy();
void LightScheduler_wakeup();
void LightScheduler_schedule_turn_on(i32 id, Day day, i32 minute_of_day);
void LightScheduler_schedule_turn_off(i32 id, Day day, i32 minute_of_day);
