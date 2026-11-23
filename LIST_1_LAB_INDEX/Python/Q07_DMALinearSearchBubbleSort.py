# Q07: Dynamic Array - Linear Search and Bubble Sort
# Purpose: Search and sort a runtime-built list using a numbered menu.


def linear_search(a, key):
    for i in range(len(a)):
        if a[i] == key:
            return i
    return -1


def bubble_sort(a):
    n = len(a)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]


def main():
    n = int(input("Enter n: "))
    # Python equivalent of C dynamic memory allocation
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i + 1}: ")))

    while True:
        print("\n1. Linear Search  2. Bubble Sort  3. Display  0. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            key = int(input("Enter value to search: "))
            pos = linear_search(a, key)
            if pos == -1:
                print("Value not found.")
            else:
                print("Found at index:", pos)
        elif choice == "2":
            bubble_sort(a)
            print("Sorted array:", a)
        elif choice == "3":
            print("Array:", a)
        elif choice == "0":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
