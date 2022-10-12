#include "light_scheduler.h"
#include "light_controller.h"
#include "time_service.h"

enum { UNUSED = -1 };

typedef enum Event {
    TURN_OFF, TURN_ON
} Event;

typedef struct ScheduledLightEvent {
    i32 id;
    i32 minute_of_day;
    Event event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduled_event;

void LightScheduler_create() { scheduled_event.id = UNUSED; }

void LightScheduler_destroy() {}

void LightScheduler_wakeup() {
    Time time;
    TimeService_get_time(&time);

    if (scheduled_event.id == UNUSED) return;

    if (time.minute_of_day != scheduled_event.minute_of_day) return;

    if (scheduled_event.event == TURN_ON) {
        LightController_on(scheduled_event.id);
    } else if (scheduled_event.event == TURN_OFF) {
        LightController_off(scheduled_event.id);
    }

}

void LightScheduler_schedule_turn_on(i32 id, Day day, i32 minute_of_day) {
    scheduled_event.id = id;
    scheduled_event.minute_of_day = minute_of_day;
    scheduled_event.event = TURN_ON;
}

void LightScheduler_schedule_turn_off(i32 id, Day day, i32 minute_of_day) {
    scheduled_event.id = id;
    scheduled_event.minute_of_day = minute_of_day;
    scheduled_event.event = TURN_OFF;
}
