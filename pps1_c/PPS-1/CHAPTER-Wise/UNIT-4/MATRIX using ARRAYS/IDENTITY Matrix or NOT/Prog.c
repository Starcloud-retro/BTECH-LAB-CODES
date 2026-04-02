#include <stdio.h>
int main()
{
    int m, n, i, j, a[5][5], isIdentityMatrix = 1;
    printf("Enter the number of rows (m) and columns (n) of the matrix: ");
    scanf("%d %d", &m, &n);
    if (m != n)
    {
        printf("The matrix is not square, so it cannot be an identity matrix.\n");
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
        for (j = 0; j < n; j++)
        {
            if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
            {
                isIdentityMatrix = 0;
                break;
            }
        }
        if (!isIdentityMatrix)
        {
            break;
        }
    }
    if (isIdentityMatrix)
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is not an identity matrix.\n");
    return 0;
}