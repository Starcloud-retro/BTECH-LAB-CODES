#include<stdio.h>
int main()
{
    int a, b, c, d, e, f, g;
    printf("\nEnter the value of a:");
    scanf("%d",&a);
    printf("\nEnter the Value of b:");
    scanf("%d",&b);
    printf("\nARITHMETIC Operations:");
    c=a+b;
    printf("\nADDITION:%d",c);
    d=a-b;
    printf("\nSUBTRACTION:%d",d);
    e=a*b;
    printf("\nMULTIPLICATION:%d",e);
    f=a/b;
    printf("\nDIVISION:%d",f);
    g=a%b;
    printf("\nMODULUS:%d",g);
    return 0;
}