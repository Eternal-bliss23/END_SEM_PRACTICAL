/* Q01: Display N Array Elements
   Purpose: Read n integers into an array and print them in order. */

#include <stdio.h>

#define MAX_N 100

int main(void)
{
    int a[MAX_N];
    int n, i;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1 || n > MAX_N)
    {
        printf("n must be between 1 and %d.\n", MAX_N);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d]: ", i);
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}
