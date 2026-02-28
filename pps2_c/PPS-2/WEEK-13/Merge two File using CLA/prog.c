//Copy Data from One File to Another
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
    FILE *f, *p;
    char c;
    f = fopen(argv[1], "a");
    p = fopen(argv[2], "r");
    while((c = fgetc(p)) != EOF)
    {
        fputc(c, f);
    }
    printf("\nMerged Successfully!");
    fclose(f);
    fclose(p);
}
