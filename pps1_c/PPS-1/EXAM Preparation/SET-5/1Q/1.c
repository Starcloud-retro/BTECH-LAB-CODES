#include<stdio.h>
#include<math.h>
int main()
{
    float a, b, c;
    printf("Enter 'a' Value:");
    scanf("%f",&a);
    printf("Enter 'B' Value:");
    scanf("%f",&b);
    printf("Enter 'c' Value:");
    scanf("%f",&c);
    float d = ((b*b)-4*a*c);
    if (d==0)
        {
            float r1 = (-b)/(2*a);
            printf("The Two ROOTS are Real and Equal. ROOT:%f",r1);
        }
    else if (d>0)
        {
            float r2 = (((-b)+sqrt(d))/(2*a));
            float r3 = (((-b)-sqrt(d))/(2*a));
            printf("The ROOTS are Real and Distinct. ROOTS:r2=%.2f, r3=%.2f",r2, r3);
        }
    else
        {
            printf("IMAGINARY and COMPLEX ROOTS.");
        }
    return 0;
}