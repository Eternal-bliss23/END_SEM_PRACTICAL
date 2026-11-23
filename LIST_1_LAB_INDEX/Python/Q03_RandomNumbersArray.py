# Q03: Array of Random Numbers
# Purpose: Fill a list with random numbers from 0 to 99 and print it.
import random


def main():
    n = int(input("Enter n: "))
    a = []
    for i in range(n):
        a.append(random.randint(0, 99))

    print("\nRandom numbers:")
    for i in range(n):
        print(f"a[{i}] = {a[i]}")
    print("Array:", a)


if __name__ == "__main__":
    main()
