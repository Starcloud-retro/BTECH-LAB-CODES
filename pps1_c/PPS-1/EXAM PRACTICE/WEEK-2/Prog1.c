#include<stdio.h>
int main()
{
	int x, y; char val;
    printf("Enter two Values: ");
    scanf("%d%d",&x,&y);
CASES:
    printf("Choose an Arithmetic Operator:\n'+' Addition\n'-' Subtraction\n'*' Multiplication\n: ");
    scanf(" %c",&val);
    switch(val)
    {
    	case '+': printf("ADDITION is: %d",x+y);
        		break;
        case '-': printf("SUBTRACTION is: %d",x-y);
        		break;
        case '*': printf("MULTIPLICATION is: %d",x*y);
        		break;
        default : printf("Choose any One of the arithmetic Operator!\n");
        		goto CASES;
                break;
    }
    return 0;
}