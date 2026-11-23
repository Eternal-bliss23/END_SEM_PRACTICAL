# Q06 - Linear Search
# Purpose: Search for a key by checking each element of the list in order.

def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

def main():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))

    print("List:", arr)
    key = int(input("Enter key to search: "))

    index = linear_search(arr, key)
    if index == -1:
        print("Key", key, "not found")
    else:
        print("Key", key, "found at position", index + 1,
              "(index %d)" % index)

if __name__ == "__main__":
    main()
