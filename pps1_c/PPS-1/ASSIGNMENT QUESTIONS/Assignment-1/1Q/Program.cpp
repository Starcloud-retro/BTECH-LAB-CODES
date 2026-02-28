#include<stdio.h>
int main()
{
    int i, N, count=0;
    printf("Enter the Number(N):");
    scanf("%d",&N);
    i=1;
    while (i<=N)
    {
        if (N%i==0)
            count++;
        i++;
    }
    if (count==2)
        printf("\nNumber(%d) is PRIME Number.",N);
    else
        printf("\nNumber(%d) is not a PRIME Number.",N);
    return 0;
}