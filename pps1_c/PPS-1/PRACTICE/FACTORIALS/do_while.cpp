#include<stdio.h>
int main()
{
    int i, n;
    long int fact=1;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    i=1;
    do
    {
        fact = fact*i;
        i++;
    }
    while (i<=n);
        printf("Factorial of %d is:%d",n, fact);
    return 0;
    
}