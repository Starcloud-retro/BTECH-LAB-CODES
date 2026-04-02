#include<stdio.h>
int main()
{
    int a, sum=20;
    printf("Enter 'a' Value:\n");
    scanf("%d",&a);
    sum%=a;
    printf("\nSUM is:%d",sum);
    return 0;
}