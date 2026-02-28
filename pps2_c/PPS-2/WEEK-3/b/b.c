//Write a C-Program to Calculate Multiplication of two Complex Numbers using Structure
#include<stdio.h>
struct complex
{
    float real;
    float imag;
};
struct complex mul(struct complex n1, struct complex n2)
{
    struct complex temp;
    temp.real = n1.real*n2.real - n1.imag*n2.imag;
    temp.imag = n1.real*n2.imag + n1.imag*n2.real;
    return temp;
}
int main()
{
    struct complex n1, n2, result;
    printf("For 1st Complex Number: \n");
    printf("Enter the Real and Imaginary parts: ");
    scanf("%f%f",&n1.real,&n1.imag);
    printf("\nFor 2nd Complex Number: \n");
    printf("Enter the Real and Imaginary parts: ");
    scanf("%f%f",&n2.real,&n2.imag);
    result = mul(n1,n2);
    printf("MULTIPLICATION = %.1f +i%.1f",result.real, result.imag);
    return 0;
}
