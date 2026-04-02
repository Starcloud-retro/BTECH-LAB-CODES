#include<stdio.h>
int main()
{
    int n, i, EVENsum=0, ODDsum=0;
    printf("Enter 'n' Value:");
    scanf("%d",&n);
    i=0;
    while (n>=i)
        {
            if (i%2==0)
                {
                    EVENsum=EVENsum+i;
                }
            else
                {
                    ODDsum=ODDsum+i;
                }
            i++;
        }
    printf("EVENsum:%d;\nODDsum:%d",EVENsum, ODDsum);
    return 0;
}

