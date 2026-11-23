#include <stdio.h>

#define MAX 20

int dataArr[MAX];
int leftArr[MAX];
int rightArr[MAX];
int count = 0, root = -1, built = 0;

void build(void)
{
    int i;
    printf("Enter number of nodes (1-%d): ", MAX);
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX)
    {
        printf("Invalid node count.\n");
        count = 0;
        return;
    }
    printf("For each node enter: data left_index right_index\n");
    printf("(use -1 for a missing child; indices are 0 to %d)\n", count - 1);
    for (i = 0; i < count; i++)
    {
        printf("Node %d: ", i);
        if (scanf("%d %d %d", &dataArr[i], &leftArr[i], &rightArr[i]) != 3)
            return;
    }
    printf("Enter root index (0 to %d): ", count - 1);
    if (scanf("%d", &root) != 1 || root < 0 || root >= count)
    {
        printf("Invalid root; using 0.\n");
        root = 0;
    }
    built = 1;
}

void preorder(int r)
{
    if (r == -1)
        return;
    printf("%d ", dataArr[r]);
    preorder(leftArr[r]);
    preorder(rightArr[r]);
}

void inorder(int r)
{
    if (r == -1)
        return;
    inorder(leftArr[r]);
    printf("%d ", dataArr[r]);
    inorder(rightArr[r]);
}

void postorder(int r)
{
    if (r == -1)
        return;
    postorder(leftArr[r]);
    postorder(rightArr[r]);
    printf("%d ", dataArr[r]);
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Binary Tree Traversals (Arrays) ---\n");
        printf("1. Build tree\n2. Preorder\n3. Inorder\n4. Postorder\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        if (choice == 0)
            return 0;
        if (choice == 1)
        {
            build();
            continue;
        }
        if (!built)
        {
            printf("Tree is empty. Build it first.\n");
            continue;
        }
        switch (choice)
        {
        case 2:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
}
