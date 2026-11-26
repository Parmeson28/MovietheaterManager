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

void free_session_schedule(SessionSchedule *schedule) {
    if(schedule == NULL){
        return;
    }

    free(schedule->items);
    schedule->items = NULL;
    schedule->count = 0;
    schedule->capacity = 0;
    
}

char *weekday_name(int weekday) {
    switch (weekday) {
        case 1: return "Domingo";
        case 2: return "Segunda";
        case 3: return "Terca";
        case 4: return "Quarta";
        case 5: return "Quinta";
        case 6: return "Sexta";
        case 7: return "Sabado";
        default: return "Desconhecido";
    }
}

static int ensure_session_capacity(SessionSchedule *schedule) {
    if (schedule->count < schedule->capacity) {
        return 0;
    }

    size_t new_capacity = schedule->capacity * 2;
    Session *resized = realloc(schedule->items, new_capacity * sizeof(Session));
    if (resized == NULL) {
        return -1;
    }

    schedule->items = resized;
    schedule->capacity = new_capacity;
    return 0;
}
