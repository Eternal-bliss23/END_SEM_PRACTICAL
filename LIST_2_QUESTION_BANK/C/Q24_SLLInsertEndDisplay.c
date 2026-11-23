/* Q24 - SLL Insert at End - Build a list by appending every value. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *head = NULL, *tail = NULL;

void insertEnd(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = NULL;
    if (head == NULL) head = n;
    else tail->next = n;
    tail = n;
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
        insertEnd(value);
    }
    display();
    return 0;
}
