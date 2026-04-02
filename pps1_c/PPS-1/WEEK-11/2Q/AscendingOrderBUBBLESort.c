// WEEK-11; Sort List of Elements in Ascending Order Using Bubble Sort
#include <stdio.h>
int main()
{
    int a[50], i, j, k, n, t;
    printf("Enter 'n' Value:");
    scanf("%d", &n);
    printf("\nEnter %d Elements:\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nBefore BUBBLE SORTING:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("\nAfter BUBBLE SORTING:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}