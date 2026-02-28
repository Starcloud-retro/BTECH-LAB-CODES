// Depth First Traversal (DFS using stack)
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n; // number of vertices

void push(int v) {
    if (top == MAX - 1)
        printf("Stack overflow!\n");
    else
        stack[++top] = v;
}

int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

void DFS_iterative(int start) {
    int i, v;
    push(start);

    while (!isStackEmpty()) {
        v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        // Push all adjacent unvisited vertices
        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                push(i);
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Depth First Traversal starting from vertex %d:\n", start);
    DFS_iterative(start);

    printf("\n");
    return 0;
}
