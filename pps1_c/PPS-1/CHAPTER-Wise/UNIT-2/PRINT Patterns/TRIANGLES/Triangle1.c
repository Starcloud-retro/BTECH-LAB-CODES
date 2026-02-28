#include<stdio.h>
int main()
{
    int n, i, j, k; //UPWARD PYRAMID
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(k=n; k>=i; k--)
        {
            printf(" ");
        }
        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}