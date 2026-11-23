#include <stdio.h>

#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int value)
{
    if (rear == MAX - 1)
    {
        printf("Deque is full. Cannot insert %d at front.\n", value);
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        front--;
    deque[front] = value;
    printf("Inserted %d at front.\n", value);
}

void insertRear(int value)
{
    if (rear == MAX - 1)
    {
        printf("Deque is full. Cannot insert %d at rear.\n", value);
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear++;
    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(void)
{
    if (front == -1)
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front++]);
    if (front > rear)
        front = rear = -1;
}

void deleteRear(void)
{
    if (front == -1)
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear--]);
    if (front > rear)
        front = rear = -1;
}

void display(void)
{
    int i;
    if (front == -1)
    {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- Deque using Linear Array ---\n");
        printf("1. Insert front\n2. Insert rear\n3. Delete front\n");
        printf("4. Delete rear\n5. Display\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
        case 2:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 0;
            if (choice == 1)
                insertFront(value);
            else
                insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
