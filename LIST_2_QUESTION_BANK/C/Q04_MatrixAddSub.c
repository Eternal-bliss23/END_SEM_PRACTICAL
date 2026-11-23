/* Q04 - Matrix Addition and Subtraction - Add or subtract two matrices. */
#include <stdio.h>

#define MAX 10

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX];
    int r, c, i, j, choice;

    for (;;) {
        printf("\n1. Add  2. Subtract  0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 0) break;
        if (choice != 1 && choice != 2) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter rows: ");
        if (scanf("%d", &r) != 1 || r < 1 || r > MAX) return 1;
        printf("Enter columns: ");
        if (scanf("%d", &c) != 1 || c < 1 || c > MAX) return 1;

        printf("Enter elements of first matrix:\n");
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++) scanf("%d", &a[i][j]);
        printf("Enter elements of second matrix:\n");
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++) scanf("%d", &b[i][j]);

        printf("Result matrix:\n");
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (choice == 1)
                    printf("%6d", a[i][j] + b[i][j]);
                else
                    printf("%6d", a[i][j] - b[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
