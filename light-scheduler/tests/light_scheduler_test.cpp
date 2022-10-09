#include "CppUTest/TestHarness.h"

extern "C" {
#include "data_type_defs.h"
#include "light_controller_spy.h"
#include "light_scheduler.h"
#include "fake_time_service.h"
}

TEST_GROUP(LightScheduler) {
	void setup() {
		LightController_create();
		LightScheduler_create();
	}

	void teardown() {
		LightController_destroy();
		LightScheduler_destroy();
	}
};

TEST(LightScheduler, NoChangeToLightsDuringInitialization) {
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_get_last_id());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_get_last_state());
}

TEST(LightScheduler, NoScheduleNothingHappens) {
    FakeTimeService_set_day(MONDAY);
    FakeTimeService_set_minute(100);

    LightScheduler_wakeup();

    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_get_last_id());
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_get_last_state());
}

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet) {
    LightScheduler_schedule_turn_on(3, EVERYDAY, 1200);
    FakeTimeService_set_day(MONDAY);
    FakeTimeService_set_minute(1199);

    LightScheduler_wakeup();

    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_get_last_id());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_get_last_state());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime) {
    LightScheduler_schedule_turn_on(3, EVERYDAY, 1200);
    FakeTimeService_set_day(MONDAY);
    FakeTimeService_set_minute(1200);

    LightScheduler_wakeup();
    LONGS_EQUAL(3, LightControllerSpy_get_last_id());
    LONGS_EQUAL(LIGHT_ON, LightControllerSpy_get_last_state());
}
