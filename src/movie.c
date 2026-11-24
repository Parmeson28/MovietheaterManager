#include "movie.h"
#include <stdio.h>

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
