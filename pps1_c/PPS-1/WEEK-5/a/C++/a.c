#include<stdio.h>
int main()
{
    int n, i;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    i=0;
    while (n>i)
    {
        printf("i=%d\n",i);
        i += 1;
    }
    return 0;
}