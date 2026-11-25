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

int init_movie_catalog(MovieCatalog *catalog, size_t initial_capacity);
void free_movie_catalog(MovieCatalog *catalog);
int add_movie(MovieCatalog *catalog, char *name, int min_age);
Movie *find_movie_by_id(MovieCatalog *catalog, int id);
void print_movie(Movie *movie);

#endif
