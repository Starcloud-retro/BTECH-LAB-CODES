// Tower of Hanoi using iterative method
#include <stdio.h>

#include<math.h>

#define MAX_DISK 64

typedef struct
{
    int items[MAX_DISK];
    int top;
    char name;
}stack;

void init(stack *s, char name)
{
    s->top = -1;
    s->name = name;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, int disk)
{
    s->items[++(s->top)] = disk;
}

int pop(stack *s)
{
    if(isEmpty(s))
    {
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(stack *s)
{
    if(isEmpty(s))
    {
        return -1;
    }
    return s->items[s->top];
}

void movedisk(stack *from, stack *to)
{
    int fromTop = pop(from);
    int toTop = pop(to);

    if (fromTop == -1)
    {
        push(from, toTop);
        printf("Move Disk %d from %c to %c\n", toTop, to->name, from->name);
    }
    else if (toTop == -1)
    {
        push(to, fromTop);
        printf("Move Disk %d from %c to %c\n", fromTop, from->name, to->name);
    }
    else if (fromTop > toTop)
    {
        push(from, fromTop);
        push(from, toTop);
        printf("Move Disk %d from %c to %c\n", toTop, to->name, from->name);
    }
    else
    {
        push(to, toTop);
        push(to, fromTop);
        printf("Move Disk %d from %c to %c\n", fromTop, from->name, to->name);
    }
}

void TOH(int n, char fromPeg, char toPeg, char auxPeg)
{
    stack s, d, a;
    init(&s,fromPeg);
    init(&d,toPeg);
    init(&a,auxPeg);
    for(int i=n; i>=1; i--)
    {
        push(&s,i);
    }

    if (n % 2 == 0)
    {
        char temp = toPeg;
        toPeg = auxPeg;
        auxPeg = temp;
    }

    int i, totalMoves = pow(2, n) - 1;

    for (i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
        {
            printf("Con1: ");   //This is used only to check for the condition
            movedisk(&s, &d);            
        }
        else if (i % 3 == 2)
        {
            printf("Con2: ");   //This is used only to check for the condition
            movedisk(&s, &a);
        }
        else if (i % 3 == 0)
        {
            printf("Con3: ");   //This is used only to check for the condition
            movedisk(&a, &d);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
 
    TOH(n, 'A', 'C', 'B');
    return 0;
}
