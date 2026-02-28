#include<stdio.h>
int main()
{
    int i, n, j, count=0;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        count=0;
        for (j=1;j<=n;j++)
        {
            if(i%j==0)
            count++;
        }
        if (count==2)
            printf("\n%d",i);
    }
    return 0;
}