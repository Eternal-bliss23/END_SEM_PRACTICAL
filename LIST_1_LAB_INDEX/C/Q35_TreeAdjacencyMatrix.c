#include <stdio.h>

#define MAXV 20

int adj[MAXV][MAXV];
int parentArr[MAXV];
int n = 0, built = 0;

void readTree(void)
{
    int i, p, c;
    printf("Enter number of nodes (1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV)
    {
        printf("Invalid number of nodes.\n");
        n = 0;
        return;
    }
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
        parentArr[i] = -1;
    }
    printf("Enter %d parent-child edge(s) as: parent child (nodes 0 to %d)\n",
           n - 1, n - 1);
    for (i = 0; i < n - 1; i++)
    {
        if (scanf("%d %d", &p, &c) != 2 || p < 0 || p >= n || c < 0 || c >= n)
        {
            printf("Invalid edge ignored.\n");
            continue;
        }
        adj[p][c] = 1;
        parentArr[c] = p;
    }
    built = 1;
}

void printTree(void)
{
    int i, j;
    if (!built)
    {
        printf("No tree has been entered yet.\n");
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
    printf("\nNode\tParent\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, parentArr[i]);
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Tree Adjacency Matrix ---\n");
        printf("1. Read tree (parent-child edges)\n2. Print matrix and parent array\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readTree();
            break;
        case 2:
            printTree();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
