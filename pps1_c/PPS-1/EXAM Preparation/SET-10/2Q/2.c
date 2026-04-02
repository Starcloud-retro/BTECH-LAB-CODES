#include<stdio.h>
int main()
{
    int n, i=1, count=0;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    while (i<=n)
    {
        if (n%i==0)
            count++;
        i++;
    }
    if (count==2)
    {
        printf("The Number %d is a PRIME Number.",n);
    }
    else
    {
        printf("The Number %d is not a PRIME Number.",n);
    }
    return 0;
}