#include<stdio.h>
int main()
{
    int n, a, b;
    printf("INCREMENT & DECREMENT OPERATOR:\nEnter 'n' Value:");
    scanf("%d",&n);
    printf("\nCurrent Value of 'n' is:%d",n);
    printf("\nPOST-INCREMENT Operator:%d",n++);
    printf("\nCurrent Value of 'n' is:%d",n);
    printf("\nPRE-INCREMENT Operator:%d",++n);
    printf("\nCurrent Value of 'n' is:%d",n);
    printf("\nPOST-DECREMENT Operator:%d",n--);
    printf("\nCurrent Value of 'n' is:%d",n);
    printf("\nPRE-DECREMENT Operator:%d",--n);
    printf("\nCurrent Value of 'n' is:%d",n);
    printf("\n\nASSIGNMENT OPERATOR:\nEnter 'b' Values:");
    scanf("%d",&b);
    a=b;
    printf("\nValue of 'a' is:%d",a);
    a+=b;
    printf("\nAfter ASSIGNMENT ADDITION 'a' is:%d",a);
    a-=b;
    printf("\nAfter ASSIGNMENT SUBTRACTION 'a' is:%d",a);
    a*=b;
    printf("\nAfter ASSIGNMENT MULTIPLICATON 'a' is:%d",a);
    a/=b;
    printf("\nAfter ASSIGNMENT DIVISION 'a' is:%d",a);
    a%=b;
    printf("\nAfter ASSIGNMENT MODULUS 'a' is:%d",a);
    return 0;
}

