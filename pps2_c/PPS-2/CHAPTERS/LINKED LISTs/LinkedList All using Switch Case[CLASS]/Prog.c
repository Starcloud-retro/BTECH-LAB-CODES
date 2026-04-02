//LINKED LIST ALL OPERATIONS USING SWITCH CASE
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *link;
};
struct node *head=NULL, *last=NULL;
void create();
void display();
void insert_at_begin();
void insert_at_position();
void insert_at_last(int val);
void delete_at_begin();
void delete_at_position();
void delete_at_last();
void search();
void main()
{
	int op, n, val;
	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	while(n--)
	{
		create();
	}
	printf("Choose an Option:\n1. Display\n2. Insert at Begin\n3. Insert at Position\n4. Insert at Last\n5. Delete at Begin\n6. Delete at Position\n7. Delete at Last\n8. Searching\n");
	scanf("%d",&op);
	
		switch(op)
		{
			case 1: display();
							break;
			case 2: insert_at_begin();
							display();
							break;
			case 3: insert_at_position();
							display();
							break;
			case 4: printf("Enter node to insert at last: ");
							scanf("%d",&val);
							insert_at_last(val);
							display();
							break;
			case 5: delete_at_begin();
							display();
							break;
			case 6: delete_at_position();
							display();
							break;
			case 7: delete_at_last();
							display();
							break;
			case 8: search();
							break;
			default: printf("Choose only among the given options");
							break;
		}
}
void create()
{
	int val;
	printf("Enter a number: ");
	scanf("%d",&val);
	insert_at_last(val);
}
void insert_at_last(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->num=val;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		last=temp;
	}
	else
	{
		last->link=temp;
		last=temp;
	}
}
void display()
{
	struct node *mylist;
	mylist=head;
	printf("\nYour Singly Linked List is: ");
	while(mylist!=NULL)
	{
		printf("%d\t",mylist->num);
		mylist=mylist->link;
	}
}
void insert_at_begin()
{
	int val;
	printf("Enter node to insert at begin: ");
	scanf("%d",&val);
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->num=val;
	temp->link=NULL;
	temp->link=head;
	head=temp;
}
void insert_at_position()
{
	int val, pos;
	printf("Enter new node and position: ");
	scanf("%d%d",&val,&pos);
	struct node *ptr1, *ptr2;
	ptr1=head;
	ptr2=(struct node*)malloc(sizeof(struct node));
	ptr2->num=val;
	ptr2->link=NULL;
	pos--;
	while(pos!=1)
	{
		ptr1=ptr1->link;
		ptr1->link=ptr2;
	}
}
void delete_at_begin()
{
	struct node *temp;
	temp=head;
	head=head->link;
	free(temp);
}
void delete_at_position()
{
	struct node *prev, *curr;
	int pos, i=1;
	prev=head;
	printf("\nEnter position to delete: ");
	scanf("%d",&pos);
	while(i<pos-1)
	{
		prev=prev->link;
		i++;
	}
	curr=prev->link;
	prev->link=curr->link;
}
void delete_at_last()
{
	struct node *temp1, *temp2;
	temp1=head;
	temp2=last;
	while(temp1->link!=last)
	{
		temp1=temp1->link;
	}
	temp1->link=NULL;
	last=temp1;
	free(temp2);
}
void search()
{
	struct node *ptr;
	int key, flag=0;
	printf("Enter a key to search: ");
	scanf("%d",&key);
	ptr=head;
	while(ptr!=NULL)
	{
		if(key==ptr->num)
		{
			flag++;
			break;
		}
		ptr=ptr->link;
	}
	if(flag==1)
		printf("Found");
	else
		printf("Not Found");
}