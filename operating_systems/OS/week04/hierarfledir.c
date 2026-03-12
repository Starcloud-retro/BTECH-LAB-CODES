#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[20];
    int type;
    int children;
    struct node *child[5];
};

void create(struct node *root)
{
    int i;

    printf("Enter name: ");
    scanf("%s",root->name);

    printf("Enter 1 for Directory, 2 for File: ");
    scanf("%d",&root->type);

    if(root->type==1)
    {
        printf("Enter number of children: ");
        scanf("%d",&root->children);

        for(i=0;i<root->children;i++)
        {
            root->child[i]=(struct node*)malloc(sizeof(struct node));
            create(root->child[i]);
        }
    }
    else
    {
        root->children=0;
    }
}

void display(struct node *root,int level)
{
    int i;

    for(i=0;i<level;i++)
        printf("  ");

    printf("%s\n",root->name);

    for(i=0;i<root->children;i++)
        display(root->child[i],level+1);
}

void main()
{
    struct node *root;

    root=(struct node*)malloc(sizeof(struct node));

    printf("Creating Root Directory\n");

    create(root);

    printf("\nDirectory Structure\n");

    display(root,0);
}
