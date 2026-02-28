#include<stdio.h>
int main()
{
    char ch, oper;
    printf("Enter the Character:");
    scanf("%c",&oper);
    switch (oper)
        {
            case 'a': printf("The Character is a VOWEL!");
                break;
            case 'A': printf("The Character is a VOWEL!");
                break;
            case 'e': printf("The Character is a VOWEL!");
                break;
            case 'E': printf("The Character is a VOWEL!");
                break;
            case 'i': printf("The Character is a VOWEL!");
                break;
            case 'I': printf("The Character is a VOWEL!");
                break;
            case 'o': printf("The Character is a VOWEL!");
                break;
            case 'O': printf("The Character is a VOWEL!");
                break;
            case 'u': printf("The Character is a VOWEL!");
                break;
            case 'U': printf("The Character is a VOWEL!");
                break;
            default: printf("The Character is a CONSONANT!");
                break;
        }
    return 0;
}