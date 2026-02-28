#include<stdio.h>
struct complex
{
    float real;
    float imag;
};
struct complex add(struct complex n1, struct complex n2)
{
    struct complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
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
    result = add(n1,n2);
    printf("Sum = %.1f +i%.1f",result.real, result.imag);
    return 0;
}