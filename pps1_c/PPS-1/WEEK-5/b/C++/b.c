#include<stdio.h>
int main()
{
    int n, i, sum;
    printf("Enter the value of 'n':");
    scanf("%d",&n);
    sum=0, i=1;
    while (i<=n)
        {
            sum=sum+i;
            i++;//++i
        }
    printf("\nSUM of '%d' Natural Numbers is: %d",n,sum);
    return 0;
}