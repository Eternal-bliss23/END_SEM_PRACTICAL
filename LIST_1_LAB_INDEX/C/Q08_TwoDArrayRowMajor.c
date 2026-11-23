/* Q08: Two-Dimensional Array in Row-Major Order
   Purpose: Store a matrix in a 1D array using index i * cols + j. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a, rows, cols, i, j;

    printf("Enter rows: ");
    if (scanf("%d", &rows) != 1)
        return 1;
    printf("Enter columns: ");
    if (scanf("%d", &cols) != 1)
        return 1;
    if (rows < 1 || cols < 1)
    {
        printf("Rows and columns must be positive.\n");
        return 1;
    }

    a = malloc(rows * cols * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            if (scanf("%d", &a[i * cols + j]) != 1)
            {
                free(a);
                return 1;
            }
        }

    printf("\nMatrix (row-major 1D array):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%5d", a[i * cols + j]);
        printf("\n");
    }

    free(a);
    return 0;
}
