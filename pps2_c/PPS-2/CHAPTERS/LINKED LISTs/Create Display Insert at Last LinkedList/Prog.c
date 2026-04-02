//  02/04/2025  Create Display Insert at Last Position using LinkedList

#include<stdio.h>  
#include<stdlib.h>  

void insert_at_last(int);  

// Definition of the node structure
struct node  
{  
    int num;                 // Data part of the node  
    struct node *link;       // Pointer to the next node  
};  

struct node *head = NULL, *last = NULL;  // Global pointers for head and last nodes  

// Function to create a linked list by inserting a new value
void create_linkedlist()  
{  
    int val;  
    printf("Enter a Number: ");  
    scanf("%d", &val);  // Take user input  
    insert_at_last(val); // Insert the value at the end of the list  
}  

// Function to insert a node at the last position in the linked list
void insert_at_last(int value)  
{  
    struct node *temp;  // Temporary pointer for creating a new node  
    temp = (struct node *)malloc(sizeof(struct node));  // Allocate memory for the node  
    temp->num = value;  // Assign the value  
    temp->link = NULL;  // Initialize the link part to NULL  
    if (head == NULL)  // If the list is empty  
    {  
        head = temp;    // Update head to point to the new node  
        last = temp;    // Update last to point to the new node  
    }  
    else  
    {  
        last->link = temp;  // Update the link of the last node to point to the new node  
        last = temp;        // Update last to the new node  
    }  
}  

// Function to display the linked list
void display_linkedlist()  
{  
    struct node *mylist;  // Temporary pointer for traversal  
    mylist = head;        // Initialize traversal with head  
    printf("\nYour Singly Linked List is: ");  
    while (mylist != NULL)  // Traverse until the end of the list  
    {  
        printf("%d\t", mylist->num);  // Print the value of each node  
        mylist = mylist->link;        // Move to the next node  
    }  
}  

int main()  
{  
    int n, val;
    printf("Enter Number of Nodes: ");  
    scanf("%d", &n);  // Take input for the number of nodes  
    while (n--)  // Loop to create the specified number of nodes  
    {  
        create_linkedlist();  // Create nodes  
    }  
    display_linkedlist();
    // Take input for the value to insert at the last position  
    printf("\nEnter Value to Insert at Last Position: ");  
    scanf("%d", &val);  
    insert_at_last(val);  // Insert the new value at the end
    display_linkedlist();
    return 0;  
}