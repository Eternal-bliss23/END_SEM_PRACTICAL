#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Enqueued %d.\n", value);
}

void dequeue(void)
{
    if (front == -1)
    {
        printf("Circular queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued %d.\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek(void)
{
    if (front == -1)
    {
        printf("Circular queue is empty. No front element.\n");
        return;
    }
    printf("Front element is %d.\n", queue[front]);
}

void display(void)
{
    int i = front;
    if (front == -1)
    {
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Circular queue (front to rear): ");
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- Circular Queue ---\n");
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
