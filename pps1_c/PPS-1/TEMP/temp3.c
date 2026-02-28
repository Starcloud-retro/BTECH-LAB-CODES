#include <stdio.h>
int main()
{
    int n, m, i, j;
    printf("Finding a Number from a List of 'n' Elements in an Array:\n\n\nEnter 'n' Value: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter %d elements into 'a':\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("ORIGINAL LIST:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nEnter the Element you want to DELETE: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {
        if (a[i] == m)
        {
            printf("The Element %d is found at Position %d.\n", m, i + 1);
            for (j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--; // Reduce the size of the array
            break;
        }
    }
    printf("LIST after DELETION:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
