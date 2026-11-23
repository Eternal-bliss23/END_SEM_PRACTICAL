#include <stdio.h>

#define MAXV 20

int adj[MAXV][MAXV];
int visited[MAXV];
int queue[MAXV];
int n = 0, built = 0;

void readGraph(void)
{
    int i, j, edges, u, v, answer;
    printf("Enter number of vertices (1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Undirected graph? (1=yes, 0=directed): ");
    if (scanf("%d", &answer) != 1)
        return;
    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0)
        return;
    printf("Enter each edge as: from to  (vertices 0 to %d)\n", n - 1);
    for (i = 0; i < edges; i++)
    {
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge ignored.\n");
            continue;
        }
        adj[u][v] = 1;
        if (answer == 1)
            adj[v][u] = 1;
    }
    built = 1;
}

void bfs(int start)
{
    int front = 0, rear = 0, i, v;
    if (!built)
    {
        printf("No graph has been entered yet.\n");
        return;
    }
    if (start < 0 || start >= n)
    {
        printf("Invalid start vertex.\n");
        return;
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS order: ");
    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] && !visited[i])
            {
                if (rear == MAXV)
                {
                    printf("\nQueue is full.\n");
                    break;
                }
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main(void)
{
    int choice, start;
    for (;;)
    {
        printf("\n--- Graph BFS ---\n");
        printf("1. Read graph\n2. Run BFS from a vertex\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readGraph();
            break;
        case 2:
            printf("Enter start vertex: ");
            if (scanf("%d", &start) != 1)
                return 0;
            bfs(start);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
