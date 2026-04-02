#include<stdio.h>
int main()
{
    int n, i=1, sum=0;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    while (i<=n)
        {
            sum=sum+i;
            i++;
        }
    printf("SUM of '%d' Natural Numbers is:%d",n, sum);
    return 0;
}