#include "light_scheduler.h"

#include "light_controller.h"

enum { UNUSED = -1 };

typedef struct ScheduledLightEvent {
    i32 id;
    i32 minute_of_day;
} ScheduledLightEvent;

static ScheduledLightEvent scheduled_event;

void LightScheduler_create() { scheduled_event.id = UNUSED; }

void LightScheduler_destroy() {}

void LightScheduler_wakeup() {
    Time time;
    TimeService_get_time(&time);

    if (scheduled_event.id == UNUSED) return;

    if (time.minute_of_day != scheduled_event.minute_of_day) return;

    LightController_on(scheduled_event.id);
}

void LightScheduler_schedule_turn_on(i32 id, Day day, i32 minute_of_day) {
    scheduled_event.id = id;
    scheduled_event.minute_of_day = minute_of_day;
}
