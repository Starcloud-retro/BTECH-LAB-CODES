#include<stdio.h>
int main()
{
    int i, n, j, k, count;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    i=1;
    while(i<=n)
        {
            count=0;
            for (k=1;k<=i;k++)
                if (i%k==0)
                    count++;
            if (count==2)
                printf("\n%d",i);
            i=i+1;
        }
    return 0;
}