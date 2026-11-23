# Q13: Nested Structures
# Purpose: A Student contains a Date object; read and print the nested members.


class Date:
    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year = year


class Student:
    def __init__(self, roll, name, dob):
        self.roll = roll
        self.name = name
        self.dob = dob


def main():
    roll = int(input("Enter roll number: "))
    name = input("Enter name: ")
    day = int(input("Enter birth day: "))
    month = int(input("Enter birth month: "))
    year = int(input("Enter birth year: "))

    student = Student(roll, name, Date(day, month, year))

    print("\nStudent details:")
    print("Roll:", student.roll)
    print("Name:", student.name)
    dob = student.dob
    print("Date of birth:", f"{dob.day}/{dob.month}/{dob.year}")


if __name__ == "__main__":
    main()
