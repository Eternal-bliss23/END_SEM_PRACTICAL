#include <stdio.h>

#define MAXV 20

int adj[MAXV][MAXV];
int n = 0, directed = 0, built = 0;

void readGraph(void)
{
    int i, j, answer;
    printf("Enter number of vertices (1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }
    printf("Directed graph? (1=yes, 0=no): ");
    if (scanf("%d", &answer) != 1)
        return;
    directed = (answer == 1);
    printf("Enter the %d x %d adjacency matrix (0/1 values):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (scanf("%d", &adj[i][j]) != 1)
                return;
            adj[i][j] = (adj[i][j] != 0);
        }
    built = 1;
    printf("Graph stored.\n");
}

void showDegrees(void)
{
    int i, j, out, in;
    if (!built)
    {
        printf("No graph has been entered yet.\n");
        return;
    }
    printf("\nVertex\tOut-degree\tIn-degree\tTotal degree\n");
    for (i = 0; i < n; i++)
    {
        out = in = 0;
        for (j = 0; j < n; j++)
        {
            out += adj[i][j];
            in += adj[j][i];
        }
        if (!directed)
            in = out;
        printf("%d\t%d\t\t%d\t\t%d\n", i, out, in, directed ? out + in : out);
    }
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Graph Degree using Matrix ---\n");
        printf("1. Read graph (matrix + directed/undirected)\n");
        printf("2. Display degrees\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readGraph();
            break;
        case 2:
            showDegrees();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
