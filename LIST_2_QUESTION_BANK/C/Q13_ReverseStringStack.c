/* Q13 - Reverse a String using Stack - Push characters, then pop them. */
/* Last character pushed is the first one printed: that reverses text.  */
#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1) printf("Stack overflow\n");
    else stack[++top] = ch;
}

char pop(void)
{
    if (top < 0) return '\0';
    return stack[top--];
}

int main(void)
{
    char str[MAX];
    int i;

    /* Step 1: read a word (no spaces) */
    printf("Enter a string: ");
    if (scanf("%99s", str) != 1) return 1;

    /* Step 2: push every character onto the stack */
    for (i = 0; str[i] != '\0'; i++) push(str[i]);

    /* Step 3: pop the stack to get the characters in reverse order */
    printf("Reversed string: ");
    while (top >= 0) putchar(pop());
    printf("\n");
    return 0;
}
