//Write a C-Program to find a Element in a given SORTED LIST using BINARY SEARCH 
#include<stdio.h>
int binsearch(int a[], int first, int last, int key)
{
    if(first<=last)
    {
        int mid=(first+last)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        {
            return binsearch(a, mid+1, last, key);
        }
        else
        {
            return binsearch(a, first, mid-1, key);
        }
    }
    else
        return -1;
}
int main()
{
    int n, first, last, key;
    printf("Enter 'n' Value: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter KEY Element: ");
    scanf("%d",&key);
    int f=binsearch(a, 0, n-1, key);
    if(f==-1)
        printf("KEY Element NOT Found!");
    else
        printf("KEY Element found at %d position!",f+1);
    return 0;
}