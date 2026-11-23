/* Q22 - Circular Queue using Array - Enqueue, dequeue, peek, display. */
#include <stdio.h>

#define MAX 10

int queue[MAX], front = 0, rear = 0;   /* rear = next free position */

int isFull(void) { return (rear + 1) % MAX == front; }
int isEmpty(void) { return front == rear; }

void enqueue(int value)
{
    if (isFull()) { printf("Queue overflow\n"); return; }
    queue[rear] = value;
    rear = (rear + 1) % MAX;
}

void dequeue(void)
{
    if (isEmpty()) { printf("Queue underflow\n"); return; }
    printf("Dequeued: %d\n", queue[front]);
    front = (front + 1) % MAX;
}

void peek(void)
{
    if (isEmpty()) printf("Queue is empty\n");
    else printf("Front element: %d\n", queue[front]);
}

void display(void)
{
    int i;
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Queue (front to rear): ");
    for (i = front; i != rear; i = (i + 1) % MAX) printf("%d ", queue[i]);
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
