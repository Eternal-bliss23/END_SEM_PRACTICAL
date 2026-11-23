/* Q13: Nested Structures
   Purpose: Store a date inside a student record and print its members. */

#include <stdio.h>

struct Date
{
    int d, m, y;
};

struct Student
{
    char name[30];
    struct Date dob;
};

int main(void)
{
    struct Student s;

    printf("Enter student name: ");
    if (scanf("%29s", s.name) != 1)
        return 1;
    printf("Enter day of birth: ");
    if (scanf("%d", &s.dob.d) != 1)
        return 1;
    printf("Enter month of birth: ");
    if (scanf("%d", &s.dob.m) != 1)
        return 1;
    printf("Enter year of birth: ");
    if (scanf("%d", &s.dob.y) != 1)
        return 1;

    printf("\nStudent record\n");
    printf("Name : %s\n", s.name);
    printf("DOB  : %d/%d/%d\n", s.dob.d, s.dob.m, s.dob.y);

    return 0;
}
