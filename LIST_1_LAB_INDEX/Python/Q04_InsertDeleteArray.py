# Q04: Insert and Delete in an Array
# Purpose: Use a list as an array and insert/delete by position with insert/pop.


def display(a):
    if not a:
        print("Array is empty.")
    else:
        print("Array:", a)


def main():
    a = []
    while True:
        print("\n1. Insert  2. Delete  3. Display  0. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            value = int(input("Enter value: "))
            pos = int(input("Enter position (0-based): "))
            if 0 <= pos <= len(a):
                a.insert(pos, value)
                print("Inserted:", value)
            else:
                print("Invalid position.")
        elif choice == "2":
            if not a:
                print("Array is empty.")
                continue
            pos = int(input("Enter position (0-based): "))
            if 0 <= pos < len(a):
                print("Deleted:", a.pop(pos))
            else:
                print("Invalid position.")
        elif choice == "3":
            display(a)
        elif choice == "0":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
