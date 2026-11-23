# Q10 - Merge Sort
# Purpose: Split a list recursively, sort the halves, then merge them.

def merge(left, right):
    result = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    while i < len(left):
        result.append(left[i])
        i += 1
    while j < len(right):
        result.append(right[j])
        j += 1
    return result

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def main():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))

    print("Original list:", arr)
    sorted_arr = merge_sort(arr)
    print("Sorted list:", sorted_arr)

if __name__ == "__main__":
    main()
