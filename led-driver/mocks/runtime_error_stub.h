#pragma once

#include "data_type_defs.h"
#include "runtime_error.h"

void RuntimeErrorStub_reset();

const char *RuntimeErrorStub_get_last_error();

i32 RuntimeErrorStub_get_last_parameter();
