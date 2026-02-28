#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    {
        if (n==0)
        {
            printf("The number(n) is ZERO.");
        }
        else if (n>0)
        {
            printf("The number(n) is POSITIVE.");
        }
        else
            printf("The number(n) is NEGATIVE.");
        
    }
    return 0;
}