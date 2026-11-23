#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
    printf("Enqueued %d.\n", value);
}

void dequeue(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        front = rear = -1;
        return;
    }
    printf("Dequeued %d.\n", queue[front++]);
    if (front > rear)
        front = rear = -1;
}

void peek(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty. No front element.\n");
        return;
    }
    printf("Front element is %d.\n", queue[front]);
}

void display(void)
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- Normal Linear Queue ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 0;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
