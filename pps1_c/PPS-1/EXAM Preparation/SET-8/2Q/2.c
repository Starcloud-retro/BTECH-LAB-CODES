#include<stdio.h>
int main()
{
    int n, i=1, fact=1;
    printf("Enter 'n' Value:",&n);
    scanf("%d",&n);
    while (i<=n)
        {
            fact=fact*i;
            i++;
        }
    printf("The FACTORIAL of %d is: %d",n, fact);
    return 0;
}