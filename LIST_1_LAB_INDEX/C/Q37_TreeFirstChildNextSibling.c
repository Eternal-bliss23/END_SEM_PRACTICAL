#include <stdio.h>

#define MAXV 20

int firstChild[MAXV];
int nextSibling[MAXV];
int hasParent[MAXV];
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
        firstChild[i] = -1;
        nextSibling[i] = -1;
        hasParent[i] = 0;
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
        if (nextSibling[c] != -1 || firstChild[c] == p)
        {
            printf("Edge ignored (invalid placement).\n");
            continue;
        }
        nextSibling[c] = firstChild[p];
        firstChild[p] = c;
        hasParent[c] = 1;
    }
    built = 1;
}

void preorder(int node)
{
    while (node != -1)
    {
        printf("%d ", node);
        preorder(firstChild[node]);
        node = nextSibling[node];
    }
}

void show(void)
{
    int i;
    if (!built)
    {
        printf("No tree has been entered yet.\n");
        return;
    }
    printf("\nNode\tFirst child\tNext sibling\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\n", i, firstChild[i], nextSibling[i]);
    printf("\nPreorder traversal: ");
    for (i = 0; i < n; i++)
        if (!hasParent[i])
            preorder(i);
    printf("\n");
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- First Child / Next Sibling Tree ---\n");
        printf("1. Read tree (parent-child edges)\n2. Print representation and preorder\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            readTree();
            break;
        case 2:
            show();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
