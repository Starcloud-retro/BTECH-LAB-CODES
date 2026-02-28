#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Global queue pointer
struct Queue* queue;

// Check if queue is empty
int isEmpty()
{
    return queue->front == NULL;
}

// Enqueue operation
void enqueue(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d to the queue.\n", data);
}

// Dequeue operation
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    printf("Dequeued %d from the queue.\n", dequeued);
    return dequeued;
}

// Peek operation
int peek() {
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

// Display queue elements
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue (Front → Rear): ");
    while (temp)
    {
        printf("%d", temp->data);
        if (temp->next)
            printf(" → ");
        temp = temp->next;
    }
    printf("\n");
}

// Free the entire queue
void freeQueue() {
    while (!isEmpty())
        dequeue();
    free(queue);
}

// Main function
int main()
{
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue)
    {
        printf("Memory allocation failed for queue.\n");
        return 1;
    }
    queue->front = queue->rear = NULL;

    int choice, data;
    while (1) {
        printf("\nQUEUE ADT OPERATIONS:\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. PEEK\n4. DISPLAY\n5. EXIT\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to ENQUEUE: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Front Element: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nEXITING...\n");
                freeQueue();
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
