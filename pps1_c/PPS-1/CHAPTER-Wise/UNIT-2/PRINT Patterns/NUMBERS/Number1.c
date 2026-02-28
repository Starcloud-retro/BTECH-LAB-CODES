#include<stdio.h>
int main()
{
    int n, i, j;//UP-WARDS Right Angle Consecutive Numbers
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}