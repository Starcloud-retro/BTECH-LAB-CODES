//COMPILE Only
#include<stdio.h>
#include"xyzeval.h"
void xyzeval()
{
    int a, b;
    printf("Enter 'a', 'b' Values: ");
    scanf("%d%d",&a, &b);
    printf("\nADD: %d\nSUB: %d\nMUL: %d\nDIV: %d\nMOD: %d\n",a+b,b-a,a*b,b/a,a%b);
}