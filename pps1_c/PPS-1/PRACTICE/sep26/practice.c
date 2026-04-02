#include<stdio.h>
int main()
{
    int n;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    if (n%2==0)
        printf("Yes. The given number - %d,is EVEN.",n);
    else
        prinf("The given Number is ODD.");
    return 0;
}