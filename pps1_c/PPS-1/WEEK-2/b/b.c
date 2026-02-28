#include<stdio.h>
int main()
{
    int a;
    printf("Enter 'a' Value:");
    scanf("%d",&a);
    printf("\nCurrent Value of a is:%d",a);
    printf("\nPRE-INCREMENT ++a is:%d",++a);
    printf("\nCurrent Value of a is:%d",a);
    printf("\nPOST-INCREMENT a++ is:%d",a++);
    printf("\nCurrent Value of a is:%d",a);
    printf("\nPRE-DECREMENT --a is:%d",--a);
    printf("\nCurrent Value of a is:%d",a);
    printf("\nPOST-DECREMENT a-- is:%d",a--);
    printf("\nCurrent Value of a is:%d",a);
    return 0;
}