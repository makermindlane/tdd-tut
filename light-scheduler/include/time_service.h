#pragma once

#include "data_type_defs.h"
#include "light_scheduler.h"

typedef struct Time {
    i32 minute_of_day;
    Day day_of_week;
} Time;

void TimeService_create();
void TimeService_get_time(Time *const self);
