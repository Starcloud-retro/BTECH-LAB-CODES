//  02/04/2025 Create and Display LinkedList
#include<stdio.h>
#include<stdlib.h>

void insert_at_last(int); // Function prototype to insert a node at the end of the linked list

// Definition of the node structure
struct node
{
    int num; // Data part of the node
    struct node *link; // Pointer to the next node
};
struct node *head = NULL, *last = NULL; // Global pointers for the head and last nodes

// Function to create a linked list by inserting a new value
void create_linkedlist()
{
    int val; // Variable to store user input
    printf("Enter a Number: "); 
    scanf("%d", &val); // Take user input
    insert_at_last(val); // Call the function to insert the value at the end
}

// Function to insert a node at the end of the linked list
void insert_at_last(int value)
{
    struct node *temp; // Temporary pointer for creating a new node
    temp = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    temp->num = value; // Assign the value to the new node
    temp->link = NULL; // Initialize the link part as NULL
    if (head == NULL) // Check if the list is empty
    {
        head = temp; // Update head to point to the new node
        last = temp; // Update last to point to the new node
    }
    else
    {
        last->link = temp; // Update the link of the last node to point to the new node
        last = temp; // Update last to the new node
    }
}

// Function to display the linked list
void display_linkedlist()
{
    struct node *mylist; // Temporary pointer to traverse the list
    mylist = head;
    printf("\nYour Singly Linked List is: ");
    while (mylist != NULL) // Traverse until the end of the list
    {
        printf("%d\t", mylist->num); // Print the value of each node
        mylist = mylist->link; // Move to the next node
    }
}

// Function to insert a node at a specific position
void insert_at_position(int val, int pos)
{
    struct node *ptr1, *ptr2; // Pointers for traversal and new node
    ptr1 = head; // Initialize traversal pointer
    ptr2 = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    ptr2->num = val; // Assign the value to the new node
    ptr2->link = NULL; // Initialize the link part as NULL
    pos--; // Decrement position to account for 1-based indexing
    while (pos != 1) // Traverse to the desired position
    {
        ptr1 = ptr1->link; // Move to the next node
        pos--; // Decrement position
    }
    ptr2->link = ptr1->link; // Link the new node to the next node
    ptr1->link = ptr2; // Link the previous node to the new node
}

int main()
{
    int n, val, pos;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n); // Take input for the number of nodes
    while (n--) // Loop to create the specified number of nodes
    {
        create_linkedlist(); // Create nodes
    }
    display_linkedlist();
    // Take inputs for value and position to insert
    printf("\nEnter Value and Position to Insert: ");
    scanf("%d %d", &val, &pos);
    insert_at_position(val, pos);
    display_linkedlist();
    return 0;
}