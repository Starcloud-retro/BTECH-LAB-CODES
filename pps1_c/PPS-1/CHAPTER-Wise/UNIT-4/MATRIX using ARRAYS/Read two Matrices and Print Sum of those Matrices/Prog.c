//To Read Two MATRICES (3*3 MATRIX) and Print the SUM of the two Matrices//
#include <stdio.h>
int main()
{
    int a[3][3], b[3][3], sum[3][3];
    int i, j;
    printf("Enter Matrix 'A' Elements:\n"); //MATRIX 'A' Elements//
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter Matrix 'B' Elements:\n"); //MATRIX 'B' Elements//
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(i = 0; i < 3; i++) //SUM of the two MATRICES//
    {
        for(j = 0; j < 3; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nSUM of MATRIX 'A' and 'B' is:\n"); //RESULT//
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}