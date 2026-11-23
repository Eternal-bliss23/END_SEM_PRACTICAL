/* Q19 - Circular Queue using Linked List - Enqueue, dequeue, display. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *rear = NULL;   /* rear->next is the front node */

void enqueue(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    if (rear == NULL) {
        n->next = n;            /* single node points to itself */
    } else {
        n->next = rear->next;
        rear->next = n;
    }
    rear = n;
}

void dequeue(void)
{
    struct node *front;
    if (rear == NULL) { printf("Queue is empty\n"); return; }
    front = rear->next;
    printf("Dequeued: %d\n", front->data);
    if (front == rear) {
        rear = NULL;            /* last node removed */
    } else {
        rear->next = front->next;
    }
    free(front);
}

void display(void)
{
    struct node *cur;
    if (rear == NULL) { printf("Queue is empty\n"); return; }
    printf("Queue (front to rear): ");
    cur = rear->next;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != rear->next);
    printf("\n");
}

int main(void)
{
    int choice, value;

    for (;;) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
