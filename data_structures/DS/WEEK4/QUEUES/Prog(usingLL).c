// Queue implementation using Linked List in C
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

// Check queue is empty
int isEmpty(struct Queue* q)
{
    return q->front == NULL;
}

// Enqueue
void enqueue(struct Queue* q, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d to the queue.\n", data);
}

// Dequeue
int dequeue(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeued = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    printf("Dequeued %d from the queue.\n", dequeued);
    return dequeued;
}

// Peek
int peek(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Display
void display(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements (Front to Rear):\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;

    int choice, data;
    while(1)
    {
        printf("QUEUE ADT OPERATIONS:\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY\n5.EXIT\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to ENQUEUE: ");
                    scanf("%d",&data);
                    enqueue(queue,data);
                    break;
            case 2: dequeue(queue);
                    break;
            case 3: printf("Front Element: %d\n",peek(queue));
                    break;
            case 4: display(queue);
                    break;
            case 5: printf("\nEXITING....\n");
                    exit(0);
                    break;
            default: printf("\nError. Try again.\n");
                    break;
        }
    }
    return 0;
}
