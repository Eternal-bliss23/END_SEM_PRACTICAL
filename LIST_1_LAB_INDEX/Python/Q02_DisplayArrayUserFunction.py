# Q02: Display Array Using a User-Defined Function
# Purpose: Read n numbers into a list and print them from display(a).


def display(a):
    print("\nArray elements:")
    for i in range(len(a)):
        print(f"a[{i}] = {a[i]}")
    print("Array:", a)


def main():
    n = int(input("Enter n: "))
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i + 1}: ")))

    display(a)


if __name__ == "__main__":
    main()
