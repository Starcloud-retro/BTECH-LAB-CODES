//Write a C-Program to sort the given elements using Bubble Sort
#include<stdio.h>
int read(int, int []);
int print(int, int[]);
int bsort(int, int[]);
int main()
{
    int n, i;
    printf("Enter 'n' Value: ");
    scanf("%d",&n);
    int a[n];
    read(n, a);
    printf("\nBefore SORT:\n");
    print(n, a);
    printf("\nAfter BUBBLE SORT:\n");
    bsort(n, a);
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
int bsort(int n, int a[])
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    return 0;
}