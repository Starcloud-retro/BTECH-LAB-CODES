#include<stdio.h>
int sum(int a, int b, int c);
int main()
{
    int x, y, z, t;
    printf("Enter x, y, z Values:");
    scanf("%d%d%d",&x,&y,&z);
    t=sum(x,y,z);
    printf("\nSUM is:%d",t);
}
int sum(int a, int b, int c)
{
    return a+b+c;
}