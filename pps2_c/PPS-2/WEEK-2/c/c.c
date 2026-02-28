//Write a C-Program to find whether a given string is Palindrome or not
#include<stdio.h>
#include<string.h>
void rev(char str[]);
int main()
{
    char str[20];
    printf("Enter the String to be reversed: ");
    scanf("%[^\n]s",str);
    rev(str);
    return 0;
}
void rev(char str[])
{
    int i, n;
    n=strlen(str);
    printf("\nReversed String is:\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%c",str[i]);
    }
}