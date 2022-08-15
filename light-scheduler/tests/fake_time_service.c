#include "fake_time_service.h"

static Time time;

void TimeService_create() {
	time.minute_of_day = TIME_UNKNOWN;
	time.day_of_week = DAY_UNKNOWN;
}

void TimeService_get_time(Time *const self) {
    self->minute_of_day = time.minute_of_day;
    self->day_of_week = time.day_of_week;
}

void FakeTimeService_set_minute(i32 minute) { time.minute_of_day = minute; }

void FakeTimeService_set_day(Day day) { time.day_of_week = day; }
