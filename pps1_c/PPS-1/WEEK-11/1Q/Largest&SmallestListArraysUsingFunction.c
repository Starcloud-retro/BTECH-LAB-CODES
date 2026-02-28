//WEEK-11; Largest & Smallest Numbers in List of Array Elements//
#include <stdio.h>
int max(int, int[15]);
int min(int, int[15]);
int main()
{
    int arr[15], n, i;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    printf("\nEnter elements into the Array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n%d is the Largest.\n",max(n, arr));
    printf("\n%d is the Smallest.\n",min(n, arr));
}
int max(int n, int arr[15])
{
    int i,large=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }
    return large;
}
int min(int n, int arr[15])
{
    int i, small=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
        }
    }
    return small;
}