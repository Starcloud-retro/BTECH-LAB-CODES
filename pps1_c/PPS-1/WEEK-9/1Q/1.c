//WEEK-9; #PRIMEsum (1st PROGRAM)//
#include <stdio.h>
int PRIMEsum(int n);
int main()
{
    int n, sum;
    printf("Enter 'n' Value: ");
    scanf("%d", &n);
    sum = PRIMEsum(n);
    printf("SUM is: %d\n", sum);
    return 0;
}
int PRIMEsum(int n)
{
    int i, j, count, sum = 0;    
    for (i = 2; i <= n; i++)
    {// Starting from 2, since 1 is not prime//
        count = 0;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
                count++;
        }
        if (count == 2)
            sum += i;
    }    
    return sum;
}