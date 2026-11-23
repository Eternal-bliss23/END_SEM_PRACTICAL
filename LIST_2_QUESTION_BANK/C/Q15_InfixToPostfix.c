/* Q15 - Infix to Postfix - Operator precedence stack conversion. */
/* Use single-character operands, e.g. A+B*C. Supports + - * / and ( ). */
#include <stdio.h>
#include <string.h>

#define MAX 100

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main(void)
{
    char expr[MAX], post[MAX], stack[MAX], ch;
    int top = -1, k = 0, i, len;

    printf("Enter infix expression: ");
    if (scanf("%99s", expr) != 1) return 1;
    len = (int)strlen(expr);

    for (i = 0; i < len; i++) {
        ch = expr[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z')) {
            post[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') post[k++] = stack[top--];
            top--;   /* discard '(' */
        } else {
            while (top >= 0 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
                post[k++] = stack[top--];
            stack[++top] = ch;
        }
    }
    while (top >= 0) post[k++] = stack[top--];
    post[k] = '\0';

    printf("Postfix expression: %s\n", post);
    return 0;
}
