//Write a C-Program to find whether a given string is Palindrome or not
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[15], s2[15];
    int i, j, n;
    printf("Enter a String: ");
    gets(s1);
    for(i=strlen(s1)-1,j=0;i>=0;i--,j++)
    {
        s2[j]=s1[i];
    }
    s2[j]='\0';
    n=strcmp(s1,s2);
    if(n==0)
    {
        printf("Given String is Palindrome");
    }
    else
    {
        printf("Given String is not a Palindrome");
    }
    return 0;
}