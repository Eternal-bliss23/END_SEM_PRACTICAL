# Q04 - Matrix Addition and Subtraction
# Purpose: Read two matrices and add or subtract them using a menu.

def read_matrix(rows, cols, name):
    print("Enter matrix", name)
    m = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input("Element [%d][%d]: " % (i + 1, j + 1))))
        m.append(row)
    return m

def print_matrix(m):
    for row in m:
        print("  " + " ".join(str(x) for x in row))

def main():
    while True:
        print("\n1. Add  2. Subtract  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 0:
            print("Goodbye!")
            break
        if ch not in (1, 2):
            print("Invalid choice")
            continue

        rows = int(input("Enter rows: "))
        cols = int(input("Enter columns: "))
        a = read_matrix(rows, cols, "A")
        b = read_matrix(rows, cols, "B")

        result = []
        for i in range(rows):
            row = []
            for j in range(cols):
                if ch == 1:
                    row.append(a[i][j] + b[i][j])
                else:
                    row.append(a[i][j] - b[i][j])
            result.append(row)

        print("Matrix A:")
        print_matrix(a)
        print("Matrix B:")
        print_matrix(b)
        print("Result:")
        print_matrix(result)

if __name__ == "__main__":
    main()
