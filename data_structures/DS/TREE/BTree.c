#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 3  // Minimum degree (defines the range for number of keys) [DEGREE OR ORDER]

typedef struct BTreeNode
{
    int *keys;
    int t;
    struct BTreeNode **C;
    int n;
    int leaf;
} BTreeNode;

// Function to create a new B-Tree node
BTreeNode *createNode(int t, int leaf)
{
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->t = t;
    node->leaf = leaf;
    node->keys = (int *)malloc(sizeof(int) * (2 * t - 1));
    node->C = (BTreeNode **)malloc(sizeof(BTreeNode *) * (2 * t));
    node->n = 0;
    return node;
}

// Function to traverse the B-Tree
void traverse(BTreeNode *root)
{
    if (root != NULL)
    {
        int i;
        for (i = 0; i < root->n; i++)
        {
            if (!root->leaf)
                traverse(root->C[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->C[i]);
    }
}

// Function to search a key in the B-Tree
BTreeNode *search(BTreeNode *root, int k)
{
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == k)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->C[i], k);
}

// Function to split the child y of node x at index i
void splitChild(BTreeNode *x, int i, BTreeNode *y)
{
    int t = y->t;
    BTreeNode *z = createNode(t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = x->n; j >= i + 1; j--)
        x->C[j + 1] = x->C[j];

    x->C[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];

    x->keys[i] = y->keys[t - 1];
    x->n++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode *x, int k)
{
    int i = x->n - 1;

    if (x->leaf)
    {
        while (i >= 0 && x->keys[i] > k)
        {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    }
    else
    {
        while (i >= 0 && x->keys[i] > k)
            i--;

        if (x->C[i + 1]->n == 2 * x->t - 1)
        {
            splitChild(x, i + 1, x->C[i + 1]);

            if (k > x->keys[i + 1])
                i++;
        }
        insertNonFull(x->C[i + 1], k);
    }
}

// Function to insert a key into the B-Tree
void insert(BTreeNode **rootRef, int k)
{
    BTreeNode *r = *rootRef;

    if (r->n == 2 * r->t - 1)
    {
        BTreeNode *s = createNode(r->t, 0);
        s->C[0] = r;
        splitChild(s, 0, r);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->C[i], k);
        *rootRef = s;
    }
    else
    {
        insertNonFull(r, k);
    }
}

// Driver code
int main()
{
    BTreeNode *root = createNode(MIN_DEGREE, 1);

    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insert(&root, keys[i]);

    printf("Traversal of the B-tree:\n");
    traverse(root);
    printf("\n");

    int k = 6;
    BTreeNode *found = search(root, k);
    if (found != NULL)
        printf("Key %d found in B-Tree.\n", k);
    else
        printf("Key %d not found in B-Tree.\n", k);

    return 0;
}