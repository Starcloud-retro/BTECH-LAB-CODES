#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number(n):");
    scanf("%d",&n);
    if (n>0)
        if (n%2==0)
        {
            printf("The Number (%d) is EVEN.",n);
        }
        else
        {
            printf("The Number (%d) is ODD.",n);
        }
    else
        {
            printf("The Number is ZERO.");
        }
    return 0;    
}