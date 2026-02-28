// Function to swap two integers using Call-by-Value
#include <stdio.h>
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
int main()
{
    int a, b;
    printf("Enter a, b Values:\n");
    scanf("%d%d",&a,&b);
    printf("Before SWAP: a = %d;B = %d",a,b);
    swap(a, b);
    printf("\nAfter SWAP: a = %d; b = %d\n", a, b);
    return 0;
}