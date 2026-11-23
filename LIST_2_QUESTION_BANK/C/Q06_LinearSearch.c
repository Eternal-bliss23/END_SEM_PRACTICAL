/* Q06 - Linear Search - Find a key by checking every element in order. */
/* The result printed is a 1-based position, or "not found".            */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, key, i, pos = -1;   /* -1 means the key was not found */

    /* Step 1: read the array */
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    /* Step 2: read the key to search for */
    printf("Enter key to search: ");
    scanf("%d", &key);

    /* Step 3: compare the key with every element from left to right */
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            pos = i + 1;   /* store 1-based position */
            break;         /* stop at the first match */
        }
    }

    /* Step 4: print the result */
    if (pos == -1)
        printf("Element %d not found\n", key);
    else
        printf("Element %d found at position %d\n", key, pos);
    return 0;
}
