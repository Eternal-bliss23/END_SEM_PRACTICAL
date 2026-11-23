/* Q03 - Delete from Position - Shift elements left after deleting a value. */
/* The position entered by the user is 1-based (first element is 1).        */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, pos, i;

    /* Step 1: read the array */
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    /* Step 2: read the 1-based position to delete */
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    /* Step 3: shift elements after the deleted position to the left */
    for (i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];

    /* Step 4: reduce the size and print the changed array */
    n--;
    printf("Array after deletion: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
