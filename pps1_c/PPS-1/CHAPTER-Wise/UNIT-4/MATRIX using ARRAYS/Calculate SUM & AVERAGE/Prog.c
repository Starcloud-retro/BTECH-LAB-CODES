#include<stdio.h>
int main()
{
    int a[50], sum=0, i, n;
    float avg;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    printf("\nEnter %d Elements into 1-Dimensional Array:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        sum=sum+a[i];
    avg=sum/n;
    printf("\nSUM is:%d\nAVERAGE is:%f",sum, avg);
    return 0;
}