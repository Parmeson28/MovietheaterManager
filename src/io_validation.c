#include "io_validation.h"
#include <stdio.h>
#include <string.h>

void clear_stdin_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        
    }
}

int is_valid_weekday(int weekday) {
    return (weekday >= 1 && weekday <= 7) ? 1 : 0;
}

int is_valid_audience(int audience) {
    return (audience >= 0) ? 1 : 0;
}
