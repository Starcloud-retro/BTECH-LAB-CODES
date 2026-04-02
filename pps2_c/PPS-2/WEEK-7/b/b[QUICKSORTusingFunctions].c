// Write a C-Program to sort the elements using QuickSort
#include <stdio.h>
void quicksort(int a[], int first, int last)
{
    int i, j, temp, pivot;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot] && i<last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a, first, j-1);
        quicksort(a, j+1,last);
    }
}
int main()
{
    int n, i;
    printf("Enter 'n' Value: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Before SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    quicksort(a, 0, n-1);
    printf("\nSORTED Array by QUICKSORT:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}