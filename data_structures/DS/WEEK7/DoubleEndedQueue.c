//DEQUE - DOUBLE ENDED QUEUE [ITERATIVE]
#include <stdio.h>
#include <stdlib.h>

#define MAX 25

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
}Deque;

void initialize(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}
void insertFront(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert %d at front.\n", value);
        return;
    }
    if (isEmpty(dq) || dq->front == -1) //any one
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front = dq->front - 1;
    }

    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

void insertRear(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert %d at rear.\n", value);
        return;
    }
    if (isEmpty(dq) || dq->front == -1) //any one
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    int deletedValue = dq->arr[dq->front];
    if (dq->front == dq->rear) //only one element
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }

    printf("Deleted %d from front.\n", deletedValue);
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    int deletedValue = dq->arr[dq->rear];
    if (dq->front == dq->rear) //only one element
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
    printf("Deleted %d from rear.\n", deletedValue);
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int peekFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    printf("Front element: %d\n", dq->arr[dq->front]);
    return dq->arr[dq->front];
}

int peekRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No rear element.\n");
        return -1;
    }
    printf("Rear element: %d\n", dq->arr[dq->rear]);
    return dq->arr[dq->rear];
}

int main()
{
    Deque dq;
    initialize(&dq);

    int choice, value;

    printf("DEQUE OPERATIONS\n");

    while (1)
    {
        printf("Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;

            case 3:
                deleteFront(&dq);
                break;

            case 4:
                deleteRear(&dq);
                break;

            case 5:
                peekFront(&dq);
                break;

            case 6:
                peekRear(&dq);
                break;

            case 7:
                display(&dq);
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
