#include<stdio.h>
int main()
{
    int a, b, c;
    printf("Enter 'a', 'b' Values:\n");
    scanf("%d%d",&a,&b);
    //CONDITIONAL Operator//
    printf("CONDITIONAL OPERATOR");
    c=(a>b)?a:b;
    printf("\nLARGEST of the two Numbers is:%d",c);
    //BITWISE OPERATOR//
    int x, y, z;
    printf("\n\nBITWISE-OPERATORS:");
    printf("\nEnter 'x', 'y' and 'z' Values:\n");
    scanf("%d%d%d",&x,&y,&z);
    printf("\n BITWISE-AND x&y is:%d",x&y); //BITWISE-AND//
    printf("\n BITWISE-OR x|y is:%d",x|y);  //BITWISE-OR//
    printf("\n BITWISE-EXCLUSIVE_OR x^y is:%d",x^y);    //BITWISE EXCLUSIVE-OR//
    printf("\n BITWISE-LEFT_SHIFT x<<2 is:%d",x<<2);    //BITWISE LEFT SHIFT//
    printf("\n BITWISE-RIGHT_SHIFT y>>2 is:%d",y>>2);   //BITWISE RIGHT SHIFT//
    printf("\n BITWISE-COPLEMENT ~z is:%d",~z);     //BITWISE COMPLEMENT//
    return 0;
}

