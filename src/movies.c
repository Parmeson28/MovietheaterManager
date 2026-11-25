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
