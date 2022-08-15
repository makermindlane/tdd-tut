#include "light_controller_spy.h"

#include "light_controller.h"

static i32 last_id;
static i32 last_state;

void LightController_create() {
    last_id = LIGHT_ID_UNKNOWN;
    last_state = LIGHT_STATE_UNKNOWN;
}

void LightController_destroy() {
	
}

void LightController_on(i32 id) {
    last_id = id;
    last_state = LIGHT_ON;
}

void LightController_off(i32 id) {
    last_id = id;
    last_state = LIGHT_OFF;
}

i32 LightControllerSpy_get_last_id() { return last_id; }

i32 LightControllerSpy_get_last_state() { return last_state; }
