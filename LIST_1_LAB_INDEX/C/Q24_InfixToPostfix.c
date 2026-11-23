#include <stdio.h>

#define MAX 100

char stack[MAX];
char output[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = c;
}

char pop(void)
{
    if (top < 0)
        return '\0';
    return stack[top--];
}

char peek(void)
{
    if (top < 0)
        return '\0';
    return stack[top];
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int isOperand(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}

void infixToPostfix(const char *expr)
{
    int i = 0, j = 0;
    char c;
    top = -1;
    while (expr[i] != '\0' && j < MAX - 1)
    {
        c = expr[i];
        if (isOperand(c))
            output[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (top >= 0 && peek() != '(')
                output[j++] = pop();
            if (top >= 0)
                pop();
            else
                printf("Warning: unmatched ')'.\n");
        }
        else if (isOperator(c))
        {
            while (top >= 0 && peek() != '(' &&
                   (precedence(peek()) > precedence(c) ||
                    (precedence(peek()) == precedence(c) && c != '^')))
                output[j++] = pop();
            push(c);
        }
        i++;
    }
    while (top >= 0 && j < MAX - 1)
    {
        c = pop();
        if (c == '(')
            printf("Warning: unmatched '('.\n");
        else
            output[j++] = c;
    }
    output[j] = '\0';
    printf("Postfix expression: %s\n", output);
}

int main(void)
{
    char expr[MAX];
    int choice;
    for (;;)
    {
        printf("\n--- Infix to Postfix ---\n");
        printf("1. Convert an infix expression\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        if (choice == 0)
            return 0;
        if (choice != 1)
        {
            printf("Invalid choice.\n");
            continue;
        }
        printf("Enter infix expression (no spaces): ");
        if (scanf("%99s", expr) != 1)
            return 0;
        infixToPostfix(expr);
    }
}
