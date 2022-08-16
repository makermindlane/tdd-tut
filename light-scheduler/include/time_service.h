#pragma once

#include "data_type_defs.h"

typedef enum Day {
    DAY_UNKNOWN = -1,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
	EVERYDAY
} Day;

typedef struct Time {
    i32 minute_of_day;
    Day day_of_week;
} Time;

void TimeService_create();
void TimeService_get_time(Time *const self);
