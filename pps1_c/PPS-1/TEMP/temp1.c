#include<stdio.h>
#define PI 3.14
#define SQUARE(x) ((x)*(x))
int main()
{
        int r;
        float a;
        printf("Enter 'r' Value: ");
        scanf("%d",&r);
        a=PI*SQUARE(r);
        printf("Area (a): %.3f",a);

        printf("\nEXTRA INFO:\n");
        printf("FILE: %s\n", __FILE__);
        printf("DATE: %s\n", __DATE__);
        printf("TIME: %s\n", __TIME__);
        printf("LINE: %d\n", __LINE__);
        printf("ANSI: %d\n", __STDC__);

        return 0;
}