#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv){

    printf("Number of arguments: %d\n", argc);
    for(int i=0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    // Open file
    FILE* _bf_ptr = fopen(argv[1], "r");
    if(_bf_ptr == NULL){
        fprintf(stderr, "File cannot be opened: %s\n", argv[1]);
        return 1;
    }

    // Check file for appropriate symbols
    // + (Add 1 to the current cell. If the cell is at 255, it wraps back to 0.)
    // - (Subtract 1 from the current cell. If the cell is at 0, it wraps to 255.)
    // > (Move the pointer one cell to the right.)
    // < (Move the pointer one cell to the left.)
    // . (Print the current cell's value as an ASCII character. For example, 72 prints H, 101 prints e.)
    // , (Read one byte of input and store its value in the current cell.)
    // [ (If the current cell is 0, skip ahead to the instruction after the matching ]. Otherwise, continue into the loop.)
    // ] (If the current cell is not 0, jump back to the matching [. Otherwise, continue past the loop.)
    char _check_char;
    char _instruction_list[] = {'+', '-', '>', '<', '.', ',', '[', ']'};
    while(TRUE){
        _check_char = fgetc(_bf_ptr);
        fprintf(stdout, "%c", _check_char);
        if(_check_char == EOF) {break;} // Stop at end of file
        for(int instruction = 0; instruction<(sizeof(_instruction_list)/sizeof(char))+1;instruction++){

            // Breaks if the current character is a valid bf instruction
            if(_check_char == _instruction_list[instruction]) {break;}

            // If not a valid instruction returns an error
            if(instruction == (sizeof(_instruction_list)/sizeof(char))){
                fprintf(stderr, "Not valid instruction: %i\n", (int)_check_char);
                fprintf(stderr, "Test: %i\n", (int)'\n');
                    return 1;
            }
        }
    }


    // Close file pointer
    fclose(_bf_ptr);

return 0;
}
