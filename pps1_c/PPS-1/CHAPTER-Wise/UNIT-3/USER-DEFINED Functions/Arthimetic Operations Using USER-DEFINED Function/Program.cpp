#include<stdio.h>
int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int main()
{
    int a, b, x, y, z, p, q;
    printf("Enter a, b Values:");
    scanf("%d%d",&a,&b);
    x=sum(a,b);
    y=sub(a,b);
    z=mul(a,b);
    p=div(a,b);
    q=mod(a,b);
    printf("\nSUM is:%d\nSUB is:%d\nMUL is:%d\nDIV is:%d\nMOD is:%d",x,y,z,p,q);
}
int sum(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mul(int a, int b)
{
    return a*b;
}
int div(int a, int b)
{
    return a/b;
}
int mod(int a, int b)
{
    return a%b;
}