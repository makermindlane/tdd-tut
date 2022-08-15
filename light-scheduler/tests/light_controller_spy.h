#pragma once

// light_controller_spy is an implementation of light_controller interface
#include "light_controller.h"

#include "data_type_defs.h"

enum { LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1, LIGHT_OFF = 0, LIGHT_ON = 1 };

i32 LightControllerSpy_get_last_id();
i32 LightControllerSpy_get_last_state();
