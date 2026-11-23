/* Q29 - Binary Tree Traversal - Build level order, then pre/in/postorder. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node { int data; struct node *left, *right; };

struct node *newNode(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); exit(1); }
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

void preorder(struct node *p)
{
    if (p == NULL) return;
    printf("%d ", p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p)
{
    if (p == NULL) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

void postorder(struct node *p)
{
    if (p == NULL) return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->data);
}

int main(void)
{
    struct node *root = NULL, *q[MAX], *cur, *n;
    int front = 0, rear = 0, count, i, value, choice;

    printf("Enter number of nodes: ");
    if (scanf("%d", &count) != 1 || count < 0 || count > MAX) return 1;
    for (i = 0; i < count; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        n = newNode(value);
        if (root == NULL) {
            root = n;
            q[rear++] = n;
        } else {
            cur = q[front];
            if (cur->left == NULL) cur->left = n;
            else { cur->right = n; front++; }
            q[rear++] = n;
        }
    }

    for (;;) {
        printf("\n1. Preorder  2. Inorder  3. Postorder  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
