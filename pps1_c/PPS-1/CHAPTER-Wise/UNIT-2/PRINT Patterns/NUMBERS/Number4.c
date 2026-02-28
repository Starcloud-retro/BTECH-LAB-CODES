#include<stdio.h>
int main()
{
    int n, i, j, k;//DOWN-WARD Consecutive Numbers Pyramid
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    for (i=n;i>=1;i--)
    {
        for (k=n;k>=i;k--)
        {
            printf(" ");
        }
        for (j=i;j>=1;j--)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}