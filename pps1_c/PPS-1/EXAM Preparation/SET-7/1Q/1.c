#include<stdio.h>
int main()
{
    int a, b;
    printf("Enter 'a' & 'b' Values:");
    scanf("%d%d",&a,&b);
    if (a>b)
        {
            printf("%d is the LARGEST.",a);
        }
    else
        {
            printf("%d is the LARGEST.",b);
        }
    return 0;
}