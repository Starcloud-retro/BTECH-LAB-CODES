//Copy Data from One File to Another
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *f1, *f2;
    char s[20], d[20], ch;
    printf("Enter Source File: ");
    scanf("%s ",s);
    f1 = fopen(s,"r");
    if(f1 == NULL)
        printf("File Not Found!");
    else
    {
        printf("Enter desired File: ");
        scanf("%s",d);
        f2 = fopen(d,"w");
        while((ch = fgetc(f1)) != EOF)
        {
            fputc(ch, f2);
        }
    }
    fclose(f1);
    fclose(f2);
}
