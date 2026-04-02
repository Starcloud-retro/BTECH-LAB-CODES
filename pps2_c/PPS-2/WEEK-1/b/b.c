//Write a C-Program to insert character at a given location in a given string.
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[30], s2[15], s3[15];
    int i, j, k, pos;
    printf("Enter a string: ");
    gets(s1); // Note: gets() is unsafe, consider using fgets() in real applications
    printf("Enter the sub-string to insert: ");
    gets(s2);
    printf("Enter the position to insert the character: ");
    scanf("%d", &pos);
    strcpy(s3,s1);
    for(i = pos, j = 0; j < strlen(s2); i++, j++)
    {
        s1[i]=s2[j];
    }
    for(j = pos, i = pos + strlen(s2); j < strlen(s3); i++, j++)
    {
        s1[i] = s3[j];
    }
    s1[i] = '\0';
    puts(s1);
    return 0;
}
