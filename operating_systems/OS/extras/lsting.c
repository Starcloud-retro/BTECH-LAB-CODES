#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char* argv[]) {
    FILE *file_pointer;
    char character;

    file_pointer = fopen(argv[1], "r");

    if (file_pointer == NULL) {
        printf("Error: Could not open file %s\\n", argv[1]);
        return 1;
    }

    while ((character = fgetc(file_pointer)) != EOF) {
        printf("%c", character);
    }
    fclose(file_pointer);
    return 0;
}
