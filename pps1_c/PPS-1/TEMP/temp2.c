#include<stdio.h>
int main()
{
    int x, y=0;
    printf("Read X:");
    scanf("%d",&x);
    while (x!=0)
    {
        y = (y * 10) + (x % 10);
        x=x/10;
    }
    printf("Y Value:%d",y);
    return 0;
}