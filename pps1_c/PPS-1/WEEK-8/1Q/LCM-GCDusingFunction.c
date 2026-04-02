//WEEK-8; LCM & GCD using Functions//
#include<stdio.h>
int gcd(int, int);
int lcm(int, int, int);
int main()
{
    int gcd1, lcm1, x, y;
    printf("Enter x, y Values:\n");
    scanf("%d%d",&x,&y);
    gcd1=gcd(x,y);
    lcm1=lcm(x,y,gcd1);
    printf("\nGCD:%d",gcd1);
    printf("\nLCM:%d",lcm1);
    return 0;
}
int gcd(int x, int y)
{
    int min, r=1, gcd1;
    min=(x<y)?x:y;
    while(r<=min)
    {
        if(x%r==0 && y%r==0)
        {
            gcd1=r;
        }
        r++;
    }
    return gcd1;
}
int lcm(int x, int y, int gcd1)
{
    return (x*y)/gcd1;
}