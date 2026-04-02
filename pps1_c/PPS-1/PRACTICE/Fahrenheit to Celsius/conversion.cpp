#include <stdio.h>
int main()
{
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit(F): ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%f Fahrenheit is %f Celsius\n", fahrenheit, celsius);
    return 0;
}