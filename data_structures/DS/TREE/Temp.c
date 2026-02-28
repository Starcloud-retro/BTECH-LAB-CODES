#include <stdio.h>
#include <stdlib.h>

typedef struct BTreeNode {
    int *keys;
    int order;
    struct BTreeNode **C;
    int n;
    int leaf;
} BTreeNode;

// Create a new B-Tree node
BTreeNode *createNode(int order, int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->order = order;
    node->leaf = leaf;
    node->keys = (int *)malloc(sizeof(int) * (order - 1));
    node->C = (BTreeNode **)malloc(sizeof(BTreeNode *) * order);
    node->n = 0;

    // Initialize child pointers to NULL
    for (int i = 0; i < order; i++)
        node->C[i] = NULL;

    return node;
}

// Traverse the B-Tree
void traverse(BTreeNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->C[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->C[i]);
    }
}

// Search a key in the B-Tree
BTreeNode *search(BTreeNode *root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == k)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->C[i], k);
}

// Split the child y of node x at index i
void splitChild(BTreeNode *x, int i, BTreeNode *y) {
    int t = (x->order + 1) / 2;
    BTreeNode *z = createNode(x->order, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf) {
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

// Insert a key into a non-full node
void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;

        // Ensure child exists before accessing
        if (x->C[i + 1] == NULL)
            x->C[i + 1] = createNode(x->order, 1); // default to leaf

        if (x->C[i + 1]->n == x->order - 1) {
            splitChild(x, i + 1, x->C[i + 1]);

            if (k > x->keys[i + 1])
                i++;
        }

        // Ensure child exists again after split
        if (x->C[i + 1] == NULL)
            x->C[i + 1] = createNode(x->order, 1);

        insertNonFull(x->C[i + 1], k);
    }
}

// Insert a key into the B-Tree
void insert(BTreeNode **rootRef, int k) {
    BTreeNode *r = *rootRef;

    if (r->n == r->order - 1) {
        BTreeNode *s = createNode(r->order, 0);
        s->C[0] = r;
        splitChild(s, 0, r);
        int i = 0;
        if (s->keys[0] < k)
            i++;

        if (s->C[i] == NULL)
            s->C[i] = createNode(s->order, 1);

        insertNonFull(s->C[i], k);
        *rootRef = s;
    } else {
        insertNonFull(r, k);
    }
}

// Main driver with dynamic order
int main() {
    int order;
    printf("Enter the Order of the B-Tree (minimum 3): ");
    scanf("%d", &order);

    if (order < 3) {
        printf("Order must be at least 3. Exiting.\n");
        return 1;
    }

    BTreeNode *root = createNode(order, 1);
    int choice, key;

    printf("=== B-Tree Operations (Order = %d) ===\n", order);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Search for a key\n");
        printf("3. Traverse B-Tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                printf("Inserted %d into the B-Tree.\n", key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found in the B-Tree.\n", key);
                else
                    printf("Key %d not found in the B-Tree.\n", key);
                break;

            case 3:
                printf("B-Tree traversal: ");
                traverse(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}