//Copy One File to Another
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *f1, *f2;
    char s[50], d[50], ch;
    printf("\nEnter the Source File: ");
    scanf("%s", s);
    f1 = fopen(s,"r");
    if(f1 == NULL)
    {
        printf("\nError. File Not Found!");
    }
    else
    {
        printf("\nEnter Desitnation File: ");
        scanf("%s",d);
        f2 = fopen(d,"w");
        while((ch == fgetc(f1))!=EOF)
        {

            fputc(ch, f2);
        }
    }
    fclose(f1);
    fclose(f2);
}