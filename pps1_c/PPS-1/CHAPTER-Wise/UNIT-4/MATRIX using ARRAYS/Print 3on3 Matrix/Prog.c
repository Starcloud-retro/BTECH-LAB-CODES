//To PRINT 3*3 Matrix//
#include<stdio.h>
int main()
{
    int a[3][3], i, j;
    printf("Enter '9' Elements:");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    printf("\nMATRIX is:\n");
    for (i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
    return 0;
}