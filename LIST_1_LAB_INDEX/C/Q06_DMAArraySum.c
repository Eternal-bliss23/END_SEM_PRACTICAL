/* Q06: Dynamic Array Sum
   Purpose: Allocate an array with malloc, read values, and print their sum. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a, n, i, sum = 0;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1)
    {
        printf("n must be positive.\n");
        return 1;
    }

    /* malloc reserves memory for n integers while the program runs. */
    a = malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d]: ", i);
        if (scanf("%d", &a[i]) != 1)
        {
            free(a);
            return 1;
        }
        sum += a[i];
    }

    printf("Sum of array elements = %d\n", sum);

    /* free returns the memory to the system. */
    free(a);
    return 0;
}
