#include<stdio.h>
int main()
{
    int n, i;
    printf("\nEnter 'n' Value:");
    scanf("%d",&n);
    i=1;
    while (i<=n)
        {
            printf("\n%d",i);
            i++;
        }
    return 0;
}