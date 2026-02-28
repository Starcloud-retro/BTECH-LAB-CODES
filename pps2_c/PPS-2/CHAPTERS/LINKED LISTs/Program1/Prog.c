//Program1: Using NUMBERS
#include<stdio.h>
#include<stdlib.h>
void insert_at_last(int);
struct node
{
	int  num;
	struct node *link;
};
struct node *head=NULL,*last = NULL;
void create_linkedlist()
{
	int val;
	printf("Enter a Number: ");
	scanf("%d",&val);
	insert_at_last(val);
}
void insert_at_last(int value)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = value;
	temp->link = NULL;
	if(head == NULL)
	{
		head = temp;
		last = temp;
	}
	else
	{
		last->link = temp;
		last = temp;
	
    }
}
void display_linkedlist()
{
	struct node *mylist;
	mylist = head;
	printf("\n Your Singly Linked List is: ");
	while(mylist != NULL)
	{
		printf("%d\t",mylist->num);
		mylist = mylist->link;
	}
}
int main()
{
	int n;
	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	while(n--)
	{
		create_linkedlist();
	}
	display_linkedlist();
	return 0;
}