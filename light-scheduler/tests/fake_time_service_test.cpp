#include "CppUTest/TestHarness.h"

extern "C" {
#include "data_type_defs.h"
#include "fake_time_service.h"
}

TEST_GROUP(FakeTimeService){void setup(){
	TimeService_create();
} void teardown(){}};

TEST(FakeTimeService, Create) {
    Time time;
    TimeService_get_time(&time);

    LONGS_EQUAL(TIME_UNKNOWN, time.minute_of_day);
    LONGS_EQUAL(DAY_UNKNOWN, time.day_of_week);
}

TEST(FakeTimeService, Set) {
    Time time;
    FakeTimeService_set_minute(42);
    FakeTimeService_set_day(SATURDAY);

    TimeService_get_time(&time);

    LONGS_EQUAL(42, time.minute_of_day);
    LONGS_EQUAL(SATURDAY, time.day_of_week);
}
