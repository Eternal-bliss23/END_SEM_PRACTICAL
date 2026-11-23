# Q05 - Matrix Multiplication
# Purpose: Read A (r1 x c1) and B (c1 x c2) and print their product.

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
    r1 = int(input("Enter rows of A: "))
    c1 = int(input("Enter columns of A: "))
    a = read_matrix(r1, c1, "A")

    c2 = int(input("Enter columns of B (rows of B = %d): " % c1))
    b = read_matrix(c1, c2, "B")

    result = []
    for i in range(r1):
        row = []
        for j in range(c2):
            total = 0
            for k in range(c1):
                total += a[i][k] * b[k][j]
            row.append(total)
        result.append(row)

    print("Matrix A:")
    print_matrix(a)
    print("Matrix B:")
    print_matrix(b)
    print("Product A x B:")
    print_matrix(result)

if __name__ == "__main__":
    main()
