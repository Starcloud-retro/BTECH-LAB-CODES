#include<stdio.h>
int main()
{
    int i, n;
    printf("Enter n Value: ");
    scanf("%d",&n);
    int sum=0, count=0;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            printf("%d ",i);
            count+=1;
            sum+=i;
            if(i!=n/i)
            {
                printf("%d ",n/i);
                count+=1;
                sum+=(n/i);
            }
        }
    }
    printf("COUNT: %d\nSUM: %d",count,sum);
}