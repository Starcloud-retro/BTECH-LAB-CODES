#include <stdio.h>

// Function to compute factorial using pointers
void findfact(int num, long int *fact)
{
    *fact = 1;
    for (int i = 1; i <= num; i++)
    {
        *fact *= i;
    }
}

int main() {
    long int fact; // Factorial of the number
    int num1;
    
    // Take user input
    scanf("%d", &num1); 
    
    // Call the function to compute factorial
    findfact(num1, &fact);

    // Display the result
    printf("The Factorial of %d is : %ld\n", num1, fact);
    
    return 0;
}