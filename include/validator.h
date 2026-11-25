// include/validator.h
#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

// Create structure to store lines of code and how many lines of code there are.
struct basic_code{
    char** lines_of_code;
    size_t num_lines;
    size_t *len_lines;
    size_t *file_pos;
};

// Parses file, producing a list ptr to strings.
struct basic_code build_parse(char*);
// Frees the basic code
void free_basic_code(struct basic_code);

#endif
