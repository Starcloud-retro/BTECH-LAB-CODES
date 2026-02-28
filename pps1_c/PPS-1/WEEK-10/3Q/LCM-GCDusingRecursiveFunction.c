//WEEK-10; LCM-GCD using Recursive Function//
#include <stdio.h>
int gcd(int, int);
int lcm(int, int);
int main()
{
    int num1, num2, lcm1, hcf;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    hcf=gcd(num1,num2);
    lcm1=lcm(num1,num2);
    printf("\nGCD:%d",hcf);
    printf("\nLCM:%d",lcm1);
    return 0;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x%y);
}
int lcm(int a, int b)
{
    static int temp=1;
    if ((temp%a==0) && (temp%b==0))
        {
            return temp;
        }
    else
    {
        temp++;
        lcm(a,b);
        return temp;
    }
}