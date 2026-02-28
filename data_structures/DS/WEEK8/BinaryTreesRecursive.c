//RECURSIVE BINARY TREE
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// In-order traversal: Left -> Root -> Right
void inOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal: Root -> Left -> Right
void preOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal: Left -> Right -> Root
void postOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the BST
int main()
{
    struct Node* root = NULL;
    int i, n;
    printf("\nEnter the number of values: ");
    scanf("%d",&n);
    int values[n];
    printf("\nEnter the values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&values[i]);
        root = insert(root, values[i]);
    }
    
    //To use STATIC way of insertion
    // Insert values into the BST
    // int values[] = {50, 30, 70, 20, 40, 60, 80};
    // int n = sizeof(values) / sizeof(values[0]);

    // for (i = 0; i < n; i++)
    // {
    //     root = insert(root, values[i]);
    // }

    // Display traversals

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
