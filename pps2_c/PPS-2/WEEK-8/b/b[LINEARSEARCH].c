//Write a C-Program to search an element in a list of elements using linear search. If the elements found display the position, otherwise print "Element Not Present"
#include <stdio.h>
int linearSearch(int a[], int n, int key)
{
    int found=0;
    while(found==0)
    {   
        for (int i = 0; i < n; i++)
        {
            if (a[i] == key)
            {
                printf("Element Found at Position %d",i+1); // Element found, return position
                found++;
                break;
            }
            else
                printf("NOT Found");
        }
    }
    return 0;
}
int main()
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    linearSearch(arr, n, key);
    return 0;
}