#include<stdio.h>
int main()
{
    int n, i, r, rev=0;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    r=n;
    while (n>0)
    {
        i=n%10;
        rev = rev*10+i;
        n=n/10;
    }
    if (rev==r)
        printf("\n%d is a PALINDROME!",r);
    else
        printf("\n%d is not a PALINDROME!",r);
    return 0;
}
