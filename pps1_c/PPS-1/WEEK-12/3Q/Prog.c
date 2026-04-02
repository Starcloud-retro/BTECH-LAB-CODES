//WEEK-12; C-Program to perform MULTIPLICATION of two Numbers
#include<stdio.h>
void mulmatrix(int[10][10], int[10][10], int, int, int);
int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, m, n, p, q;
    printf("Enter m, n, p, q Values:\n");
    scanf("%d%d%d%d",&m, &n, &p, &q);
    if (n==p)
    {
        printf("Enter %d elements into A:\n",m*n);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter %d elements into B:\n",p*q);
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        mulmatrix(a, b, q, m, n);
    }
    else
    {
        printf("\nMULTIPLICATION is not Possible.");
    }
    return 0;
}
void mulmatrix(int a[10][10], int b[10][10], int q, int m, int n)
{
    int c[10][10], i, j, k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    printf("Matrix MULTIPLICATION is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",c[i][j]);
        }
    printf("\n");
    }
}