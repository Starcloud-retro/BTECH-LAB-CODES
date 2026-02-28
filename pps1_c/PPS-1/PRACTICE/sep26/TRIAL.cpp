#include<stdio.h>
int main()
{
    int n;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    if (n<10)
    {
        printf("\nThe given number is less than TEN");
        if(n==5)
        {
            printf("\nThe given number is FIVE");
        }
    }
    return 0;
}