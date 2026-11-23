/* Q11 - Stack using Array - Menu driven push, pop, peek and display. */
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1) printf("Stack overflow\n");
    else stack[++top] = value;
}

void pop(void)
{
    if (top < 0) printf("Stack underflow\n");
    else printf("Popped: %d\n", stack[top--]);
}

void peek(void)
{
    if (top < 0) printf("Stack is empty\n");
    else printf("Top element: %d\n", stack[top]);
}

void display(void)
{
    int i;
    if (top < 0) { printf("Stack is empty\n"); return; }
    printf("Stack (top first): ");
    for (i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;

    for (;;) {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
