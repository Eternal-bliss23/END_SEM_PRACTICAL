# Q08: Two-Dimensional Array in Row-Major Order
# Purpose: Store a matrix in one 1D list using i*cols+j and print it back as 2D.


def main():
    rows = int(input("Enter rows: "))
    cols = int(input("Enter columns: "))

    # Python equivalent of C dynamic memory allocation
    matrix = [0] * (rows * cols)
    for i in range(rows):
        for j in range(cols):
            value = int(input(f"Enter element [{i}][{j}]: "))
            matrix[i * cols + j] = value

    print("\nMatrix:")
    for i in range(rows):
        line = ""
        for j in range(cols):
            line += f"{matrix[i * cols + j]:5d}"
        print(line)

    print("\n1D storage:", matrix)


if __name__ == "__main__":
    main()
