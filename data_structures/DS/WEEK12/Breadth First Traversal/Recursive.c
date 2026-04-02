// Breadth First Traversal (BFS – Recursive)
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n; // number of vertices

void enqueue(int v)
{
    if (rear == MAX - 1) //full
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    if (front == -1 || front > rear) //empty
        return -1;
    return queue[front++];
}

void BFS_recursive()
{
    if (front == -1 || front > rear)
        return;

    int v = dequeue();
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            enqueue(i);
            visited[i] = 1;
        }
    }

    BFS_recursive(); // recursive call for next element in queue
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

    visited[start] = 1;
    enqueue(start);

    printf("Breadth First Traversal (recursive) starting from vertex %d:\n", start);
    BFS_recursive();

    printf("\n");
    return 0;
}

//SAMPLE INPUT-OUTPUT
// Enter number of vertices: 4
// Enter adjacency matrix of the graph:
// 0 1 1 0
// 0 0 1 0
// 1 0 0 1
// 0 0 0 1
// Enter starting vertex (0 to 3): 2

// OUTPUT:
// Breadth First Traversal (recursive) starting from vertex 2:
// 2 0 3 1
