// WEEK-11; Sort List of Elements in Ascending Order Using Bubble Sort
#include <stdio.h>
void bubblesort(int[], int);
int main()
{
    int a[50], i, n;
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
    bubblesort(a, n);
    printf("\nAfter BUBBLE SORTING:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
void bubblesort(int a[50], int n)
{
    int i, j, t;
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
}