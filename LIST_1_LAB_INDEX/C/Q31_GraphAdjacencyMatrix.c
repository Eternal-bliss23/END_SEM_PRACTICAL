#include <stdio.h>

#define MAXV 20

int adj[MAXV][MAXV];
int n = 0, built = 0;

void readGraph(void)
{
    int i, edges, u, v, answer, directed;
    printf("Enter number of vertices (1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    printf("Directed graph? (1=yes, 0=no): ");
    if (scanf("%d", &answer) != 1)
        return;
    directed = (answer == 1);
    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0)
    {
        printf("Invalid edge count.\n");
        return;
    }
    printf("Enter each edge as two vertex numbers (0 to %d):\n", n - 1);
    for (i = 0; i < edges; i++)
    {
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge ignored.\n");
            continue;
        }
        adj[u][v] = 1;
        if (!directed)
            adj[v][u] = 1;
    }
    built = 1;
    printf("Graph stored.\n");
}

void printMatrix(void)
{
    int i, j;
    if (!built)
    {
        printf("No graph has been entered yet.\n");
        return;
    }
    printf("\nAdjacency matrix:\n    ");
    for (j = 0; j < n; j++)
        printf("%2d ", j);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%2d: ", i);
        for (j = 0; j < n; j++)
            printf("%2d ", adj[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Graph Adjacency Matrix ---\n");
        printf("1. Read graph and edges\n2. Print adjacency matrix\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readGraph();
            break;
        case 2:
            printMatrix();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
