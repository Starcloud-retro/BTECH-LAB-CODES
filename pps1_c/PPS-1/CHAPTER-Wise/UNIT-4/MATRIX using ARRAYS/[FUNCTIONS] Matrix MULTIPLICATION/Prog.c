#include <stdio.h>
void mulMatrix(int[10][10], int[10][10], int, int, int);
int main()
{
    int a[10][10],b[10][10],c[10][10], i,j,k,m,n,p,q;
    printf("Enter m, n, p, q values:\n");
    scanf("%d%d%d%d",&m,&n,&p,&q);
    if (n == p)
    {
        printf("Enter %d elements into A\n",m*m);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        printf("\nEnter %d elements into B\n",p*q);
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        }
        mulMatrix(a,b,m,n,q);
    }
    else
    {
        printf("MULTIPLICATION is not Possible.");
    return 0;
    }
}
void mulMatrix(int a[10][10], int b[10][10], int m, int n, int q)
{
    int c[10][10], i, j, k;
    for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        }
    printf("\nMULTIPLICATION is:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
}