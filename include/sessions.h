#ifndef SESSIONS_H
#define SESSIONS_H

#include <stdint.h>
#include <stddef.h>
#include "movies.h"

#define INITIAL_SESSION_CAPACITY 8

typedef struct {
    uint8_t id;
    uint8_t movie_id;          
    uint8_t weekday;            
    int start_hour;       
    uint16_t audience;         
    int accumulated_audience;
} Session;

typedef struct {
    Session *items;          
    size_t count;         
    size_t capacity;      
} SessionSchedule;

int init_session_schedule(SessionSchedule *schedule, size_t initial_capacity);
void free_session_schedule(SessionSchedule *schedule);
char *weekday_name(int weekday);
int add_session(SessionSchedule *schedule, MovieCatalog *catalog, uint8_t movie_id, uint8_t weekday, int start_hour, uint16_t audience);
void print_session(Session *session, Movie *movie);
void print_schedule(SessionSchedule *schedule, MovieCatalog *catalog);

#endif
