//BALANCING Expression [11-04-2025]
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(char);
void pop();
void status();
int top = -1;
char stack[MAX];
void main()
{
    char s[100];
    int i;
    printf("Enter Expression: ");
    scanf("%s",s);
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
            push(s[i]);
        else if(stack[top] == '(' && s[i] == ')')
            pop();
        if(s[i] == '[')
            push(s[i]);
        else if(stack[top] == '[' && s[i] == ']')
            pop();
        if(s[i] == '{')
            push(s[i]);
        else if(stack[top] == '{' && s[i] == '}')
            pop();
    }
    status();
}
void push(char s)
{
    top++;
    stack[top] = s;
}
void pop()
{
    top--;
}
void status()
{
    if(top == -1)
        printf("\nBALANCED Expression!\n");
    else
        printf("\nUNBALANCED Expression!\n");
}