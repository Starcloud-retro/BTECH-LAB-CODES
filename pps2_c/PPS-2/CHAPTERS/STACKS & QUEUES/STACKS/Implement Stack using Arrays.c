//Implementation of Stack Using Arrays: [11-04-2025]
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top = -1;
int stack[MAX];
void push();
void pop();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\nCONDITIONS:\n1. push()\n2. pop()\n3. display()\n4. exit()\nSelect a Condition :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:    printf("Invalid option! Please select a valid one.\n");
                        break;
        }
    }
    return 0;
}
void push()
{
    int num;
    printf("Enter Element: ");
    scanf("%d",&num);
    if(top == MAX-1)
    {
        printf("\nStack will Overflow!");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("\nStack will Underflow!");
    }
    else
    {
        printf("%d Element is removed from STACK\n", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is Empty!");
    }
    else
    {
        printf("\nStack Elements are:\n");
        for(i = top; i >= 0; i--)
        {
            printf("\t%d\n",stack[i]);
        }
    }
}