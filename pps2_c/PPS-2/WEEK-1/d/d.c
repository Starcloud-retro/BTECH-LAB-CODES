//Write a C-Program to print the number of vowels and consonants using strings.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char line[100];
    int i, vowels = 0, consonants = 0, digits = 0, space = 0;
    printf("Enter a string: ");
    gets(line);
    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U')
        {
            ++vowels;
        }
        else if (line[i] > 'a' && line[i] <= 'z' || line[i] > 'A' && line[i] <= 'Z')
        {
            ++consonants;
        }
        else if (line[i] >= '0' && line[i] <= '9')
        {
            ++digits;
        }
        else if (line[i] == ' ')
        {
            ++space;
        }
    }
    printf("\nVowels: %d\nConsonants: %d\nDigits: %d\nSpace: %d", vowels, consonants, digits, space);
    return 0;
}