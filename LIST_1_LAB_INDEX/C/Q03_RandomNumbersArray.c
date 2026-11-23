/* Q03: Random Numbers in an Array
   Purpose: Fill an array with random numbers (0 to 99) using rand(). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100

int main(void)
{
    int a[MAX_N];
    int n, i;

    srand(time(NULL));

    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1 || n > MAX_N)
    {
        printf("n must be between 1 and %d.\n", MAX_N);
        return 1;
    }

    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("\nRandom array elements:\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}
