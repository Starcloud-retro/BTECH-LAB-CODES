#include<stdio.h>
int main()
{
    int a[50], i, key, n, f=0;
    printf("Enter Number of Elements (n):");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Key Elements:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("\n%d is found at %d position.",key,i+1);
    else
        printf("\n%d Not Found.",key);
    return 0;
}