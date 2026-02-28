//CIRCULAR SINGLY LINKED LIST IMPLEMENTATION IN C
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void display()
{
    struct node* temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Circular List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void insert_at_begin(int d)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = d;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insert_at_end(int d)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = d;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_at_position(int d, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_at_begin(d);
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = d;

    struct node* temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
    {
        printf("Not Possible. Out of Range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_begin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == head)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        struct node* last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        free(temp);
    }
}


void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == head)
    {
        free(temp);
        head = NULL;
        return;
    }

    struct node* prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

void delete_at_position(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        delete_at_begin();
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    int i;
    for (i = 1; i < pos && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos)
    {
        printf("Not Possible. Out of Range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
 
void search(int d)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    int pos = 1;
    do
    {
        if (temp->data == d)
        {
            printf("Element %d found at position %d\n", d, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found in the list\n", d);
}

int main()
{
    int choice, data, pos;
    while (1)
    {   //CIRCULAR SINGLY LINKED LIST MENU
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_begin(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                insert_at_position(data, pos);
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
