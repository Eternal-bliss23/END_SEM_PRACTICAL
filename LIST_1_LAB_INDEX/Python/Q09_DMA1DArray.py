# Q09: One-Dimensional Dynamic Array
# Purpose: Create a 1D list at runtime and display its elements.


def main():
    n = int(input("Enter n: "))
    # Python lists replace malloc/free: they grow automatically and need no free
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i + 1}: ")))

    print("\nArray elements:")
    for i in range(len(a)):
        print(f"a[{i}] = {a[i]}")
    print("Array:", a)


if __name__ == "__main__":
    main()
