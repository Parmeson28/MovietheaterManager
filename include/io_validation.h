#ifndef IO_VALIDATION_H
#define IO_VALIDATION_H

#include <stddef.h>
#include "movies.h"

void clear_stdin_buffer(void);
int read_int(char *prompt, int *out_value);
int read_int_in_range(char *prompt, int min_val, int max_val, int *out_value);
int read_line(char *prompt, char *buffer, size_t size);

int is_valid_weekday(int weekday);
int is_valid_audience(int audience);
Movie *validate_existing_movie(MovieCatalog *catalog, int movie_id);

#endif
