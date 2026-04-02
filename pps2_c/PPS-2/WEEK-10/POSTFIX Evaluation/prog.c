//POSTFIX EVALUATION
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int x)
{
    top++;
    stack[top] = x;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char exp[20], *e;
    int n1, n2, n3, num;
    printf("Enter the Expression: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n2 - n1; break;
                case '*': n3 = n2 * n1; break;
                case '/': n3 = n2 / n1; break;
                case '%': n3 = n2 % n1; break;
                case '^': n3 = pow(n2,n1); break;
                
            }
            push(n3);
        }
        e++;
    }
    printf("\n The Result of Expression is: %s = %d",exp, pop());
    return 0;
}