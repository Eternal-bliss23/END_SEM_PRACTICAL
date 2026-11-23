# Q11: Dynamic 2D Array (Pointers to Rows)
# Purpose: Read rows and cols, build each row dynamically, then print matrix.


def main():
    rows = int(input("Enter rows: "))
    cols = int(input("Enter columns: "))

    # Python equivalent of C dynamic memory allocation
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input(f"Element [{i}][{j}]: ")))
        matrix.append(row)

    print("\nMatrix:")
    for i in range(rows):
        for j in range(cols):
            print(f"{matrix[i][j]:5d}", end="")
        print()

    print("\nRows:", matrix)


if __name__ == "__main__":
    main()
