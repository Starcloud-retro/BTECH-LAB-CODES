#include<stdio.h>
int main()
{
    int n, a, b, oper;
    printf("ARITHMETIC CALCULATOR:\n\tChoose an Operation:\n\t\t1.(+) ADDITION\n\t\t2.(-) SUBTRACTION\n\t\t3.(*) MULTIPLICATION\n\t\t4.(/) DIVISION\n\t\t5.(%%) MODULUS\nCHOOSED OPTION:");
    scanf("%d",&oper);
    switch (oper)
        {
            case 1: printf("ADDITION (+) is:%d",a+b);
                    break;
            case 2: printf("SUBTRACTION (-) is:%d",a-b);
                    break;
            case 3: printf("MULTIPLICATION (*) is:%d",a*b);
                    break;
            case 4: printf("DIVISION (/) is:%d",a/b);
                    break;
            case 5: printf("MODULUS (%%) is:%d",a%b);
                    break;
            default : printf("Choose any One from the Above OPERATORS.");
                    break;
        }
}
