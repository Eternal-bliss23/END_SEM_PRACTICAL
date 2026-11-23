/* Q02 - Insert at Position - Shift elements right and insert a value. */
/* The position entered by the user is 1-based (first element is 1).   */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, pos, value, i;

    /* Step 1: read the array */
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0 || n >= MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    /* Step 2: read the new value and its 1-based position */
    printf("Enter new value: ");
    scanf("%d", &value);
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 1;
    }

    /* Step 3: shift elements from the end towards the right */
    for (i = n; i >= pos; i--) a[i] = a[i - 1];

    /* Step 4: put the new value in the empty slot */
    a[pos - 1] = value;
    n++;

    /* Step 5: display the changed array */
    printf("Array after insertion: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
