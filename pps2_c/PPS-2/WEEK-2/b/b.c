//Write a C-Program to find the 2's Compliment of a given string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char bin[20];
    int i, j, len;
    printf("Enter a Binary Number: ");
    gets(bin);
    for(i=0; bin[i]!='\0'; i++)
    {
        if(bin[i]!='1' && bin[i]!='0')
        {
            printf("Binary Number must be in 0 to 1");
            exit(0);
        }
    }
    len=strlen(bin);
    for(i=len-1; i>=0; i--)
    {
        if(bin[i]=='1')
            break;
    }
    for(j=i-1; j>=0; j--)
    {
        if(bin[j]=='1')
            bin[j]='0';
        else
            bin[j]='1';
    }
    printf("The 2's Compliment is: %s",bin);
}
