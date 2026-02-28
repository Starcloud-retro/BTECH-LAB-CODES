// Function to swap two integers using Call-by-Reference
#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{
    int a, b;
    printf("Enter a, b Values:\n");
    scanf("%d%d",&a,&b);
    printf("Before SWAP: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After SWAP: a = %d, b = %d\n", a, b); // Values are swapped
    return 0;
}
