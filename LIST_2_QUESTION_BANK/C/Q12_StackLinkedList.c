/* Q12 - Stack using Linked List - Menu driven push, pop, peek and display. */
#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

struct node *top = NULL;

void push(int value)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL) { printf("Memory not available\n"); return; }
    n->data = value;
    n->next = top;
    top = n;
}

void pop(void)
{
    struct node *temp;
    if (top == NULL) { printf("Stack underflow\n"); return; }
    temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek(void)
{
    if (top == NULL) printf("Stack is empty\n");
    else printf("Top element: %d\n", top->data);
}

void display(void)
{
    struct node *cur;
    if (top == NULL) { printf("Stack is empty\n"); return; }
    printf("Stack (top first): ");
    for (cur = top; cur != NULL; cur = cur->next) printf("%d ", cur->data);
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
