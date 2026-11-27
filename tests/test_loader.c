#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "loader.h"

int main(){

    // Stage Test file
    char* test_file = "test_code.bas";

    // Initialize expected outputs
    struct basic_code expected_basic_code;
        expected_basic_code.num_lines = 2;

        //initialize expected outputs for len_lines
        expected_basic_code.len_lines = malloc(expected_basic_code.num_lines * sizeof(size_t));
        expected_basic_code.len_lines[0] = 13;
        expected_basic_code.len_lines[1] = 12;

        //initialize_expected output for file_pos
        expected_basic_code.file_pos = malloc(expected_basic_code.num_lines * sizeof(size_t));
        expected_basic_code.file_pos[0] = 0;
        expected_basic_code.file_pos[1] = 16;

    // Produce actual output

    struct basic_code actual_basic_code;
    build_parse(test_file, &actual_basic_code);

    // Test Case: Check if the code is counting correct lines of code
    assert(actual_basic_code.num_lines == expected_basic_code.num_lines);
    /* printf("actual_basic_code.num_lines = %zu\nexpected_basic_code.num_lines = %zu\n",
        actual_basic_code.num_lines,
        expected_basic_code.num_lines); */

    //test_case: File_pos and the len_lines
    for(int i = 0; i<expected_basic_code.num_lines; i++){

        /*printf("actual_basic_code.len_lines[%d] = %zu\nexpected_basic_code.len_lines[%d] = %zu\n",
            i,
            actual_basic_code.len_lines[i],
            i,
            expected_basic_code.len_lines[i]);*/
        assert(expected_basic_code.len_lines[i] == actual_basic_code.len_lines[i]);


        /*printf("actual_basic_code.file_pos[%d] = %zu\nexpected_basic_code.file_pos[%d] = %zu\n",
            i,
            actual_basic_code.file_pos[i],
            i,
            expected_basic_code.file_pos[i]);*/
        assert(expected_basic_code.file_pos[i] == actual_basic_code.file_pos[i]);
    }

    // free the code
    free_basic_code(&actual_basic_code);
    free_basic_code(&expected_basic_code);
    return 0;
}
