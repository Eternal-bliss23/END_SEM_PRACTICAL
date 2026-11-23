/* Q20 - Deque using Circular Array - Insert/delete at front and rear. */
#include <stdio.h>

#define MAX 10

int deque[MAX], front = 0, rear = 0;   /* rear = next free position */

int isFull(void) { return (rear + 1) % MAX == front; }
int isEmpty(void) { return front == rear; }

void insertFront(int value)
{
    if (isFull()) { printf("Deque is full\n"); return; }
    front = (front - 1 + MAX) % MAX;
    deque[front] = value;
}

void insertRear(int value)
{
    if (isFull()) { printf("Deque is full\n"); return; }
    deque[rear] = value;
    rear = (rear + 1) % MAX;
}

void deleteFront(void)
{
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deleted from front: %d\n", deque[front]);
    front = (front + 1) % MAX;
}

void deleteRear(void)
{
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    rear = (rear - 1 + MAX) % MAX;
    printf("Deleted from rear: %d\n", deque[rear]);
}

void display(void)
{
    int i;
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deque (front to rear): ");
    for (i = front; i != rear; i = (i + 1) % MAX) printf("%d ", deque[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;

    for (;;) {
        printf("\n1. Insert front  2. Insert rear  3. Delete front\n");
        printf("4. Delete rear   5. Display      0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertFront(value); break;
            case 2: printf("Enter value: "); scanf("%d", &value); insertRear(value); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
