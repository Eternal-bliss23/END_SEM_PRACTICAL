/* Q18: Sparse Matrix Using Triplets
   Purpose: Store non-zero terms as (row, col, value) and display triplet/dense form. */

#include <stdio.h>

#define MAX_TERMS 50

struct Term
{
    int row, col, value;
};

void denseDisplay(struct Term t[], int n, int rows, int cols)
{
    int i, j, k, value;
    printf("\nDense matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            value = 0;
            for (k = 0; k < n; k++)
                if (t[k].row == i && t[k].col == j)
                    value = t[k].value;
            printf("%5d", value);
        }
        printf("\n");
    }
}

int main(void)
{
    struct Term t[MAX_TERMS];
    int rows, cols, n, i, choice;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1)
        return 1;
    printf("Enter number of columns: ");
    if (scanf("%d", &cols) != 1)
        return 1;
    printf("Enter number of non-zero terms: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (rows < 1 || cols < 1 || n < 1 || n > MAX_TERMS)
    {
        printf("Invalid size or number of terms.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Term %d (row col value): ", i + 1);
        if (scanf("%d %d %d", &t[i].row, &t[i].col, &t[i].value) != 3)
            return 1;
        if (t[i].row < 0 || t[i].row >= rows || t[i].col < 0 || t[i].col >= cols)
        {
            printf("Row or column out of range.\n");
            return 1;
        }
    }

    for (;;)
    {
        printf("\n1. Display triplet table  2. Display dense matrix  0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            printf("\n%-6s %-6s %-6s\n", "Row", "Col", "Value");
            for (i = 0; i < n; i++)
                printf("%-6d %-6d %-6d\n", t[i].row, t[i].col, t[i].value);
            break;
        case 2:
            denseDisplay(t, n, rows, cols);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
