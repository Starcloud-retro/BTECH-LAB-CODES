//Implement QUEUE Operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void enqueue();
void dequeue();
void display();
int peek();
int queue[MAX];
int rear = -1;
int front = -1;
int main()
{
    int choice;
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Insert Element (enqueue)\n");
        printf("2. Delete Element (dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Peek\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("Wrong Choice!\n");
        }
    }
}
void enqueue()
{
    int data;
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!\n");
    }
    else
    {
        if (front == -1) front = 0;
        printf("Insert the element into Queue: ");
        scanf("%d", &data);
        rear++;
        queue[rear] = data;
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Element deleted: %d\n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        printf("Queue is:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
int peek()
{
    printf("PEEK: %d\n",queue[front]);
}