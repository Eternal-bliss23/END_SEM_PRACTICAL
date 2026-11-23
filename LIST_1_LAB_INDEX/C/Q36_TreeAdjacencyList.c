#include <stdio.h>
#include <stdlib.h>

#define MAXV 20

struct Child
{
    int vertex;
    struct Child *next;
};

struct Child *head[MAXV];
int parentArr[MAXV];
int n = 0, built = 0;

void appendChild(int parent, int child)
{
    struct Child *node = (struct Child *)malloc(sizeof(struct Child));
    struct Child *cur;
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    node->vertex = child;
    node->next = NULL;
    if (head[parent] == NULL)
        head[parent] = node;
    else
    {
        cur = head[parent];
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
}

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
        head[i] = NULL;
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
        appendChild(p, c);
        parentArr[c] = p;
    }
    built = 1;
}

void printList(void)
{
    int i;
    struct Child *cur;
    if (!built)
    {
        printf("No tree has been entered yet.\n");
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
        printf("\n--- Tree Adjacency List ---\n");
        printf("1. Read tree (parent-child edges)\n2. Print adjacency list\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readTree();
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
