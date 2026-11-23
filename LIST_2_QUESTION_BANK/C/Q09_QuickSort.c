/* Q09 - Quick Sort - Recursive quicksort using a partition function. */
#include <stdio.h>

#define MAX 100

int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    temp = a[i + 1]; a[i + 1] = a[high]; a[high] = temp;
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;
    if (low >= high) return;
    p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main(void)
{
    int a[MAX], n, i;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
