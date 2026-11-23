# Q08 - Bubble Sort
# Purpose: Sort a list by repeatedly swapping adjacent out-of-order values.

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def main():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))

    print("Original list:", arr)
    bubble_sort(arr)
    print("Sorted list:", arr)

if __name__ == "__main__":
    main()
