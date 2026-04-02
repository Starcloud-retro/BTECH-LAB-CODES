//WEEK-11;

#include <stdio.h>
int main()
{
    int array[100], n, i, element, found = 0;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    for (i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            printf("Element found at location: %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("The Number is not Found.\n");
    }
    return 0;
}