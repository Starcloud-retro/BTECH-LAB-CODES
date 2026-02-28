//WEEK-10; FIBONACCI SERIES Using Recursive Function//
#include<stdio.h>
int Fib(int n)
{
    //To Check for FIBONACCI Series//
    if (n==0 || n==1)
        return n;
    else
        return Fib(n-1)+Fib(n-2);
}
int main()
{
    int n, i;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    printf("\nFIBONACCI Series from 1 to %d is:\n",n);
    for(i=0;i<=n;i++)
        {
            printf("\t%d",Fib(i));
        }
    return 0;
}