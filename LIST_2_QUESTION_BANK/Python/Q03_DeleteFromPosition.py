# Q03 - Delete from Position
# Purpose: Delete an element at a given 1-based position from a list.

def read_list():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))
    return arr

def main():
    arr = read_list()
    print("Original list:", arr)

    pos = int(input("Enter position to delete (1-based): "))

    if pos < 1 or pos > len(arr):
        print("Invalid position")
    else:
        removed = arr.pop(pos - 1)
        print("Deleted element:", removed)
        print("List after deletion:", arr)

if __name__ == "__main__":
    main()
