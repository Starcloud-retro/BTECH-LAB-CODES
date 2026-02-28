#include <stdio.h>
int main()
{
    int m, n, i, j, isUpperTriangular = 1, a[5][5];
    printf("Enter m,n Values:\n");
    scanf("%d %d", &m, &n);
    if (m != n)
    {
        printf("The matrix is not square, so it cannot be an upper triangular matrix.\n");
        return 1;
    }
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i < m; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[i][j] != 0)
            {
                isUpperTriangular = 0;
                break;
            }
        }
        if (!isUpperTriangular)
        {
            break;
        }
    }
    if (isUpperTriangular)
    {
        printf("The matrix is an upper triangular matrix.\n");
    }
    else
    {
        printf("The matrix is not an upper triangular matrix.\n");
    }
    return 0;
}