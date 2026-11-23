/* Q16: Polynomial Sum Using an Array of Structures
   Purpose: Add two polynomials stored as arrays of (coefficient, exponent) terms. */

#include <stdio.h>

#define MAX_TERMS 20

struct Term
{
    int coeff, exp;
};

int main(void)
{
    struct Term a[MAX_TERMS], b[MAX_TERMS], result[MAX_TERMS];
    int na, nb, nr = 0, i, j, found;

    printf("Enter number of terms in first polynomial: ");
    if (scanf("%d", &na) != 1)
        return 1;
    printf("Enter number of terms in second polynomial: ");
    if (scanf("%d", &nb) != 1)
        return 1;
    if (na < 1 || na > MAX_TERMS || nb < 1 || nb > MAX_TERMS)
    {
        printf("Number of terms must be between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    printf("\nFirst polynomial (coefficient exponent):\n");
    for (i = 0; i < na; i++)
    {
        printf("Term %d: ", i + 1);
        if (scanf("%d %d", &a[i].coeff, &a[i].exp) != 2)
            return 1;
    }
    printf("\nSecond polynomial (coefficient exponent):\n");
    for (i = 0; i < nb; i++)
    {
        printf("Term %d: ", i + 1);
        if (scanf("%d %d", &b[i].coeff, &b[i].exp) != 2)
            return 1;
    }

    /* Copy first polynomial into the result. */
    for (i = 0; i < na; i++)
    {
        result[nr] = a[i];
        nr++;
    }
    /* Add terms of the second polynomial to matching exponents. */
    for (i = 0; i < nb; i++)
    {
        found = 0;
        for (j = 0; j < nr; j++)
            if (result[j].exp == b[i].exp)
            {
                result[j].coeff += b[i].coeff;
                found = 1;
                break;
            }
        if (!found)
        {
            result[nr] = b[i];
            nr++;
        }
    }

    printf("\nResult terms (coefficient x^exponent):\n");
    for (i = 0; i < nr; i++)
        printf("%d x^%d\n", result[i].coeff, result[i].exp);

    return 0;
}
