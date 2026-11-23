/* Q09: Dynamic Memory Allocation - 1D Array
   Purpose: Create a 1D int array with malloc, display it, then free it. */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a, n, i;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1)
    {
        printf("n must be positive.\n");
        return 1;
    }

    /* malloc asks the system for n integers of memory.
       It returns the address of the first element (or NULL on failure). */
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
    }

    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    /* free gives the allocated memory back; do not use a after this. */
    free(a);
    printf("Memory freed.\n");

    return 0;
}
