#include<stdio.h>
int main()
{
    int n;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    if (n==0)
        {
            printf("The Number is ZERO.");
        }
    else if (n>0)
        {
            printf("The Number is POSITIVE.");
        }
    else
        {
            printf("The Number is NEGATIVE.");
        }
    return 0;
}