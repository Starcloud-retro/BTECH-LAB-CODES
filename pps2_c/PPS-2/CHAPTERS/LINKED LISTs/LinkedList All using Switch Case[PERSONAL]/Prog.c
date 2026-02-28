#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *link;
};
struct node *head = NULL, *last = NULL;
void categories();
void create();
void display();
void insert_at_begin();
void insert_at_position();
void insert_at_last(int val);
void delete_at_begin();
void delete_at_position();
void delete_at_last();
void search();
void exit_status();
void main()
{
    int n;
	printf("\tLINKED LIST TOOLS\n");
    printf("\nEnter Number of Nodes: ");
    scanf("%d", &n);
    printf("\n");
    while (n--)
    {
        create();
    }
    categories();
	exit_status();
}
void categories()
{
    int op, val;
    while (1)
    {
        printf("\nCATEGORIES:\n1. Display\n2. Insert at Begin\n3. Insert at Position\n4. Insert at Last\n5. Delete at Begin\n6. Delete at Position\n7. Delete at Last\n8. Searching\n9. EXIT\n");
        printf("\nChoose an Option from above: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:	display();
                	break;
            case 2:	insert_at_begin();
                	display();
                	break;
            case 3:	insert_at_position();
                	display();
                	break;
            case 4:	printf("Enter node to insert at last: ");
                	scanf("%d", &val);
                	insert_at_last(val);
                	display();
                	break;
            case 5:	delete_at_begin();
                	display();
                	break;
            case 6:	delete_at_position();
                	display();
                	break;
            case 7:	delete_at_last();
                	display();
                	break;
            case 8:	search();
                	break;
            case 9:	exit_status();
                	return;
            default:printf("Choose any one from the given options..\n");
                	break;
        }
        exit_status(); // Call exit_status after executing a task
    }
}
void exit_status()
{
    char ch;
    printf("\nDo you want to go for another Category (Y / N)? : ");
    scanf(" %c", &ch); // Added space before %c to avoid newline character issues
    if (ch == 'y' || ch == 'Y')
    {
        return; // Continue the loop in `categories`
    }
    else if (ch == 'n' || ch == 'N')
    {
        printf("Exiting the program...\n");
        exit(0); // Terminate the program
    }
    else
    {
        printf("Invalid input! Please enter Y or N.\n");
        exit_status(); // Ask again for valid input
    }
}
void create()
{
    int val;
    printf("\nEnter a number: ");
    scanf("%d", &val);
    insert_at_last(val);
}
void insert_at_last(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->num = val;
    temp->link = NULL;
    if (head == NULL)
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
void display()
{
    struct node *mylist;
    mylist = head;
    printf("\nYour Singly Linked List is: ");
    while (mylist != NULL)
    {
        printf("%d\t", mylist->num);
        mylist = mylist->link;
    }
}
void insert_at_begin()
{
    int val;
    printf("Enter node to insert at begin: ");
    scanf("%d", &val);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->num = val;
    temp->link = head;
    head = temp;
}
void insert_at_position()
{
    int val, pos;
    printf("Enter new node and position: ");
    scanf("%d%d", &val, &pos);
    struct node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->num = val;
    pos--;
    while (pos != 1 && ptr1->link != NULL) // Added boundary condition
    {
        ptr1 = ptr1->link;
        pos--;
    }
    if (pos == 1)
    {
        ptr2->link = ptr1->link;
        ptr1->link = ptr2;
    }
    else
    {
        printf("Invalid position.\n");
    }
}
void delete_at_begin()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp;
    temp = head;
    head = head->link;
    free(temp);
}
void delete_at_position()
{
    int pos, i = 1;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_at_begin();
        return;
    }
    struct node *prev, *curr;
    prev = head;
    while (i < pos - 1 && prev->link != NULL)
    {
        prev = prev->link;
        i++;
    }
    if (i == pos - 1 && prev->link != NULL)
    {
        curr = prev->link;
        prev->link = curr->link;
        free(curr);
    }
    else
    {
        printf("Invalid position.\n");
    }
}
void delete_at_last()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp1, *temp2;
    temp1 = head;
    while (temp1->link != last)
    {
        temp1 = temp1->link;
    }
    temp2 = last;
    temp1->link = NULL;
    last = temp1;
    free(temp2);
}
void search()
{
    struct node *ptr;
    int key, flag = 0;
    printf("Enter a key to search: ");
    scanf("%d", &key);
    ptr = head;
    while (ptr != NULL)
    {
        if (key == ptr->num)
        {
            flag = 1;
            break;
        }
        ptr = ptr->link;
    }
    if (flag)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found!\n");
    }
}