#ifndef MOVIE_H
#define MOVIE_H

#include <stdint.h>

typedef struct {
    uint8_t id;
    char *name;
    uint8_t min_age;
    uint8_t audience_count;
    uint8_t weekday; 
} Movie;

void print_movie(Movie * movie);
#endif
