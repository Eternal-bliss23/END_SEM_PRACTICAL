/* Q25 - SLL Insert at Position - Insert at a 1-based position, then display. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *head = NULL;

void insertAtPosition(int value, int pos)
{
    struct node *n = malloc(sizeof *n);
    struct node *cur = head;
    int i;

    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    if (pos == 1 || head == NULL) {
        n->next = head;
        head = n;
        return;
    }
    for (i = 1; cur != NULL && i < pos - 1; i++) cur = cur->next;
    if (cur == NULL) { printf("Invalid position\n"); free(n); return; }
    n->next = cur->next;
    cur->next = n;
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
    int choice, value, pos;

    for (;;) {
        printf("\n1. Insert at position  2. Display  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value);
                printf("Enter position: "); scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 2: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
