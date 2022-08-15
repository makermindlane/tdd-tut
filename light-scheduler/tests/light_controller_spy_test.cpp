#include "CppUTest/TestHarness.h"

extern "C" {
#include "data_type_defs.h"
#include "light_controller_spy.h"
}

TEST_GROUP(LightControllerSpy) {
	void setup() {
		LightController_create();
	}

	void teardown() { 
		LightController_destroy(); 
	}
};

TEST(LightControllerSpy, Create) {
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_get_last_id());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_get_last_state());
}

TEST(LightControllerSpy, RememberTheLastLightIdControlled) {
	LightController_on(10);
	LONGS_EQUAL(10, LightControllerSpy_get_last_id());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_get_last_state());
}
