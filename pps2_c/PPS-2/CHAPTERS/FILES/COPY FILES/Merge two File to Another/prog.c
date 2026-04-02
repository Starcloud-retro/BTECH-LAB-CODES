//Merge Two Files to Another
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *f1, *f2, *f3;
    char s1[50], s2[50], s3[100], ch;
    printf("\nEnter the File1: ");
    scanf("%s", s1);
    f1 = fopen(s1,"r");
    printf("\nEnter the File2: ");
    scanf("%s",s2);
    f2 = fopen(s2,"r");
    printf("Enter the Destination File: ");
    scanf("%s",s3);
    f3 = fopen(s3,"a");
    if(f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("\nError. File Not Found!");
    }
    else
    {
        while((ch == fgetc(f1))!=EOF)
        {

            fputc(ch, f3);
        }
        while((ch == fgetc(f2))!=EOF)
        {

            fputc(ch, f3);
        }

    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}