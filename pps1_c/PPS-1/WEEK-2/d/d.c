#include<stdio.h>
int main()
{
    int a, b, n;
    printf("Enter 'a', 'b', 'n' Values:\n");
    scanf("%d%d%d",&a,&b,&n);
    printf("\n BITWISE-AND a&b is:%d",a&b);
    printf("\n BITWISE-OR a|b is:%d",a|b);
    printf("\n BITWISE-EXCLUSIVE_OR a^b is:%d",a^b);
    printf("\n BITWISE-LEFT_SHIFT a<<2 is:%d",a<<2);
    printf("\n BITWISE-RIGHT_SHIFT b>>2 is:%d",b>>2);
    printf("\n BITWISE-COPLEMENT ~n is:%d",~n);
    return 0;
}