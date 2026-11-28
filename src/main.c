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
    if(argv[1] == NULL){
        printf("No argument given.\n");
        exit(1);
    }
    // Initialize and load basic code
    struct basic_code loaded_code;
    load_file(argv[1], &loaded_code);

    printf("%s\n", loaded_code.lines_of_code);
    printf("%zu\n", loaded_code.amount_of_lines);
    // FREE THE HEAP
    free_basic_code(&loaded_code);
return 0;
}
