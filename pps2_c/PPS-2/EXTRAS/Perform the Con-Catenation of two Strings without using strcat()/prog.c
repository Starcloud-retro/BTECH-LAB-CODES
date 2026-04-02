//Write a simple C-program to perform Concatenation of two strings without using strcat().
#include <stdio.h>
void stringConcat(char *dest, char *src)
{
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    stringConcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}