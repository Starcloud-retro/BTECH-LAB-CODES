//Create a Linked List using three Nodes and Display using Numbers
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int number;
    struct node *link;
};
struct node *head = NULL, *last = NULL;
void create_linked_list();
void insert_at_last(int value);
void display_linked_list();
int main()
{
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    printf("\nCreating Linked List (Singly)\n");
    while(n--)
    {
        create_linked_list();
    }
    display_linked_list();
    return 0;
}
void create_linked_list()
{
    int val;
    printf("Enter a number: \n");
    scanf("%d",&val);
    insert_at_last(val);
}
void insert_at_last(int val)
{
    struct node *temp_node;
    temp_node=(struct node*)malloc(sizeof(struct node));
    temp_node -> number = val;
    temp_node -> link = NULL;
    if(head == NULL)
    {
        head = temp_node;
        last = temp_node;
    }
    else
    {
        last -> link = temp_node;
        last = temp_node;
    }
}
void display_linked_list()
{
    printf("Your Linked List is : \n");
    struct node *mylist;
    mylist = head;
    while(mylist != NULL)
    {
        printf("%d\t",mylist -> number);
        mylist = mylist -> link;
    }
}