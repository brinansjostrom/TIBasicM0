// src/validator

#include <stdio.h>
#include <stdlib.h>
#include "validator.h"

struct basic_code build_parse(char *file_name){

    // Initialize the structure that holds the code that we will be compiling
    struct basic_code current_code; // Holds the code from the file
    current_code.num_lines = 0;

    // Open file ptr
    FILE* bf_ptr = fopen(file_name, "r"); // Opens and declares bf_ptr as the file ptr
    if(bf_ptr == NULL){
        fprintf(stderr, "File cannot be opened: %s\n", file_name);
        exit(1);
    }

    // Search file for '\n' characters to understand how many lines are in the BASIC code
    int char_current = 0; // Tracks the current character
    int char_previous = 0; // Tracks the previous character

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

    // Allocate memory for the length of the lines, and their position
    current_code.len_lines = (size_t*)malloc(current_code.num_lines * sizeof(size_t));
    if(current_code.len_lines == NULL){
        printf("Memory Allocation Error");
        exit(1);
    }

    current_code.file_pos = (size_t*)malloc(current_code.num_lines * sizeof(size_t));
    if(current_code.file_pos == NULL){
        printf("Memory Allocation Error");
        exit(1);
    }

    // Restart the file pointer
    rewind(bf_ptr);

    // Build out how long each line of code is
    // Also build out where the lines of code are in the file
    // This will allow us to allocate the the right amount in our current_code.line_code

    size_t file_pos = 0; // Tracks current file_pos
    size_t num_line = 0; // Tracks which line the next portion of code is on.
    char_current = 0;
    char_previous = 0;

    while(TRUE){

        char_current = fgetc(bf_ptr);

        if(char_current == EOF){
            break;
        }
        else if(char_current == '\n'){
            if(char_previous != '\n'){
             num_line++;
            }
        }
        else{
            if(char_previous == '\n'){
                current_code.file_pos[num_line] = file_pos;
            }
            current_code.len_lines[num_line]++;
        }

        char_previous = char_current;
        file_pos++;
    }

    // Close file ptr
    fclose(bf_ptr);

return current_code;
}
