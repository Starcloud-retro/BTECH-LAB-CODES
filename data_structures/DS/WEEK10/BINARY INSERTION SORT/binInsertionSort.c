//BINARY INSERTION SORT
#include <stdio.h>

// Binary search to find position for insertion
int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

// Binary Insertion Sort
void binaryInsertionSort(int arr[], int n)
{
    int i, j, selected, loc;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = arr[i];

        // Find location using binary search
        loc = binarySearch(arr, selected, 0, j);

        // Shift elements
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    binaryInsertionSort(arr, n);

    printf("\nSorted Array using Binary Insertion Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}