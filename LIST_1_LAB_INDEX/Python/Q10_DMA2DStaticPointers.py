# Q10: Static Array of Pointers to Allocated Rows
# Purpose: Build 3 row-lists, fill them and print each row and element.


def main():
    rows = 3
    cols = int(input("Enter number of columns per row: "))

    # This mirrors a static array of pointers to separately allocated rows
    table = []
    for i in range(rows):
        # Python equivalent of C dynamic memory allocation
        table.append([])

    for i in range(rows):
        print(f"Row {i + 1}:")
        for j in range(cols):
            value = int(input(f"  Column {j + 1}: "))
            table[i].append(value)

    print("\n2D array (array of row pointers):")
    for i in range(rows):
        for j in range(cols):
            print(f"table[{i}][{j}] = {table[i][j]}")
        print()

    print("Rows:", table)


if __name__ == "__main__":
    main()
