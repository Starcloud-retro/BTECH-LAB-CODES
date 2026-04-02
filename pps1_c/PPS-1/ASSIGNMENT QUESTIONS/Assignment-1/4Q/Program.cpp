#include<stdio.h>
int main()
{
    int a, b;
    char oper;
    printf("\nEnter the Number a, b:");
    scanf("%d%d",&a,&b);
    printf("\nChoose an OPERATOR:\n+ ADDITION\n- SUBTRACTION\n* MULTIPLICATION\n/ DIVISION\n%% MODULUS\n");
    scanf(" %c",&oper);
    switch (oper)
    {
        case '+':printf("\nADDITION is:%d",a+b);
                break;
        case '-':printf("\nSUBTRACTION is:%d",a-b);
                break;
        case '*':printf("\nMULTIPLICATION is:%d",a*b);
                break;
        case '/':printf("\nDIVISION is:%d",a/b);
                break;
        case '%':printf("\nMODULUS is:%d",a%b);
                break;
        default: printf("\nChoose any one from the OPERATORS provided.");
                break;
    }
}