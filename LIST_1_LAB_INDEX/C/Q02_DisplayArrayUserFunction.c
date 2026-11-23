/* Q02: Display Array Using a User-Defined Function
   Purpose: Print array elements with the function display(int a[], int n). */

#include <stdio.h>

#define MAX_N 100

void display(int a[], int n)
{
    int i;
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);
}

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

    display(a, n);
    return 0;
}
