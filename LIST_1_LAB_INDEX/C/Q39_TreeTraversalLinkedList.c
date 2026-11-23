#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

static struct Node *root = NULL;

struct Node *create(void)
{
    int value;
    struct Node *node;
    printf("Enter data (or -1 for no node): ");
    if (scanf("%d", &value) != 1 || value == -1)
        return NULL;
    node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->data = value;
    printf("Left child of %d:\n", value);
    node->left = create();
    printf("Right child of %d:\n", value);
    node->right = create();
    return node;
}

void freeTree(struct Node *node)
{
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(struct Node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main(void)
{
    int choice;
    for (;;)
    {
        printf("\n--- Binary Tree Traversals (Linked List) ---\n");
        printf("1. Build tree\n2. Preorder\n3. Inorder\n4. Postorder\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            freeTree(root);
            printf("Building root:\n");
            root = create();
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Preorder: ");
                preorder(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Inorder: ");
                inorder(root);
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Postorder: ");
                postorder(root);
                printf("\n");
            }
            break;
        case 0:
            freeTree(root);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
