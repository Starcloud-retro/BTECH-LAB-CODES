//Merge One File to Another
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *f1, *f2;
    char s1[50], s2[50], ch;
    printf("\nEnter the Source File: ");
    scanf("%s", s1);
    f1 = fopen(s1,"a");
    printf("\nEnter Desitnation File: ");
    scanf("%s",s2);
    f2 = fopen(s2,"r");        
    if(f1 == NULL || f2 == NULL)
    {
        printf("\nError. File Not Found!");
    }
    else
    {
        while((ch == fgetc(f2))!=EOF)
        {

            fputc(ch, f1);
        }
    }
    fclose(f1);
    fclose(f2);
}