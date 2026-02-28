//CIRCULAR QUEUE IMPLEMENTATION using Array [only ITERATIVE is Possible Practically]
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void enqueue() //later UPDATED this Code to take input from user only after he checking for overflow condition.
{
    int x;

    if ((front == (rear + 1) % MAX)) // Queue is full
    {
        printf("OVERFLOW! Cannot insert.");
        return;
    }

    if (front == -1) // First element
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    printf("ENTER THE ELEMENT TO BE INSERTED: ");
    scanf("%d", &x);
    queue[rear] = x;
    printf("%d inserted into queue.\n", x);
}

void dequeue()
{
    if (front == -1) // Queue is empty
    {
        printf("UNDERFLOW! Queue is empty.\n");
        return;
    }

    int deleted = queue[front];

    if (front == rear) // Only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%d eliminated from queue.\n", deleted);
}

void display()
{
    if (front == -1)
    {
        printf("QUEUE IS EMPTY!\n");
        return;
    }

    printf("QUEUE ELEMENTS ARE: ");

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\nCIRCULAR QUEUE OPERATIONS\n");
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting program.\n");
                    exit(0);
                    break;
            default:printf("INVALID CHOICE!\n");
                    break;
        }
    }
    return 0;
}
