/* Q23 - SLL Insert at Beginning - Build a list by inserting every value first. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *head = NULL;

void insertBegin(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = head;
    head = n;
}

void display(void)
{
    struct node *cur;
    if (head == NULL) { printf("List is empty\n"); return; }
    printf("List: ");
    for (cur = head; cur != NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

int main(void)
{
    int n, value, i;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;
    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertBegin(value);
    }
    display();
    return 0;
}
