/* Q08 - Bubble Sort - Repeatedly swap neighbouring out-of-order elements. */
/* After each pass, the largest remaining value settles at the end.       */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, temp, swapped;

    /* Step 1: read the array */
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    /* Step 2: perform at most n-1 passes */
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;   /* already sorted */
    }

    /* Step 3: print the sorted array */
    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
