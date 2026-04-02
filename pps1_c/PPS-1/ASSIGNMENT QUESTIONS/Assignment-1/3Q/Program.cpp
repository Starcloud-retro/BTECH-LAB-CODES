#include <stdio.h>
int main()
{
    int N, product = 1;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)// Calculating the product of all integers from 1 to N
    {
        product *= i;
    }

    // Displaying the price tag
    printf("price tag=%d\n", product);
    return 0;
}
