# Q07 - Binary Search
# Purpose: Search a sorted list repeatedly by halving the search range.

def binary_search(arr, key):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif key < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1

def main():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d (in sorted order): " % (i + 1))))

    print("Sorted list:", arr)
    key = int(input("Enter key to search: "))

    index = binary_search(arr, key)
    if index == -1:
        print("Key", key, "not found")
    else:
        print("Key", key, "found at position", index + 1,
              "(index %d)" % index)

if __name__ == "__main__":
    main()
