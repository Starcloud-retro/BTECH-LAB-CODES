#include<stdio.h>
int main()
{
    int n, i=1, count=0;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    while(i<=n)
        {
            if (n%i==0)
                count ++;
            i++;
        }
    if (count==2)
        {
            printf("\nThe Number %d is PRIME.",n);
        }
    else
        printf("\nThe Number %d is not PRIME.",n);
    return 0;
}
