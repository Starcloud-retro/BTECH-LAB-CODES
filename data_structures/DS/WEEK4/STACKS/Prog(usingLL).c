// Stack implementation using Linked List in C
#include <stdio.h>
#include <stdlib.h>

// Node structure for Stack
struct Node
{
    int data;
    struct Node* next;
};

// Check if stack is empty
int isEmpty(struct Node* top)
{
    return top == NULL;
}

// Push operation
void push(struct Node** top, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

// Pop operation
int pop(struct Node** top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    printf("Popped %d from the stack.\n", popped);
    return popped;
}

// Peek operation
int peek(struct Node* top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display(struct Node* top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    while (top != NULL)
    {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    struct Node *stack = NULL;

    while(1)
    {
        int d, topD;
        printf("STACK ADT OPERATIONS:\n");
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element you want to PUSH:");
                    scanf("%d",&d);
                    push(&stack,d);
                    break;
            case 2: pop(&stack);
                    break;
            case 3: topD = peek(stack);
                    printf("Topmost element is: %d\n",topD);
                    break;
            case 4: display(stack);
                    break;
            case 5: printf("\nExiting...");
                    exit(0);
                    break;
            default:printf("\nERROR. Try Again!");
                    break;
        }
    }
    return 0;
}
