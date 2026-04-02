// Depth First Traversal (DFS – Recursive)
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void DFS_recursive(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS_recursive(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Depth First Traversal (recursive) starting from vertex %d:\n", start);
    DFS_recursive(start);

    printf("\n");
    return 0;
}

//SAMPLE INPUT OUTPUT
// Enter number of vertices: 4
// Enter adjacency matrix of the graph:
// 0 1 1 0
// 0 0 1 0
// 1 0 0 1
// 0 0 0 1
// Enter starting vertex (0 to 3): 2

// OUTPUT:
// Depth First Traversal (recursive) starting from vertex 2:
// 2 0 1 3

