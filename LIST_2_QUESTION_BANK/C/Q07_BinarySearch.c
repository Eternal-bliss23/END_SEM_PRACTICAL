/* Q07 - Binary Search - Iterative search on a sorted array. */
/* The array must already be sorted in ascending order.      */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, key, low, high, mid, pos = -1;

    /* Step 1: read the sorted array */
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    /* Step 2: read the key to search for */
    printf("Enter key to search: ");
    scanf("%d", &key);

    /* Step 3: repeatedly cut the search range in half */
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;   /* middle index */
        if (a[mid] == key) {
            pos = mid + 1;   /* 1-based position */
            break;
        } else if (a[mid] < key) {
            low = mid + 1;   /* search the right half */
        } else {
            high = mid - 1;  /* search the left half */
        }
    }

    /* Step 4: print the result */
    if (pos == -1)
        printf("Element %d not found\n", key);
    else
        printf("Element %d found at position %d\n", key, pos);
    return 0;
}
