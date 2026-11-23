/* Q10: 2D Array Using Static Array of Pointers
   Purpose: Use int *p[3] and allocate each of the 3 rows with malloc. */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3

int main(void)
{
    int *p[ROWS];
    int cols, i, j, k;

    printf("Enter number of columns: ");
    if (scanf("%d", &cols) != 1)
        return 1;
    if (cols < 1)
    {
        printf("Columns must be positive.\n");
        return 1;
    }

    /* p is a fixed array of 3 pointers; each pointer gets one row. */
    for (i = 0; i < ROWS; i++)
    {
        p[i] = malloc(cols * sizeof(int));
        if (p[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            for (j = 0; j < i; j++)
                free(p[j]);
            return 1;
        }
    }

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < cols; j++)
        {
            printf("Enter p[%d][%d]: ", i, j);
            if (scanf("%d", &p[i][j]) != 1)
            {
                for (k = 0; k < ROWS; k++)
                    free(p[k]);
                return 1;
            }
        }

    printf("\nMatrix:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%5d", p[i][j]);
        printf("\n");
    }

    for (i = 0; i < ROWS; i++)
        free(p[i]);

    return 0;
}
