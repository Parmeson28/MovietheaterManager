#include "movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_movie_catalog(MovieCatalog *catalog, size_t initial_capacity) {
    if (catalog == NULL || initial_capacity == 0) {
        return -1;
    }

    catalog->items = calloc(initial_capacity, sizeof(Movie));
    if (catalog->items == NULL) {
        catalog->count = 0;
        catalog->capacity = 0;
        return -1;
    }

    catalog->count = 0;
    catalog->capacity = initial_capacity;
    return 0;
}

void free_movie_catalog(MovieCatalog *catalog) {
    if (catalog == NULL) {
        return;
    }

    free(catalog->items);
    catalog->items = NULL;
    catalog->count = 0;
    catalog->capacity = 0;
}

int ensure_movie_capacity(MovieCatalog *catalog) {
    if (catalog->count < catalog->capacity) {
        return 0;
    }

    size_t new_capacity = catalog->capacity * 2;
    Movie *resized = realloc(catalog->items, new_capacity * sizeof(Movie));
    if (resized == NULL) {
        return -1;
    }

    catalog->items = resized;
    catalog->capacity = new_capacity;
    return 0;
}

int add_movie(MovieCatalog *catalog, char *name, int min_age) {
    if (catalog == NULL || name == NULL || name[0] == '\0' || min_age < 0) {
        return -1;
    }

    if (ensure_movie_capacity(catalog) != 0) {
        return -1;
    }

    Movie *m = &catalog->items[catalog->count];
    m->id = (int)catalog->count;
    snprintf(m->name, MAX_TITLE_LEN, "%s", name);
    m->min_age = min_age;
    m->total_audience = 0;

    catalog->count++;
    return m->id;
}

void print_movie(const Movie *movie) {
    if (movie == NULL) {
        printf("Invalid movie (NULL)\n");
        return;
    }

    printf("+----------------------------------+\n");
    printf("| ID..............: %u\n",        movie->id);
    printf("| Name............: %s\n",        movie->name ? movie->name : "(empty)");
    printf("| Minimum age.....: %u years\n",  movie->min_age);
    printf("| Audience count..: %u\n",        movie->audience_count);
    printf("| Weekday.........: %u (%s)\n",   movie->weekday);
    printf("+----------------------------------+\n");
}
