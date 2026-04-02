//Write a C-Program to sort the given elements using Selection Sort
#include<stdio.h>
int read(int, int []);
int print(int, int[]);
int selsort(int, int[]);
int main()
{
    int n, i;
    printf("Enter 'n' Value: ");
    scanf("%d",&n);
    int a[n];
    read(n, a);
    printf("\nBefore SORT:\n");
    print(n, a);
    printf("\nAfter SELECTION SORT:\n");
    selsort(n, a);
    print(n, a);
    return 0;
}
int read(int n, int a[])
{
    int i;
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    return 0;
}
int print(int n, int a[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
int selsort(int n, int a[])
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
    return 0;
}