/* Q05 - Matrix Multiplication - Multiply A(r1 x c1) by B(c1 x c2). */
/* The product has size r1 x c2; columns of A must equal rows of B. */
#include <stdio.h>

#define MAX 10

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2, i, j, k;

    /* Step 1: read the sizes and check that multiplication is possible */
    printf("Enter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) return 1;
    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) return 1;
    if (c1 != r2) {
        printf("Multiplication not possible: c1 must equal r2\n");
        return 1;
    }

    /* Step 2: read both matrices */
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++) scanf("%d", &a[i][j]);
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++) scanf("%d", &b[i][j]);

    /* Step 3: res[i][j] = sum of a[i][k] * b[k][j] */
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;   /* start with a clean sum */
            for (k = 0; k < c1; k++) res[i][j] += a[i][k] * b[k][j];
        }

    /* Step 4: print the product matrix */
    printf("Product matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) printf("%6d", res[i][j]);
        printf("\n");
    }
    return 0;
}
