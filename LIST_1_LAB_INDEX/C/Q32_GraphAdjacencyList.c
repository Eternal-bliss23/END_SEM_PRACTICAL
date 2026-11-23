#include <stdio.h>
#include <stdlib.h>

#define MAXV 20

struct Edge
{
    int vertex;
    struct Edge *next;
};

struct Edge *head[MAXV];
int n = 0, built = 0;

void appendEdge(int from, int to)
{
    struct Edge *node = (struct Edge *)malloc(sizeof(struct Edge));
    struct Edge *cur;
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    node->vertex = to;
    node->next = NULL;
    if (head[from] == NULL)
        head[from] = node;
    else
    {
        cur = head[from];
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
}

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
        head[i] = NULL;
    printf("Directed graph? (1=yes, 0=no): ");
    if (scanf("%d", &answer) != 1)
        return;
    directed = (answer == 1);
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
        appendEdge(u, v);
        if (!directed)
            appendEdge(v, u);
    }
    built = 1;
}

void printList(void)
{
    int i;
    struct Edge *cur;
    if (!built)
    {
        printf("No graph has been entered yet.\n");
        return;
    }
    printf("\nAdjacency list:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        cur = head[i];
        while (cur != NULL)
        {
            printf("%d ", cur->vertex);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Graph Adjacency List ---\n");
        printf("1. Read graph and edges\n2. Print adjacency list\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readGraph();
            break;
        case 2:
            printList();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
