//works online in ONLINE COMPILER
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    int a, b, sum;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    
    sum = a + b;
    printf("SUM is: %d",sum);
    return 0;
}