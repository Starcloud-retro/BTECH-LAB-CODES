#include<stdio.h>
int main()
{
    int n, i, j, min;
    printf("\nEnter 'n' Value:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nBefore SORT:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
    }
    printf("\nSORTED Array by SELECTION SORT:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}