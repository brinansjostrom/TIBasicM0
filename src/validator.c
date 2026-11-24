// src/validator

#include <stdio.h>
#include <stdlib.h>
#include "validator.h"

struct basic_code build_parse(char *file_name){

    // Initialize the structure that holds the code that we will be compiling
    struct basic_code current_code;
    current_code.num_lines = 0;

    // Open file ptr
    FILE* bf_ptr = fopen(file_name, "r");
    if(bf_ptr == NULL){
        fprintf(stderr, "File cannot be opened: %s\n", file_name);
        exit(1);
    }

    // Search file for '\n' characters to understand how many lines are in the BASIC code
    char char_current = 0;
    char char_previous = 0;
    while(TRUE){
        char_current = fgetc(bf_ptr);
        if(char_current == EOF){
            if(char_previous != '\n'){
                current_code.num_lines++;
            }

            break;
        }
        if(char_current == '\n'){
            if(char_previous != '\n'){
                current_code.num_lines++;
            }
        }
        char_previous = char_current;
    }


    // Close file ptr
    fclose(bf_ptr);

return current_code;
}
