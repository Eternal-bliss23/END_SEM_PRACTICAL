/* Q01 - Merge Two Arrays - Copy both arrays into a third array and print it. */
/* Method: read two arrays, copy a then b into c, and print the result.       */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX], c[2 * MAX];
    int n1, n2, i, k = 0;   /* k is the next free index in c */

    /* Step 1: read the first array */
    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0 || n1 > MAX) return 1;
    printf("Enter %d elements of first array: ", n1);
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    /* Step 2: read the second array */
    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0 || n2 > MAX) return 1;
    printf("Enter %d elements of second array: ", n2);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    /* Step 3: copy all elements of a, then all elements of b, into c */
    for (i = 0; i < n1; i++) c[k++] = a[i];
    for (i = 0; i < n2; i++) c[k++] = b[i];

    /* Step 4: display the merged array */
    printf("Merged array: ");
    for (i = 0; i < k; i++) printf("%d ", c[i]);
    printf("\n");
    return 0;
}
