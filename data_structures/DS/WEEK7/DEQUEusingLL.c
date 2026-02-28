// DEQUE - DOUBLE ENDED QUEUE [using Linked List]
#include <stdio.h>
#include <stdlib.h>

struct DEQUE
{
    int data;
    struct DEQUE *prev;
    struct DEQUE *next;
};

struct DEQUE *front = NULL, *rear = NULL;

// Check if DEQUE is empty
int isEmpty()
{
    return (front == NULL && rear == NULL);
}

void insertFront()
{
    int value;
    struct DEQUE *newelement = (struct DEQUE*)malloc(sizeof(struct DEQUE));

    if (!newelement)
    {
        printf("\nMemory Allocation Failed!");
        return;
    }

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &value);
    newelement->data = value;
    newelement->prev = NULL;
    newelement->next = NULL;

    if (isEmpty())
    {
        front = rear = newelement;
    }
    else
    {
        newelement->next = front;
        front->prev = newelement;
        front = newelement;
    }
}

void insertRear()
{
    int value;
    struct DEQUE *newelement = (struct DEQUE*)malloc(sizeof(struct DEQUE));

    if (!newelement)
    {
        printf("\nMemory Allocation Failed!");
        return;
    }

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &value);
    newelement->data = value;
    newelement->prev = NULL;
    newelement->next = NULL;

    if (isEmpty())
    {
        front = rear = newelement;
    }
    else
    {
        newelement->prev = rear;
        rear->next = newelement;
        rear = newelement;
    }
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("\nUNDERFLOW! Cannot Delete.");
        return;
    }

    printf("\nDeleted Value: %d", front->data);

    if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct DEQUE *temp = front->next;
        temp->prev = NULL;
        free(front);
        front = temp;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("\nUNDERFLOW! Cannot Delete.");
        return;
    }

    printf("\nDeleted Value: %d", rear->data);

    if (front == rear)
    {
        free(rear);
        front = rear = NULL;
    }
    else
    {
        struct DEQUE *temp = rear->prev;
        temp->next = NULL;
        free(rear);
        rear = temp;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nDEQUE is Empty.");
        return;
    }

    printf("\nDEQUE ELEMENTS:\n");
    struct DEQUE *temp = front;
    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void peekFront()
{
    if (isEmpty())
    {
        printf("\nDEQUE is Empty.");
        return;
    }
    printf("\nFront Value is: %d\n", front->data);
}

void peekRear()
{
    if (isEmpty())
    {
        printf("\nDEQUE is Empty.");
        return;
    }
    printf("\nRear Value is: %d\n", rear->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nDEQUE OPERATION:\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete at Front\n4. Delete at Rear\n");
        printf("5. Peek Front\n6. Peek Rear\n7. Display\n8. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertFront();
                    break;
            case 2: insertRear();
                    break;
            case 3: deleteFront();
                    break;
            case 4: deleteRear();
                    break;
            case 5: peekFront();
                    break;
            case 6: peekRear();
                    break;
            case 7: display();
                    break;
            case 8: printf("\nExiting..");
                    exit(0);
                    break;
            default: printf("\nError. Try Again.");
                    break;
        }
    }
    return 0;
}