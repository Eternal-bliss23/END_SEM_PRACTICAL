/* Q11: 2D Array Using Double Pointer
   Purpose: Allocate int **p row by row, read a matrix, print it, and free. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **p, rows, cols, i, j;

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

    /* First allocate the array of row pointers. */
    p = malloc(rows * sizeof(int *));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Then allocate memory for each row. */
    for (i = 0; i < rows; i++)
    {
        p[i] = malloc(cols * sizeof(int));
        if (p[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            for (j = 0; j < i; j++)
                free(p[j]);
            free(p);
            return 1;
        }
    }

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
        {
            printf("Enter p[%d][%d]: ", i, j);
            if (scanf("%d", &p[i][j]) != 1)
            {
                for (j = 0; j < rows; j++)
                    free(p[j]);
                free(p);
                return 1;
            }
        }

    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%5d", p[i][j]);
        printf("\n");
    }

    for (i = 0; i < rows; i++)
        free(p[i]);
    free(p);

    return 0;
}
