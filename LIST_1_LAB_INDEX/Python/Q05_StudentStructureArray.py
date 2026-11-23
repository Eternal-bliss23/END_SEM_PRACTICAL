# Q05: Array of Student Structures
# Purpose: Store n students (roll, name, marks) and print them as a table.


class Student:
    def __init__(self, roll, name, marks):
        self.roll = roll
        self.name = name
        self.marks = marks


def main():
    n = int(input("Enter number of students: "))
    students = []
    for i in range(n):
        print(f"\nStudent {i + 1}:")
        roll = int(input("  Roll no: "))
        name = input("  Name: ")
        marks = float(input("  Marks: "))
        students.append(Student(roll, name, marks))

    print("\nRoll\tName\tMarks")
    print("-" * 30)
    for s in students:
        print(f"{s.roll}\t{s.name}\t{s.marks}")


if __name__ == "__main__":
    main()
