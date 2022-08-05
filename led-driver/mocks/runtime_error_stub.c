#include "runtime_error_stub.h"

static const char *message = "No Error";
static i32 parameter = -1;
static const char *file = 0;
static i32 line = -1;

void RuntimeErrorStub_reset() {
    message = "No Error";
    parameter = -1;
}

const char *RuntimeErrorStub_get_last_error() { return message; }

void RuntimeError(const char *m, i32 p, const char *f, i32 l) {
    message = m;
    parameter = p;
    file = f;
    line = l;
}

i32 RuntimeErrorStub_get_last_parameter() { return parameter; }
