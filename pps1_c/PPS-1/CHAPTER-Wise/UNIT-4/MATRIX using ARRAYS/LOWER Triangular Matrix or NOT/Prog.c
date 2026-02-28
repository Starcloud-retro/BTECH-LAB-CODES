#include <stdio.h>
int main()
{
    int m, n, i, j, a[5][5], isLowerTriangular = 1;
    printf("Enter the number of rows (m) and columns (n) of the matrix: ");
    scanf("%d %d", &m, &n);
    if (m != n)
    {
        printf("The matrix is not square, so it cannot be a lower triangular matrix.\n");
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
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                isLowerTriangular = 0;
                break;
            }
        }
        if (!isLowerTriangular)
        {
            break;
        }
    }
    if (isLowerTriangular)
        printf("The matrix is a lower triangular matrix.\n");
    else
        printf("The matrix is not a lower triangular matrix.\n");
    return 0;
}