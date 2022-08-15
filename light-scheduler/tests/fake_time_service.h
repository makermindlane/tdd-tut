#pragma once

#include "time_service.h"

enum {
    TIME_UNKNOWN = -1,
};

void FakeTimeService_set_minute(i32 minute);
void FakeTimeService_set_day(Day day);
