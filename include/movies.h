#ifndef MOVIES_H
#define MOVIES_H

#include <stdint.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LEN 100

typedef struct {
    uint8_t id;
    char name[MAX_TITLE_LEN];
    uint8_t min_age;
    uint16_t total_audience;
} Movie;

void print_movie(Movie * movie);
#endif
