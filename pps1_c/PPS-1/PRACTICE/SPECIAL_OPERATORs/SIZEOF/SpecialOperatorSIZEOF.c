#include<stdio.h>
int main()
{
    short int a;
    unsigned short int a1;
    unsigned int a2;
    int a3;
    long int a4;
    unsigned long int a5;
    long long int a6;
    unsigned long long int a7;
    char c;
    float b;
    double n;
    printf("%d",sizeof(a));
    printf("\n%d",sizeof(a1));
    printf("\n%d",sizeof(a2));
    printf("\n%d",sizeof(a3));
    printf("\n%d",sizeof(a4));
    printf("\n%d",sizeof(a5));
    printf("\n%d",sizeof(a6));
    printf("\n%d",sizeof(a7));
    printf("\n%d",sizeof(c));
    printf("\n%d",sizeof(b));
    printf("\n%d",sizeof(n));
    return 0;
}