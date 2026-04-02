//WEEK-12; Duplicate Elements using (SORTED ORDER)//
#include<stdio.h>
void duplicate(int[],int);
int main()
{
    int a[50], i, n;
    printf("\nEnter Size of Array:");
    scanf("%d",&n);
    printf("Enter %d elements into Array:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Duplicate Elements are:\n");
    duplicate(a, n);
    return 0;
}
void duplicate(int a[50], int n)
{
    int i, f=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            if(f==0)
            {
                printf("%d\t",a[i]);
                f=1;
            }
        }
        if(a[i]!=a[i+1])
            f=0;
    }
}