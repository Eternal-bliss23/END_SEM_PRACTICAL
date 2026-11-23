#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d.\n", value);
}

void pop(void)
{
    if (top < 0)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    printf("Popped %d.\n", stack[top--]);
}

void peek(void)
{
    if (top < 0)
    {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element is %d.\n", stack[top]);
}

void display(void)
{
    int i;
    if (top < 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- Stack using Array ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 0;
            push(value);
            break;
        case 2:
            pop();
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
