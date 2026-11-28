// include/loader.h
#ifndef _LOADER_H_
#define _LOADER_H_

#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 256


// Create structure to store lines of code and how many lines of code there are.
struct basic_code{
    char* lines_of_code;
    size_t amount_of_lines;
    size_t* len_of_line;
    size_t* pos;
};

// loads file into the second argument, the first argument is the file name
// The goal of this function is to load the file into memory
void load_file(char*, struct basic_code*);

// Frees the basic_code struct
void free_basic_code(struct basic_code*);

#endif
