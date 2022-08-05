#pragma once

#include "data_type_defs.h"

void RuntimeError(const char *message, i32 parameter, const char *file, i32 line);

#define RUNTIME_ERROR(description, parameter) \
    RuntimeError(description, parameter, __FILE__, __LINE__)
