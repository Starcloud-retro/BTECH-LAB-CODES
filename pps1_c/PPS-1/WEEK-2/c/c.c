#include<stdio.h>
int main()
{
    int a, b, c;
    printf("Enter 'a', 'b' Values:");
    scanf("%d%d",&a,&b);
    c=(a>b)?a:b;
    printf("\n Largest Number is:%d",c);
    return 0;
}