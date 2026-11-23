# Q02 - Insert at Position
# Purpose: Insert a value at a given 1-based position in a list.

def read_list():
    n = int(input("Enter n: "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d: " % (i + 1))))
    return arr

def main():
    arr = read_list()
    print("Original list:", arr)

    value = int(input("Enter value to insert: "))
    pos = int(input("Enter position (1-based): "))

    if pos < 1 or pos > len(arr) + 1:
        print("Invalid position")
    else:
        arr.insert(pos - 1, value)
        print("List after insertion:", arr)

if __name__ == "__main__":
    main()
