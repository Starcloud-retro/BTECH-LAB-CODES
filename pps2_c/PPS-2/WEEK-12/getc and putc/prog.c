//use of fgetc, fputc
#include<stdio.h>
void main()
{
    //fputc
    FILE *f;
    char c;
    f = fopen("ram.txt", "w");
    printf("Enter Text: ");
    while((c = getchar()) != EOF)
        fputc(c,f);
    fclose(f);
    
    

    //fgetc
    f = fopen("ram.txt", "r");
    while((c = fgetc(f)) != EOF)
        printf("%c",c);
    fclose(f);
}
