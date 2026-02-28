#include<stdio.h>
int sum(int a, int b);
int main()
{
    int a, b, c;
    printf("Enter a, b Values:");
    scanf("%d%d",&a,&b);
    c=sum(a,b); //FUNCTION CALL &  CALLING FUNCTION
    printf("\nSUM is:%d",c);
}
int sum(int a, int b) //FUNCTION Definition & Called Function
{
    return a+b;
}