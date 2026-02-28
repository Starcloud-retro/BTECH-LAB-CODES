#include<stdio.h>
int main()
{
    int n, i, j;//DOWN-WARD NON-Cosecutive Numbers Right Angle//
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    for (i=n;i>=1;i--)
    {
        for (j=i;j>=1;j--)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}