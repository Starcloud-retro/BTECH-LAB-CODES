#include<stdio.h>
int main()
{
    int i, n;
    long long int fact=1;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    i=1;
    while (i<=n)
    {
        fact = fact*i;
        i++;
    }
    printf("Factorial of %d is:%d",n,fact);
    return 0;
}