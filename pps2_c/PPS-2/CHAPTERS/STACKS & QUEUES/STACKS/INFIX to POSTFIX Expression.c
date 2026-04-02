#include<stdio.h>
#include<ctype.h>
char stack[50];
int top = -1;
void push(char s)
{
    stack[++top] = s;
}
char pop()
{
    return stack[top--];
}
int priority(char s)
{
    if(s == '(')
        return 0;
    if(s == '+' || s == '-')
        return 1;
    if(s == '*' || s == '/' || s == '%')
        return 2;
    if(s == '^')
        return 3;
    return 0;
}
int main()
{
    char s1[50], *e, s;
    printf("Enter String: ");
    scanf("%s",s1);
    e = s1;
    while(*e != '\0')
    {
        if(isalpha(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((s = pop()) != '(')
                printf("%c",s);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
   }
    while(top != -1)
    {
        printf("%c",pop());
    }
    return 0;
}