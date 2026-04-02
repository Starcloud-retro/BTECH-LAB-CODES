// Doubly Linked List Implementation in C
// This program implements a doubly linked list with various operations such as insertion, deletion, and
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

// Create new node
struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Insert at beginning
void insert_at_beginning(int data)
{
    struct node* newnode = createnode(data);
    if (head != NULL)
    {
        newnode->next = head;
        head->prev = newnode;
    }
    head = newnode;
}

// Insert at end
void insert_at_end(int data)
{
    struct node* newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert after a specific node
void insert_after(int key, int data)
{
    struct node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node with data %d not found.\n", key);
        return;
    }

    struct node* newnode = createnode(data);
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// Insert at a specific position
void insert_at_position(int pos, int data)
{
    if (pos < 1)
    {
        printf("Invalid position. Must be >= 1.\n");
        return;
    }
    if (pos == 1)
    {
        insert_at_beginning(data);
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    struct node* newnode = createnode(data);
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// Delete from beginning
void delete_from_beginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete from end
void delete_from_end()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete at a specific position
void delete_at_position(int pos)
{
    if (pos < 1)
    {
        printf("Invalid position. Must be >= 1.\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        delete_from_beginning();
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display list forward
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display list backward
void display_from_back()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Doubly Linked List in reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main menu
int main()
{
    int choice, data, key, pos;

    while (1)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete at Position\n");
        printf("8. Display List\n");
        printf("9. Display from Backwards\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_after(key, data);
                break;
            case 4:
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_at_position(pos, data);
                break;
            case 5:
                delete_from_beginning();
                break;
            case 6:
                delete_from_end();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(pos);
                break;
            case 8:
                display();
                break;
            case 9:
                display_from_back();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
