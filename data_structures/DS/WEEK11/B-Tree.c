#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variable for ORDER (minimum degree)
int ORDER;

// Structure of a B-Tree node
typedef struct BTreeNode {
    int *keys;                  // Array of keys
    struct BTreeNode **children; // Array of child pointers
    int n;                      // Current number of keys
    bool leaf;                  // Is true when node is leaf
} BTreeNode;

// Function to create a new B-Tree node
BTreeNode* createNode(bool leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    node->keys = (int*)malloc((2 * ORDER - 1) * sizeof(int));
    node->children = (BTreeNode**)malloc((2 * ORDER) * sizeof(BTreeNode*));
    for (int i = 0; i < 2 * ORDER; i++)
        node->children[i] = NULL;
    return node;
}

// Function to traverse the B-Tree
void traverse(BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->children[i]);
    }
}

// Function to search a key in the B-Tree
BTreeNode* search(BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == k)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->children[i], k);
}

// Function to split the child y of node x at index i
void splitChild(BTreeNode* x, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->leaf);
    z->n = ORDER - 1;

    // Copy last (ORDER-1) keys of y to z
    for (int j = 0; j < ORDER - 1; j++)
        z->keys[j] = y->keys[j + ORDER];

    // Copy last ORDER children of y to z
    if (!y->leaf) {
        for (int j = 0; j < ORDER; j++)
            z->children[j] = y->children[j + ORDER];
    }

    y->n = ORDER - 1;

    // Shift children of x to make space for z
    for (int j = x->n; j >= i + 1; j--)
        x->children[j + 1] = x->children[j];

    x->children[i + 1] = z;

    // Shift keys of x to make space for middle key
    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];

    x->keys[i] = y->keys[ORDER - 1];
    x->n++;
}

// Insert a key into a non-full node
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        // Shift keys to make space
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->keys[i])
            i--;

        i++;
        if (x->children[i]->n == 2 * ORDER - 1) {
            splitChild(x, i, x->children[i]);
            if (k > x->keys[i])
                i++;
        }
        insertNonFull(x->children[i], k);
    }
}

// Insert a key into the B-Tree
BTreeNode* insert(BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2 * ORDER - 1) {
        BTreeNode* s = createNode(false);
        s->children[0] = root;
        splitChild(s, 0, root);

        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->children[i], k);

        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// Driver program
int main() {
    BTreeNode* root = NULL;
    int choice, key;

    printf("Enter the ORDER (minimum degree) of the B-Tree: ");
    scanf("%d", &ORDER);

    while (1) {
        printf("\n--- B-Tree Operations ---\n");
        printf("1. Insert\n2. Search\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    BTreeNode* result = search(root, key);
                    if (result != NULL)
                        printf("Key %d found in B-Tree.\n", key);
                    else
                        printf("Key %d not found.\n", key);
                }
                break;
            case 3:
                printf("B-Tree traversal: ");
                traverse(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
