// include/validator.h
#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

// Create structure to store lines of code and how many lines of code there are.
struct basic_code{
    char* lines_of_code;
    size_t amount_of_lines;
    size_t* len_of_line;
    size_t* pos;
};

// Parses file, producing a list ptr to strings.
void build_parse(char*, struct basic_code*);

// Frees the basic code
void free_basic_code(struct basic_code*);

#endif
