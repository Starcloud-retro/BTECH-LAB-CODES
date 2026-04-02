//EXPRESSION PARENTHESIS CHECKER
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
char push(char c)
{
    
    if(top < MAX-1)
    {
        stack[++top] = c;
    }
    else
    {
        printf("ERROR. Stack overflow");
        return 0;
    }
}
char pop()
{
    if(top>=-1)
    {
        return stack[top--];
    }
    else
    {
        printf("STACK UNDERFLOW");
        return 0;
    }
}
int ispair(char open, char close)
{
    return (open == '('&&close==')')||(open == '{'&& close == '}')||(open == '['&& close == ']');
}
int  isBalanced(char *exp)
{
    int i;
    top = -1;
        for(i=0 ;exp[i] != '\0';i++)
        {
            char c = exp[i];
            if(c == '(' || c == '{' || c == '[')
            {
                push(c);
            }
            else if( c == ')' || c == '}' || c == ']')
            {
                if(top == -1 || !ispair(pop(),c))
                {
                    return 0;
                }
            }
        }
        return top==-1;
}

int main()
{
    char exp[MAX];
    int i;
    printf("Enter the Expression : ");
    gets(exp);
    if(isBalanced(exp))
    {
        printf("Valid and Balanced");
    }
    else
    {
        printf("NOT VALID.");
    }
    return 0;
}