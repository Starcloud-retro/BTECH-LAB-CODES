//Write a simple C-program to calculate the length of string without using strlen()
#include <stdio.h>
int stringLength(char *str)
{
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    int length = stringLength(str);
    printf("Length of the string is: %d\n", length);

    return 0;
}