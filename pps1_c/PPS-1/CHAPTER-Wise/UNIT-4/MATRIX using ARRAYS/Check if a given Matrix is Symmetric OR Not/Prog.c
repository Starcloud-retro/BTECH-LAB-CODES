#include<stdio.h>
int main()
{
    int a[5][5], b[5][5], f=0, i, j, k, m, n;
    printf("Enter m, n Values:\n");
    scanf("%d%d",&m,&n);
    printf("\nEnter %d elements into A:\n",m*n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
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
        b[i][j]=a[i][j];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]=b[i][j]);
                f++;
        }
    }
    if (f == (m*n))
        printf("Matrix A is Symmetric.");
    else
        printf("Matrix A is not Symmetric.");
    return 0;
}