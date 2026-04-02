#include<stdio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, m, n, p, q;
    printf("Enter m, n, p, q Values:\n");
    scanf("%d%d%d%d",&m, &n, &p, &q);
    if (m==p && n==q)
    {
        printf("Enter %d elements into A:\n",m*n);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        printf("Enter %d elements into B:\n",p*q);
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        }
        //PERFORMING ADDITION://
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                c[i][j]=a[i][j]+b[i][j];
        }
        printf("ADDITION is:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",c[i][j]);
        printf("\n");
        }
    }
    else
    {
        printf("ADDITION is not Possible.");
    }
    return 0;
}