#include<stdio.h>
int main()
{
    int n, i, EVENsum, ODDsum;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    i=0;
    EVENsum=0;
    ODDsum=0;
    do
    {
        if (i%2==0)
        {
            EVENsum = EVENsum+i;
            i++;
        }
        else
        {
            ODDsum = ODDsum+i;
            i++;
        }
    }
    while (i<=n);
    {
        printf("EVENsum:%d \n ODDsum:%d",EVENsum,ODDsum);
    }
    return 0;
}