/* Q26 - SLL Insert End and Delete End - Menu driven list operations. */
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

void deleteEnd(void)
{
    struct node *cur;
    if (head == NULL) { printf("List is empty\n"); return; }
    printf("Deleted: %d\n", tail->data);
    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }
    cur = head;
    while (cur->next != tail) cur = cur->next;
    cur->next = NULL;
    free(tail);
    tail = cur;
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
    int choice, value;

    for (;;) {
        printf("\n1. Insert at end  2. Delete last  3. Display  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertEnd(value); break;
            case 2: deleteEnd(); break;
            case 3: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
