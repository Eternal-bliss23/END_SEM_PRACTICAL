# Q01 - Merge Two Arrays
# Purpose: Read two lists and merge all their elements into a third list.

def read_list(name):
    n = int(input("Enter n for " + name + ": "))
    arr = []
    for i in range(n):
        arr.append(int(input("Enter element %d of %s: " % (i + 1, name))))
    return arr

def main():
    a = read_list("first list")
    b = read_list("second list")

    merged = []
    for x in a:
        merged.append(x)
    for x in b:
        merged.append(x)

    print("First list:", a)
    print("Second list:", b)
    print("Merged list:", merged)

if __name__ == "__main__":
    main()
