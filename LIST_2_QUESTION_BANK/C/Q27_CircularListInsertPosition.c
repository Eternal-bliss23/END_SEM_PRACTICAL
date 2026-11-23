/* Q27 - Circular List Insert at Position - Insert and display in a circle. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *head = NULL;   /* last node's next points back to head */

void insertAtPosition(int value, int pos)
{
    struct node *n = malloc(sizeof *n);
    struct node *cur;
    int i;

    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }
    if (pos <= 1) {
        cur = head;
        while (cur->next != head) cur = cur->next;
        n->next = head;
        cur->next = n;
        head = n;
        return;
    }
    cur = head;
    for (i = 1; cur->next != head && i < pos - 1; i++) cur = cur->next;
    n->next = cur->next;
    cur->next = n;
}

void display(void)
{
    struct node *cur;
    if (head == NULL) { printf("List is empty\n"); return; }
    printf("Circular list: ");
    cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
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
