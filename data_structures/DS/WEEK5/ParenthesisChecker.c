// EXPRESSION PARENTHESIS CHECKER [ITERATIVE METHOD]
#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
    {
        stack[++top] = c;
    }
    else
    {
        // Silent overflow handling (optional: log or ignore)
    }
}

char pop()
{
    if (top == -1)
    {
        // Silent underflow handling (optional: log or ignore)
        return 0;
    }
    return stack[top--];
}

int ispair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *exp)
{
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1 || !ispair(pop(), c))
            {
                return 0;
            }
        }
    }
    return top == -1;
}

int main()
{
    char exp[MAX];

    printf("EXPRESSION CHECKER:\nEnter the Expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
    {
        printf("\nExpression is Valid and Balanced\n");
    }
    else
    {
        printf("\nExpression is NOT Valid or Balanced\n");
    }

    return 0;
}
