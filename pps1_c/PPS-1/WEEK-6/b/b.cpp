#include<stdio.h>
int main()
{
    int n, i, sum=0;
    printf("Enter the Value of 'n':");
    scanf("%d",&n);
    i=1;
    do
    {
        sum = sum+i;
        i++;
    }
    while (i<=n);
        printf("\nSUM is:%d",sum);
    return 0;    
}