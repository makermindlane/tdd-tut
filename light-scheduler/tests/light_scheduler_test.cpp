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
