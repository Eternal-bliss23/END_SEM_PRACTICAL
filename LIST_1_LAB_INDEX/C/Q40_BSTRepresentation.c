#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

static struct Node *root = NULL;

void insert(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *cur = root, *parent = NULL;
    if (node == NULL)
    {
        printf("Memory allocation failed. Cannot insert.\n");
        return;
    }
    node->data = value;
    node->left = node->right = NULL;
    while (cur != NULL)
    {
        parent = cur;
        if (value < cur->data)
            cur = cur->left;
        else if (value > cur->data)
            cur = cur->right;
        else
        {
            printf("%d already exists.\n", value);
            free(node);
            return;
        }
    }
    if (parent == NULL)
        root = node;
    else if (value < parent->data)
        parent->left = node;
    else
        parent->right = node;
    printf("Inserted %d.\n", value);
}

void search(int value)
{
    struct Node *cur = root;
    while (cur != NULL && cur->data != value)
        cur = (value < cur->data) ? cur->left : cur->right;
    if (cur == NULL)
        printf("%d not found.\n", value);
    else
        printf("%d found.\n", value);
}

void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void display(void)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return;
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

int minValue(struct Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node->data;
}

struct Node *removeNode(struct Node *node, int value)
{
    struct Node *temp;
    if (node == NULL)
        return NULL;
    if (value < node->data)
        node->left = removeNode(node->left, value);
    else if (value > node->data)
        node->right = removeNode(node->right, value);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        if (node->left == NULL)
        {
            temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL)
        {
            temp = node->left;
            free(node);
            return temp;
        }
        node->data = minValue(node->right);
        node->right = removeNode(node->right, node->data);
    }
    return node;
}

void deleteValue(int value)
{
    if (root == NULL)
    {
        printf("BST is empty. Cannot delete.\n");
        return;
    }
    root = removeNode(root, value);
    printf("Delete operation finished for %d.\n", value);
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- BST Representation ---\n");
        printf("1. Insert\n2. Search\n3. Inorder display\n4. Delete\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
        case 2:
        case 4:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 0;
            if (choice == 1)
                insert(value);
            else if (choice == 2)
                search(value);
            else
                deleteValue(value);
            break;
        case 3:
            display();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
