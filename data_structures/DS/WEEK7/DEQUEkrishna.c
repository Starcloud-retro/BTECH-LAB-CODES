//DEQUE LL
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Create a new node
Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Initialize deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Insert at front
void insertFront(Deque* dq, int value) {
    Node* temp = newNode(value);
    if (!dq->front) {
        dq->front = dq->rear = temp;
    } else {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
}

// Insert at rear
void insertRear(Deque* dq, int value) {
    Node* temp = newNode(value);
    if (!dq->rear) {
        dq->front = dq->rear = temp;
    } else {
        temp->prev = dq->rear;
        dq->rear->next = temp;
        dq->rear = temp;
    }
}

// Delete from front
void deleteFront(Deque* dq) {
    if (!dq->front) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;
    free(temp);
}

// Delete from rear
void deleteRear(Deque* dq) {
    if (!dq->rear) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;
    free(temp);
}

// Display deque
void displayDeque(Deque* dq) {
    Node* temp = dq->front;
    printf("Deque: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free all nodes
void freeDeque(Deque* dq) {
    while (dq->front)
        deleteFront(dq);
    free(dq);
}

// Main function to test
int main() {
    Deque* dq = createDeque();
    int ch,val;
        
    while (1)
    {
        printf("\n1.Insertfront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.Display\n6.Exit:");
        scanf("%d",&ch);

        switch(ch) {
            case 1:printf("Enter value : ");
                    scanf("%d",&val);
                    insertFront(dq,val);break;
            case 2:printf("Enter value : ");
                    scanf("%d",&val);
                    insertRear(dq,val);break;
            case 3:deleteFront(dq);break;
            case 4:deleteRear(dq);break;
            case 5:displayDeque(dq);break;
            case 6:exit(0);
            default:printf("Invalid Choice!!");
        }
    }
    freeDeque(dq);
    return 0;
}

  // insertRear(dq,10);
    // displayDeque(dq);
    // insertFront(dq,20);
    // displayDeque(dq);
    // insertRear(dq,30);
    // displayDeque(dq);
    // deleteFront(dq);
    // displayDeque(dq);
    // insertFront(dq,40);
    // deleteRear(dq);
    // displayDeque(dq);