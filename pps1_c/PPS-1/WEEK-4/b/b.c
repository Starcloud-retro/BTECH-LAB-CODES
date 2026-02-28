#include<stdio.h>
#include<math.h>
int main()
//Find the QUADRATIC ROOT of an EQUATION with Discriminant(d)
{
    float a, b, c;
    printf("Enter the Value of a:");
    scanf("%f", &a);
    printf("Enter the Value of b:");
    scanf("%f", &b);
    printf("Enter the Value of c:");
    scanf("%f", &c);

    float d = (b * b) - (4 * a * c);

    if (d > 0) {
        float r1 = ((-b) + sqrt(d)) / (2 * a);
        float r2 = ((-b) - sqrt(d)) / (2 * a);
        printf("ROOTS are Real and Distinct. ROOTS: r1 = %f, r2 = %f\n", r1, r2);
    } else if (d == 0) {
        float r3 = (-b) / (2 * a);
        printf("The two ROOTS are Real and Equal. ROOT: r3 = %f\n", r3);
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-d) / (2 * a);
        printf("ROOTS are Complex and Imaginary. ROOT1: %f + %fi, ROOT2: %f - %fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
