#include "sessions.h"
#include <stdio.h>
#include <stdlib.h>

int init_session_schedule(SessionSchedule *schedule, size_t initial_capacity) {
    if (schedule == NULL || initial_capacity == 0) {
        return -1;
    }

    schedule->items = calloc(initial_capacity, sizeof(Session));
    if (schedule->items == NULL) {
        schedule->count = 0;
        schedule->capacity = 0;
        return -1;
    }

    schedule->count = 0;
    schedule->capacity = initial_capacity;
    return 0;
}

