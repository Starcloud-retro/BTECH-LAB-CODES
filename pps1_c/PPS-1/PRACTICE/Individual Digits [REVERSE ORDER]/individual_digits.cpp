#include<stdio.h>
int main()
{
    int n, i; //To PRINT Indivisual Digits of a given number is Reverse Order.
    printf("Enter the number 'n':");
    scanf("%d",&n);
    while (n>0)
    {
        i = n%10;
        printf("%d",i);
        n = n/10;
    }
    return 0;
}