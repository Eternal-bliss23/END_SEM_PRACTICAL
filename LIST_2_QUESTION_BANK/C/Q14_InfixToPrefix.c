/* Q14 - Infix to Prefix - Reverse, swap brackets, postfix, then reverse. */
/* Use single-character operands, e.g. (A+B)*C. Supports + - * / and ( ). */
#include <stdio.h>
#include <string.h>

#define MAX 100

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void reverse(char s[], int n)
{
    int i, j;
    char t;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        t = s[i]; s[i] = s[j]; s[j] = t;
    }
}

void toPostfix(char in[], char out[])
{
    char stack[MAX], ch;
    int top = -1, k = 0, i, len = (int)strlen(in);

    for (i = 0; i < len; i++) {
        ch = in[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z')) {
            out[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') out[k++] = stack[top--];
            top--;   /* discard '(' */
        } else {
            while (top >= 0 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
                out[k++] = stack[top--];
            stack[++top] = ch;
        }
    }
    while (top >= 0) out[k++] = stack[top--];
    out[k] = '\0';
}

int main(void)
{
    char expr[MAX], rev[MAX], post[MAX];
    int len, i;

    printf("Enter infix expression: ");
    if (scanf("%99s", expr) != 1) return 1;

    len = (int)strlen(expr);
    strcpy(rev, expr);
    reverse(rev, len);
    for (i = 0; i < len; i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    toPostfix(rev, post);
    reverse(post, (int)strlen(post));
    printf("Prefix expression: %s\n", post);
    return 0;
}
