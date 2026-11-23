/* Q16 - Evaluate Prefix - Scan space-separated prefix tokens right to left. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char line[MAX], *tok[MAX], *t;
    int stack[MAX], top = 0, count = 0, i, a, b, res;

    printf("Enter prefix expression (e.g. + 3 * 2 4): ");
    if (fgets(line, sizeof line, stdin) == NULL) return 1;
    for (t = strtok(line, " \t\n"); t != NULL; t = strtok(NULL, " \t\n")) {
        if (count < MAX) tok[count++] = t;
    }
    if (count == 0) { printf("No expression entered\n"); return 1; }

    for (i = count - 1; i >= 0; i--) {
        if (isdigit((unsigned char)tok[i][0]) ||
            (tok[i][0] == '-' && isdigit((unsigned char)tok[i][1]))) {
            stack[top++] = atoi(tok[i]);
        } else {
            a = stack[--top];   /* left operand */
            b = stack[--top];   /* right operand */
            switch (tok[i][0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) { printf("Division by zero\n"); return 1; }
                    res = a / b; break;
                default:
                    printf("Unknown operator: %s\n", tok[i]);
                    return 1;
            }
            stack[top++] = res;
        }
    }
    printf("Result: %d\n", stack[0]);
    return 0;
}
