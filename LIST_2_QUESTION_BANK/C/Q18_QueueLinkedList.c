/* Q18 - Queue using Linked List - Menu driven enqueue, dequeue, peek, display. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *front = NULL, *rear = NULL;

void enqueue(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = NULL;
    if (rear == NULL) front = rear = n;
    else { rear->next = n; rear = n; }
}

void dequeue(void)
{
    struct node *temp;
    if (front == NULL) { printf("Queue is empty\n"); return; }
    temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void peek(void)
{
    if (front == NULL) printf("Queue is empty\n");
    else printf("Front element: %d\n", front->data);
}

void display(void)
{
    struct node *cur;
    if (front == NULL) { printf("Queue is empty\n"); return; }
    printf("Queue (front to rear): ");
    for (cur = front; cur != NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

int main(void)
{
    int choice, value;

    for (;;) {
        printf("\n1. Enqueue  2. Dequeue  3. Peek  4. Display  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
