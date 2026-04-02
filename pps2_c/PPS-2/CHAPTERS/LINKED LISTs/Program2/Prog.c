//Program2: STUDENT DETAILS
#include<stdio.h>
#include<stdlib.h>
void insert_at_last();
struct student
{
	int  num;
	char name[25];
	float gpa;
	struct student *link;
};
struct student *head = NULL,*last = NULL;
void create_linkedlist()
{
	insert_at_last();
}
void insert_at_last()
{
	struct student *temp;
	temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter details\n");
	scanf("%d%s%f",&temp->num,temp->name,&temp->gpa);
	temp->link=NULL;
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
	struct student *mylist;
	mylist = head;
	printf("\nYour Singly Linked List is: ");
	while(mylist != NULL)
	{
		printf("\n%d\t%s\t%f\t",mylist->num,mylist->name,mylist->gpa);
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