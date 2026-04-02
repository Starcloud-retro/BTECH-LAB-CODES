#include<stdio.h>
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
        //Perform MULTIPLICATION
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]=0;
                for(k=0;k<n;k++)
                {
                    c[i][j]=c[i][j]+a[i][j]*b[i][j];
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
    else
        printf("MULTIPLICATION is not Possible.");
    return 0;
}