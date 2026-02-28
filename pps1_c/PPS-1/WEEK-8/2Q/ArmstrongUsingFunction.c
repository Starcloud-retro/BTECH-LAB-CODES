//WEEK-8; ARMSTRONG Number OR Not//
#include <stdio.h>
#include <math.h>
//To count the number of digits in a number//
int countDigits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
//To check if a number is an Armstrong number//
int isArmstrong(int num)
{
    int originalNum = num;
    int sum = 0;
    int digits = countDigits(num);
    while (num != 0)
    {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    return (sum == originalNum);
}
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    //To check if the number is an Armstrong number//
    if (isArmstrong(number))
    {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }
    return 0;
}