# Q09 - Quick Sort
# Purpose: Sort a list recursively by partitioning values around a pivot.

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = []
    middle = []
    right = []
    for x in arr:
        if x < pivot:
            left.append(x)
        elif x > pivot:
            right.append(x)
        else:
            middle.append(x)

    return quick_sort(left) + middle + quick_sort(right)

def main():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))

    print("Original list:", arr)
    sorted_arr = quick_sort(arr)
    print("Sorted list:", sorted_arr)

if __name__ == "__main__":
    main()
