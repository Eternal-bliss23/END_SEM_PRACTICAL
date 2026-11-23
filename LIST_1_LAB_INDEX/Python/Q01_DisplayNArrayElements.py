# Q01: Display N Array Elements
# Purpose: Read n numbers into a list and print them in order.


def main():
    n = int(input("Enter n: "))
    a = []
    for i in range(n):
        value = int(input(f"Enter element {i + 1}: "))
        a.append(value)

    print("\nArray elements:")
    for i in range(n):
        print(f"a[{i}] = {a[i]}")
    print("Array:", a)


if __name__ == "__main__":
    main()
