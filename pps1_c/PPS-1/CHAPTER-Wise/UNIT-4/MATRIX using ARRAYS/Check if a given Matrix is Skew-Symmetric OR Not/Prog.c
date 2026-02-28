#include <stdio.h>
int main()
{
    int m, n, i, j, a[5][5], b[5][5], f = 1;
    printf("Enter m,n Values:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("\nMatrix A is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\nTRANSPOSE of A is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",a[j][i]);
        }
        printf("\n");
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != (-a[j][i]))
            {
                f = 0;
                break;
            }
        }
        if(!f)
            break;
    }
    printf("%d",f);
    if(f)
        printf("The Matrix A is skew-symmetric.\n");
    else
        printf("The Matrix A is not skew-symmetric.\n");
    return 0;
}