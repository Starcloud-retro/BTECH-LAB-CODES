#include<stdio.h>
int main()
{
    int n;
    printf("Enter (n) Value:");
    scanf("%d",&n);
    if (n%2==0)
    {
        if (n>0)
        {
            printf("The value of (n) is EVEN.");
        }
        else
        printf("The value of (n) is ZERO.");
        
    }
    else
    {
        printf("The value of (n) is ODD.");
    }
    return 0;
}