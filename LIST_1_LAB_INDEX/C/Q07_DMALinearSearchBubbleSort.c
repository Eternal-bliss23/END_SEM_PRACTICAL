/* Q07: Dynamic Array - Linear Search and Bubble Sort
   Purpose: Use a malloc array with a menu for search, sort, and display. */

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    printf("Array sorted in ascending order.\n");
}

void display(int a[], int n)
{
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int *a, n, i, choice, key, pos;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1)
    {
        printf("n must be positive.\n");
        return 1;
    }

    a = malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d]: ", i);
        if (scanf("%d", &a[i]) != 1)
        {
            free(a);
            return 1;
        }
    }

    for (;;)
    {
        printf("\n1. Linear search  2. Bubble sort  3. Display  0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        switch (choice)
        {
        case 1:
            printf("Enter value to search: ");
            if (scanf("%d", &key) != 1)
                break;
            pos = linearSearch(a, n, key);
            if (pos == -1)
                printf("%d not found.\n", key);
            else
                printf("%d found at index %d.\n", key, pos);
            break;
        case 2:
            bubbleSort(a, n);
            break;
        case 3:
            display(a, n);
            break;
        case 0:
            free(a);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    free(a);
    return 0;
}
