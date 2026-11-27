// src/main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "loader.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv){

    printf("Number of arguments: %d\n", argc);
    for(int num_argument=0; num_argument < argc; num_argument++){
        printf("%s\n", argv[num_argument]);
    }



return 0;
}
