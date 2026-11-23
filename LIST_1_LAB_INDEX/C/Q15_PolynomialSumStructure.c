/* Q15: Polynomial Sum Using a Structure
   Purpose: Add two polynomials stored in struct Poly coefficient arrays. */

#include <stdio.h>

#define MAX_DEG 20

struct Poly
{
    int coeff[20];
    int deg;
};

int main(void)
{
    struct Poly p = {0}, q = {0}, r = {0};
    int i, first;

    printf("Enter degree of first polynomial: ");
    if (scanf("%d", &p.deg) != 1)
        return 1;
    printf("Enter degree of second polynomial: ");
    if (scanf("%d", &q.deg) != 1)
        return 1;
    if (p.deg < 0 || p.deg > MAX_DEG || q.deg < 0 || q.deg > MAX_DEG)
    {
        printf("Degree must be between 0 and %d.\n", MAX_DEG);
        return 1;
    }

    printf("\nFirst polynomial:\n");
    for (i = p.deg; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        if (scanf("%d", &p.coeff[i]) != 1)
            return 1;
    }
    printf("\nSecond polynomial:\n");
    for (i = q.deg; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        if (scanf("%d", &q.coeff[i]) != 1)
            return 1;
    }

    r.deg = (p.deg > q.deg) ? p.deg : q.deg;
    for (i = 0; i <= r.deg; i++)
        r.coeff[i] = p.coeff[i] + q.coeff[i];

    printf("\nSum polynomial:\n");
    first = 1;
    for (i = r.deg; i >= 0; i--)
    {
        if (r.coeff[i] == 0)
            continue;
        if (!first)
            printf(" + ");
        if (i == 0)
            printf("%d", r.coeff[i]);
        else
            printf("%dx^%d", r.coeff[i], i);
        first = 0;
    }
    if (first)
        printf("0");
    printf("\n");

    return 0;
}
