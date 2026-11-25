#ifndef SESSIONS_H
#define SESSIONS_H

#include <stdint.h>
#include <stddef.h>
#include "movies.h"

#define MAX_SESSIONS 200

typedef struct {
    int id;
    Movie *movie;   
    int weekday;   
    int start_hour; 
    int audience;   
} Session;

typedef struct {
    Session items[MAX_SESSIONS];
    size_t count;
} SessionSchedule;

void print_session(Session *session, int accumulated_audience);
void print_schedule(SessionSchedule *schedule);

#endif
