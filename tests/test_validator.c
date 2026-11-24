#include <assert.h>
#include "validator.h"

int main(){

    // Stage Test file
    char* test_file = "test_code.bas";

    //Initialize expected outputs
    struct basic_code expected_basic_code;
    expected_basic_code.num_lines = 2;

    // Produce actual output
    struct basic_code actual_basic_code = build_parse(test_file);

    // Test Case: Check if the code is counting correct lines of code
    assert(actual_basic_code.num_lines == expected_basic_code.num_lines);
    printf("actual_basic_code.num_lines = %zu\nexpected_basic_code.num_lines = %zu\n",
        actual_basic_code.num_lines,
        expected_basic_code.num_lines);


    return 0;
}
