// src/validator

#include <stdio.h>
#include <stdlib.h>
#include "loader.h"

void load_file(char *file_name, struct basic_code *current_code_ptr){

    // Initialize the structure that holds the code that we will be compiling
    struct basic_code current_code; // Holds the code from the file

    // Open file ptr
    FILE* bf_ptr = fopen(file_name, "r"); // Opens and declares bf_ptr as the file ptr
    if(bf_ptr == NULL){
        fprintf(stderr, "File cannot be opened: %s\n", file_name);
        exit(1);
    }




    // Close file ptr
    if(fclose(bf_ptr) == EOF){
       fprintf(stderr, "File cannot be closed: %s\n", file_name);
       free_basic_code(&current_code);
       exit(1);
    }

    *current_code_ptr = current_code;
    return;
}


void free_basic_code(struct basic_code *code_to_free){

    /* later for the char** lines_of_code variable :)
    size_t num_lines = code_to_free->num_lines;
    for(int i = 0; i < num_lines;i++){
        free(code_to_free->lines_of_code[i]);
    }

    free(code_to_free->lines_of_code);
    free(code_to_free->len_lines);
    free(code_to_free->file_pos);*/
    return;
}
