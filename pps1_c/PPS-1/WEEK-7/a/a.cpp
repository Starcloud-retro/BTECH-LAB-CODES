#include<stdio.h>
int main()
{
    int i, n, count=0;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    i=1;
    while (i<=n)
    {
        if (n%i==0)
            count++;
        i++;
    }
    if (count==2)
        printf("\nThe Number(%d) is a PRIME Number.",n);
    else
        printf("\nThe Number(%d) is not a PRIME Number.",n);
}