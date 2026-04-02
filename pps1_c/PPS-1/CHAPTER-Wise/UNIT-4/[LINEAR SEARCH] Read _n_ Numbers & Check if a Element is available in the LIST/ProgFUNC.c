#include<stdio.h>
int lins(int[], int, int);
int main()
{
    int a[50], i, key, n, f=0;
    printf("Enter Number of Elements (n):");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Key Elements:");
    scanf("%d",&key);

    f=lins(a, n, key);    
    if(f==1)
        printf("%d is Found.",key);
    else
        printf("\n%d Not Found.",key);
    return 0;
}
int lins(int a[50], int n, int key)
{
    int i,f;
    for(i=0;i<n;i++)
        {
            if(key==a[i])
            {
                f=1;
                printf("In Position %d,",i+1);
                break;
            }
        }
    return f;
}