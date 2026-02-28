//WEEK-10; FACTORIAL Using Recursive Function//
#include<stdio.h>
int fact(int n);
int main()
{
    int n;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    printf("FACTORIAL of %d is:%d",n, fact(n));
    return 0;
}
//Finding FACTORIAL//
int fact(int n)
{
    if (n==1 || n==0)
        return 1;
    else
    {
        return n*fact(n-1);
    }
}