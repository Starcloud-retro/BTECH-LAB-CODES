#include<stdio.h>
int main()
{
    int n, r, sum=0;
    printf("Enter the value of 'n':");
    scanf("%d",&n);
    while (n!=0)
    {
        r=n%10;
        sum += ((r)*(r)*(r));
        n = n/10;
    }
    printf("The SUM of CUBES of each digits in the number is:%d",sum);
}