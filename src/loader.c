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
        fprintf(stderr, "\'%s\' cannot be opened.\n", file_name);
        exit(1);
    }


    // Go to end of file
    if(!(fseek(bf_ptr, 0, SEEK_END) == 0)){
        fprintf(stderr, "\'%s\' cannot be loaded.\n", file_name);
        exit(1);
    }



    // Get the position of the end of the file.
    long file_size = ftell(bf_ptr) + 1;
    if (file_size <= 0){
        fprintf(stderr, "\'%s\' cannot be loaded.\n", file_name);
        exit(1);
    }
    if(file_size == 1){
        fprintf(stdout, "\'%s\' is emtpy.\n", file_name);
    }



    // Allocate enough memory to load file into RAM (+1 to account for the offset of starting at 0)
    current_code.lines_of_code = (char*)calloc(file_size, sizeof(char));
    if(current_code.lines_of_code == NULL){
        fprintf(stderr, "Memory allocation error while loading \'%s\'\n", file_name);
        exit(1);
    }



    // Go to the beginning of the file
    if(fseek(bf_ptr, 0, SEEK_SET) != 0){
        fprintf(stderr, "\'%s\' cannot be loaded.",file_name);
        free(current_code.lines_of_code);
        exit(1);
    }



    // Load file into memory and process increase amount_of_lines
    int current_char = '\0'; // Keeps track of the character that is just read from the file
    int previous_char = '\0'; // Keeps track of the previous character that was read
    size_t file_pos = 0; // Keeps track of file postion
    current_code.amount_of_lines = 0;
    unsigned int len_of_line_buffer[BUFFER_SIZE]; // Buffer to keep the length of each line
    unsigned int pos_buffer[BUFFER_SIZE]; // Buffer to keep the position of each line

    while(TRUE){
        current_char = fgetc(bf_ptr);
        if(current_char == EOF){ // Checking for end of file
            if(file_pos == file_size - 1){
                printf("\'%s\' loaded.\n", file_name);
                current_code.lines_of_code[file_pos] = '\0';
                break;
            }
            else {
                fprintf(stderr, "Error reading \'%s\'.\n", file_name);
                free_basic_code(&current_code);
                exit(1);
            }
        }
        if((previous_char == '\n' || file_pos == 0) && (current_char != '\n' && current_char != EOF)){ // Checking if the current character is the start of a new line
            pos_buffer[current_code.amount_of_lines] = file_pos;
            current_code.amount_of_lines++;
        }
        current_code.lines_of_code[file_pos] = current_char;
        file_pos++;
        previous_char = current_char;
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


    free(code_to_free->lines_of_code);
    //free(code_to_free->len_of_line);
    //free(code_to_free->pos);
    return;
}
