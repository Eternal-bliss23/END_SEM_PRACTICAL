/* Q14: Polynomial Sum Using Coefficient Arrays
   Purpose: Add two polynomials stored as arrays indexed by power. */

#include <stdio.h>

#define MAX_DEG 20

int main(void)
{
    int a[MAX_DEG + 1] = {0}, b[MAX_DEG + 1] = {0};
    int da, db, maxDeg, i, first;

    printf("Enter degree of first polynomial: ");
    if (scanf("%d", &da) != 1)
        return 1;
    printf("Enter degree of second polynomial: ");
    if (scanf("%d", &db) != 1)
        return 1;
    if (da < 0 || da > MAX_DEG || db < 0 || db > MAX_DEG)
    {
        printf("Degree must be between 0 and %d.\n", MAX_DEG);
        return 1;
    }

    for (i = da; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d for first: ", i);
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }
    for (i = db; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d for second: ", i);
        if (scanf("%d", &b[i]) != 1)
            return 1;
    }

    maxDeg = (da > db) ? da : db;
    printf("\nResult polynomial:\n");
    first = 1;
    for (i = maxDeg; i >= 0; i--)
    {
        int sum = a[i] + b[i];
        if (sum == 0)
            continue;
        if (!first)
            printf(" + ");
        if (i == 0)
            printf("%d", sum);
        else
            printf("%dx^%d", sum, i);
        first = 0;
    }
    if (first)
        printf("0");
    printf("\n");

    return 0;
}
