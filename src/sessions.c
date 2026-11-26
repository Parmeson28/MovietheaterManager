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

int add_session(SessionSchedule *schedule, MovieCatalog *catalog, int movie_id, int weekday, int start_hour, int audience) {
    if(schedule == NULL) return -1;
    if(catalog == NULL) return -1;

    Movie *movie = find_movie_by_id(catalog, movie_id);
    if (movie == NULL) return -2;

    if(audience < 0) return -3;
    if(weekday < 1 || weekday > 7) return -3;

    if (ensure_session_capacity(schedule) != 0) return -1;
    
    movie->total_audience += audience;

    Session *s = &schedule->items[schedule->count];
    s->id = (int)schedule->count;
    s->movie_id = movie->id;
    s->weekday = weekday;
    s->start_hour = start_hour;
    s->audience = audience;
    s->accumulated_audience = movie->total_audience;

    schedule->count++;
    return s->id;
    
}

void print_session(const Session *session, const Movie *movie) {
    if (session == NULL) {
        return;
    }

    const char *title = (movie != NULL) ? movie->name : "(Filme removido)";
    int min_age = (movie != NULL) ? movie->min_age : 0;

    printf("%-14s %-12d %-14s %02dh %10d pessoas %11d pessoas\n",
           title,
           min_age,
           weekday_name(session->weekday),
           session->start_hour,
           session->audience,
           session->accumulated_audience);
}

