//Write a C-Program to find a Element in a given UN-SORTED LIST using BINARY SEARCH
#include<stdio.h>
int isSorted(int a[], int n) //Check if the array is SORTED
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0; // if Not sorted
        }
    }
    return 1; // if Sorted
}
void bubbleSort(int a[], int n) //BUBBLE SORT
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int binsearch(int a[], int first, int last, int key) // BINARY SEARCH
{
    if(first <= last)
    {
        int mid = (first + last) / 2;
        if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] < key) 
        {
            return binsearch(a, mid + 1, last, key);
        }
        else
        {
            return binsearch(a, first, mid - 1, key);
        }
    }
    else
    {
        return -1;
    }
}
int main() //MAIN FUNCTION
{
    int n, first, last, key;
    printf("Enter 'n' Value: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter KEY Element: ");
    scanf("%d", &key);
    // Check if the array is sorted
    if(!isSorted(a, n))
    {
        // If not sorted, perform Bubble Sort
        printf("Array is not sorted. Performing Bubble Sort...\n");
        bubbleSort(a, n);
        printf("Array sorted.\n");
    }
    int f = binsearch(a, 0, n - 1, key);
    if(f == -1)
    {
        printf("KEY Element NOT Found!\n");
    }
    else
    {
        printf("KEY Element found at %d position!\n", f + 1);
    }
    return 0;
}