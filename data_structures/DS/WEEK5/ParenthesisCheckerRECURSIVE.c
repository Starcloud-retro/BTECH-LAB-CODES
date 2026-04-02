// Program to check for balanced parentheses using recursion
#include <stdio.h>
#include <string.h>

#define MAX 100

int ispair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkBalanced(char *exp, int count, char stack[], int top)
{
    if (exp[count] == '\0') // End of expression
        return top == -1;   // Stack empting

    char c = exp[count];

    if (c == '(' || c == '{' || c == '[')
    {
        stack[++top] = c; // Push to stack
    }
    else if (c == ')' || c == '}' || c == ']')
    {
        if (top == -1 || !ispair(stack[top--], c)) // Pop and check
            return 0;
    }

    return checkBalanced(exp, count + 1, stack, top); // Recursive call
}

int main()
{
    char exp[MAX];
    char stack[MAX];

    printf("EXPRESSION CHECKER:\nEnter the Expression: ");
    scanf("%s", exp);

    if (checkBalanced(exp, 0, stack, -1))
        printf("\nExpression is Valid and Balanced\n");
    else
        printf("\nExpression is NOT Valid or Balanced\n");

    return 0;
}
