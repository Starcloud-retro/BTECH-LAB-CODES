#include<Stdio.h>
int main()
{
    int a, b, c;
    printf("Enter a, b, c values:");
    scanf("%d%d%d",&a,&b,&c);
    if (a>b)
        if (a>c)
            printf("\nA is largest.");
        else
            printf("\nC is largest.");
    else
        if (b>c)
            printf("\nB is Largest");
        else
            printf("\nC is largest.");
    return 0;
}