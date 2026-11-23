def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def main():
    while True:
        print("\n1. Read graph and show degrees\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        n = read_int("Number of vertices: ")
        if n <= 0:
            print("Number of vertices must be positive.")
            continue
        kind = input("Directed or undirected? (d/u): ").strip().lower()
        directed = kind.startswith("d")
        matrix = []
        for i in range(n):
            row = []
            for j in range(n):
                value = read_int("Matrix[{0}][{1}] (0/1): ".format(i, j))
                row.append(1 if value else 0)
            matrix.append(row)
        print("\nVertex  Out  In  Total")
        for i in range(n):
            out_degree = sum(matrix[i])
            if directed:
                in_degree = sum(matrix[row][i] for row in range(n))
                total = out_degree + in_degree
            else:
                in_degree = out_degree
                total = out_degree
            print("{0:>6}  {1:>3}  {2:>2}  {3:>5}".format(
                i, out_degree, in_degree, total))


if __name__ == "__main__":
    main()
