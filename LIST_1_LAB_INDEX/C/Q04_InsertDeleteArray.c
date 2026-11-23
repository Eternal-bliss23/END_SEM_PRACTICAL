/* Q04: Insert and Delete in an Array
   Purpose: Use a menu to insert/delete by shifting array elements. */

#include <stdio.h>

#define MAX 50

void display(int a[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void insert(int a[], int *n, int pos, int value)
{
    int i;
    if (*n >= MAX)
    {
        printf("Array is full.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position.\n");
        return;
    }
    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];
    a[pos - 1] = value;
    (*n)++;
    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteAt(int a[], int *n, int pos)
{
    int i;
    if (pos < 1 || pos > *n)
    {
        printf("Invalid position.\n");
        return;
    }
    printf("Deleted %d from position %d.\n", a[pos - 1], pos);
    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

int main(void)
{
    int a[MAX], n = 0, choice, pos, value;

    for (;;)
    {
        printf("\n1. Insert  2. Delete  3. Display  0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            printf("Enter position (1 to %d): ", n + 1);
            if (scanf("%d", &pos) != 1)
                return 0;
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 0;
            insert(a, &n, pos, value);
            break;
        case 2:
            printf("Enter position (1 to %d): ", n);
            if (scanf("%d", &pos) != 1)
                return 0;
            deleteAt(a, &n, pos);
            break;
        case 3:
            display(a, n);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
