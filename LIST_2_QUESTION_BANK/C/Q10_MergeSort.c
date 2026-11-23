/* Q10 - Merge Sort - Recursive mergesort using a merge function. */
#include <stdio.h>

#define MAX 100

void merge(int a[], int left, int mid, int right, int temp[])
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; i++) a[i] = temp[i];
}

void mergeSort(int a[], int left, int right, int temp[])
{
    int mid;
    if (left >= right) return;
    mid = (left + right) / 2;
    mergeSort(a, left, mid, temp);
    mergeSort(a, mid + 1, right, temp);
    merge(a, left, mid, right, temp);
}

int main(void)
{
    int a[MAX], temp[MAX], n, i;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1, temp);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
