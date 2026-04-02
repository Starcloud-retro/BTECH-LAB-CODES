#include<stdio.h>
int main()
{
    int n, i, sum;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    sum=0;i=1;
    while (i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("SUM of %d Natural Numbers is:%d",n, sum);
    return 0;
}