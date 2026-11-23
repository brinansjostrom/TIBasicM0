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


    // Close file pointer
    fclose(_bf_ptr);

return 0;
}
