#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i, j, x;
    char s1[30], s2[30];

    printf("Enter a String: ");
    scanf("%s", s1);

    for(i = 0, j = 0; i < strlen(s1); i++)
    {
        if(s1[i] >= '0' && s1[i] <= '9')
        {
            s2[j] = s1[i];
            x = atoi(s2);
            printf("%d\n", x * x);
        }
    }
}