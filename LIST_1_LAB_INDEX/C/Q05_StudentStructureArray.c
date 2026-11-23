/* Q05: Array of Student Structures
   Purpose: Read student records and display them as a neat table. */

#include <stdio.h>

#define MAX_N 30

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main(void)
{
    struct Student s[MAX_N];
    int n, i;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1 || n > MAX_N)
    {
        printf("Number of students must be between 1 and %d.\n", MAX_N);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Enter roll number: ");
        if (scanf("%d", &s[i].roll) != 1)
            return 1;
        printf("Enter name: ");
        if (scanf("%29s", s[i].name) != 1)
            return 1;
        printf("Enter marks: ");
        if (scanf("%f", &s[i].marks) != 1)
            return 1;
    }

    printf("\n%-8s %-20s %-10s\n", "Roll", "Name", "Marks");
    printf("----------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%-8d %-20s %-10.2f\n", s[i].roll, s[i].name, s[i].marks);

    return 0;
}
