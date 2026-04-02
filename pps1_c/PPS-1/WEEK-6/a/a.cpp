#include<stdio.h>
int main()
{
    int x, y;
    char val;
    printf("Enter x, y Values:");
    scanf("%d%d",&x,&y);
    printf("\nChoose an Arithemetic Operator: \n+ ADDITION\n- SUBTRACTION\n* MULTIPLICATION\n/ DIVISION\n%% MODULUS\n");
    scanf(" %c",&val);
    switch(val)
    {
        case '+':printf("\nSUM is %d",x+y);
                break;
        case '-':printf("\nSUB is %d",x-y);
                break;
        case '*':printf("\nMUL is %d",x*y);
                break;
        case '/':printf("\nDIV is %d",x/y);
                break;
        case '%':printf("\nMOD is %d",x%y);
                break;
        default:printf("Choose any one of the Arthemetic Operator Only.");
                break;
    }
    return 0;
}