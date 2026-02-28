#include<stdio.h>
int main()
{
    int i, j, n;
    scanf("%d",&n);
    for(i = 1; i <= (2*n) - 1; i++)
    {
        for(j = 1; j <= (2*n) - 1; j++)
        {
            //PART-1
            if(i <= n && j <= n)
            {
                int min = i < j ? i : j;
                printf("%d ",n - min + 1);
            }

            //PART-2
            if(i <= n && j > n)
            {
                if((i + j) <= (2*n))
                    {
                        printf("%d ",n - i + 1);
                    }
                else if((i + j) > (2*n))
                    {
                        printf("%d ",j - n + 1);
                    }
            }
            
            //PART-3
            if(i > n && j <= n)
            {
                if((i + j) <= (2*n))
                    {
                        printf("%d ",n - j + 1);
                    }
                else if((i + j) > (2*n))
                    {
                        printf("%d ",i - n + 1);
                    }
            }

            //PART-4
            if(i > n && j > n)
            {
                int max = i > j ? i : j;
                printf("%d ",max - n + 1);
            }

        }
        printf("\n");
    }
    return 0;
}