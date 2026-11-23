# Q06: Dynamic Array Sum
# Purpose: Build a list at runtime, add its elements and print the total.


def main():
    n = int(input("Enter n: "))
    # Python equivalent of C dynamic memory allocation
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i + 1}: ")))

    total = 0
    for value in a:
        total += value

    print("Array:", a)
    print("Sum:", total)


if __name__ == "__main__":
    main()
