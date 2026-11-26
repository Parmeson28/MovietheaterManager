#include "io_validation.h"
#include <stdio.h>
#include <string.h>

void clear_stdin_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        
    }
}
