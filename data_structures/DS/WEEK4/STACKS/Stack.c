// Stack implementation using Linked List in C
#include <stdio.h>
#include <stdlib.h>

// Node structure for Stack
struct Node
{
    int data;
    struct Node* next;
};

// Global pointer to top of the stack
struct Node* top = NULL;

// Check if stack is empty
int isEmpty()
{
    return top == NULL;
}

// Push operation
void push(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

// Pop operation
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = temp->next;
    free(temp);
    printf("Popped %d from the stack.\n", popped);
    return popped;
}

// Peek operation
int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes before exiting
void freeStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

int main()
{
    int choice, d, topD;

    while (1)
    {
        printf("\nSTACK ADT OPERATIONS:\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element you want to PUSH: ");
                scanf("%d", &d);
                push(d);
                break;
            case 2:
                pop();
                break;
            case 3:
                topD = peek();
                if (topD != -1)
                    printf("Topmost element is: %d\n", topD);
                break;
            case 4:
                display();
                break;
            case 5:
                freeStack();
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nERROR. Try Again!");
        }
    }

    return 0;
}
