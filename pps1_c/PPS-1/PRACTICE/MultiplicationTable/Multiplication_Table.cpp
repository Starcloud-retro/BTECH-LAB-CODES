#include<stdio.h>
int main()
{
    int n, i=0, k, l;
    printf("Enter a number to get it's Multiplication Table:");
    scanf("%d",&n);
    printf("Enter the number of MULTIPLICATION TABLES:");
    scanf("%d",&k);
    while (i<=k)
        {
            l=n*i;
            printf("\n%d * %d = %d",n, i, l);
            i+=1;
        }
    return 0;
}