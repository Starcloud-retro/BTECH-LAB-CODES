#include<stdio.h>
int main()
{
    int i, n, r, rev=0;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    r=n;
    while (n>0)
    {
        i=n%10;
        rev=rev*10+i;
        n=n/10;
    }
    if (rev==r)
        printf("\n%d is a Palindrome.",r);
    else
        printf("\n%d is not a Palindrome",r);
}