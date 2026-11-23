/* Q28 - Doubly Linked List - Insert/delete and display both directions. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *prev, *next; };
struct node *head = NULL;

void insertBegin(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->prev = NULL;
    n->next = head;
    if (head != NULL) head->prev = n;
    head = n;
}

void insertEnd(int value)
{
    struct node *n = malloc(sizeof *n);
    struct node *cur;
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = NULL;
    if (head == NULL) { n->prev = NULL; head = n; return; }
    for (cur = head; cur->next != NULL; cur = cur->next) ;
    cur->next = n;
    n->prev = cur;
}

void insertAtPosition(int value, int pos)
{
    struct node *cur = head, *n;
    int i;
    if (pos <= 1) { insertBegin(value); return; }
    for (i = 1; cur != NULL && i < pos - 1; i++) cur = cur->next;
    if (cur == NULL) { printf("Invalid position\n"); return; }
    n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = cur->next;
    n->prev = cur;
    if (cur->next != NULL) cur->next->prev = n;
    cur->next = n;
}

void deleteFirst(void)
{
    struct node *temp;
    if (head == NULL) { printf("List is empty\n"); return; }
    temp = head;
    printf("Deleted: %d\n", temp->data);
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void deleteLast(void)
{
    struct node *cur;
    if (head == NULL) { printf("List is empty\n"); return; }
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    for (cur = head; cur->next != NULL; cur = cur->next) ;
    printf("Deleted: %d\n", cur->data);
    cur->prev->next = NULL;
    free(cur);
}

void displayForward(void)
{
    struct node *cur;
    printf("Forward: ");
    for (cur = head; cur != NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

void displayBackward(void)
{
    struct node *cur = head;
    if (cur == NULL) { printf("List is empty\n"); return; }
    while (cur->next != NULL) cur = cur->next;
    printf("Backward: ");
    for (; cur != NULL; cur = cur->prev) printf("%d ", cur->data);
    printf("\n");
}

int main(void)
{
    int choice, value, pos;

    for (;;) {
        printf("\n1. Insert begin  2. Insert end  3. Insert at position\n");
        printf("4. Delete first  5. Delete last  6. Display forward\n");
        printf("7. Display backward  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertBegin(value); break;
            case 2: printf("Enter value: "); scanf("%d", &value); insertEnd(value); break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: displayForward(); break;
            case 7: displayBackward(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
