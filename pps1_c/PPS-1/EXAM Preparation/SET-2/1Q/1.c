#include<stdio.h>
#include<math.h>
int main()
{
    double A, r, pi;
    int x, y;
    printf("Enter the 'X' Value:");
    scanf("%d",&x);
    y=(pow(x,2))+(2*x)+3;//'pow' for POWER, OR we can use "x*x" then 'math.h' library would not be required.//
    printf("\nThe Value of 'Y' from the Equation: y=(x^2)+(2*x)+3 is:%d",y);
    pi=3.1415926535897932384626433832795;
    r=y;
    A=(pi*(pow(r,2)));
    printf("\nAREA of CIRCLE (A) is:%lf (for 'y' taken as RADIUS)",A);
    return 0;
}
