//Write a C-Program to sort the given elements using Insertion Sort
#include<stdio.h>
int read(int, int []);
int print(int, int[]);
int insertionsort(int, int[]);
int main()
{
    int n, i;
    printf("Enter 'n' Value: ");
    scanf("%d",&n);
    int a[n];
    read(n, a);
    printf("\nBefore SORT:\n");
    print(n, a);
    printf("\nAfter INSERTION SORT:\n");
    insertionsort(n, a);
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
int insertionsort(int n, int a[])
{
    int i, j, k;
    for(i=0;i<n;i++)
    {
        k=a[i];
        for(j=i-1;j>=0 && k<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=k;
    }
    return 0;
}