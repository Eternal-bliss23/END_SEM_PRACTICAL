#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

static struct Node *top = NULL;

void push(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    node->data = value;
    node->next = top;
    top = node;
    printf("Pushed %d.\n", value);
}

void pop(void)
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    temp = top;
    printf("Popped %d.\n", temp->data);
    top = top->next;
    free(temp);
}

void peek(void)
{
    if (top == NULL)
    {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element is %d.\n", top->data);
}

void display(void)
{
    struct Node *current = top;
    if (current == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    int choice, value;
    for (;;)
    {
        printf("\n--- Stack using Linked List ---\n");
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
            while (top != NULL)
                pop();
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
