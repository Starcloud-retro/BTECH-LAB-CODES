//WEEK-14; Program to return multiplies values from a function using Pointers.
#include<stdio.h>
#include<stdlib.h>
void sumdiff(int *a, int *b, int *sum, int *diff)
{
    *sum=*a+*b;
    *diff=*a-*b;
}
int main()
{
    int *a, *b, *sum, *diff;
    a=(int*)malloc(sizeof(int));
    b=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    diff=(int*)malloc(sizeof(int));
    printf("Enter two Numbers:\n");
    scanf("%d%d",a, b);
    sumdiff(a, b, sum, diff);
    printf("Sum of %d & %d is %d\n",*a, *b, *sum);
    printf("Difference of %d & %d is %d\n",*a, *b, *diff);
    free(a);
    free(b);
    free(sum);
    free(diff);
    return 0;
}