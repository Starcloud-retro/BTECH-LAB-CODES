//Write a C-Program to implement BIT-Fields in C
#include<stdio.h>
struct date
{
	unsigned int d:5;
	unsigned int m:4;
	unsigned int y:11;
}dt;
int main()
{
	printf("%d",sizeof(dt));
	return 0;
}
