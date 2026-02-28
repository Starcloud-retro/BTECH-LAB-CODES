//IMPLEMENT QUEUE OPERATIONS
#include<stdio.h>
#define MAX 50
int queue[MAX], front = -1, rear = -1;
void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue is Overflowing!");
        return;
    }
    if(front == -1)
    {
        front = 0;
    }
    queue[++rear] = value;
    printf("%d enqueued to Queue!",value);
}
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("%d dequeued from the list!",queue[front++]);
}
void peek()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Front Element is: %d",queue[front]);
}
void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("QUEUE ELEMENTS:\n");
    for(int i = 0; i <= rear; i++)
    {
        printf("\n%d",queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice, value;
    do
    {
        printf("QUEUE OPERATIONS:\n1. ENQUEUE\n2. DEQUEUE\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Choose a Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter value to Enqueue: ");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nExiting......\n");
                    break;
            default: printf("Invalid Choice. Try Again!");
        }
    } while (choice != 5);
    return 0;
}