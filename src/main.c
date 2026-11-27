#include <stdio.h>
#include <stdint.h>
#include "movies.h"
#include "sessions"

static void scan_movie(MovieCatalog * c){
    int min_age;
    char name[MAX_TITLE_LEN];
    printf("digita ai para eu ver uma parada:\n");
    scanf("%d %s", &min_age, name);
    if(add_movie(c, name, min_age) != 0) printf("deu certo");
    
}


int main(){
    
    return 0;
}
