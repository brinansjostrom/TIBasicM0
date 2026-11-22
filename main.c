#INCLUDE <stdio.h>
#INCLUDE <stdlib.h>
#INCLUDE <time.h>

const char* _base_code = "#include <stdio.h>/nint main(){";
#DEFINE _START_CODE sizeof(_base_code)

int main(int argc, char **argv){

    printf("Number of arguments: %d\n", argc);
    for(int i=0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    // Open file
    FILE* _bf_ptr = fopen(argv[1], "r");
    if(_bf_ptr == NULL){
        printf("File cannot be read");
        return 1;
    }



    // Close file pointer
    fclose(_bf_ptr);

return 0;
}
