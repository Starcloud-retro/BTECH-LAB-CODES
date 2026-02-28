//WEEK-9; #FIBONACCI SERIES(2nd PROGRAM)//
#include<stdio.h>
void Fib(int n);
int main()
{
    int n;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    Fib(n);
}
void Fib(int n)
{
    int i, f1=0, f2=1, f3;
    printf("%d\t%d\t",f1,f2);
    for(i=3;i<=n;i++)
    {
        f3=f1+f2;
        printf("%d\t",f3);
        f1=f2;
        f2=f3;
    }
}