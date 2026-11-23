/* Q21 - Queue using Array - Menu driven enqueue, dequeue, peek, display. */
#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1) { printf("Queue overflow\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

void dequeue(void)
{
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        front = rear = -1;
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
}

void peek(void)
{
    if (front == -1 || front > rear) printf("Queue is empty\n");
    else printf("Front element: %d\n", queue[front]);
}

void display(void)
{
    int i;
    if (front == -1 || front > rear) { printf("Queue is empty\n"); return; }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++) printf("%d ", queue[i]);
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
