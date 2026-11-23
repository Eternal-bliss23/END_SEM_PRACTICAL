def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def main():
    while True:
        print("\n1. Build tree adjacency matrix\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        n = read_int("Number of nodes (0 to n-1): ")
        if n <= 0:
            print("Number of nodes must be positive.")
            continue
        matrix = [[0] * n for _ in range(n)]
        parent = [-1] * n
        edges = 0
        while edges < n - 1:
            line = input("Enter parent-child edge 'p c' (n-1 needed): ").strip()
            parts = line.split()
            if len(parts) != 2:
                print("Enter exactly two node numbers.")
                continue
            try:
                p, c = int(parts[0]), int(parts[1])
            except ValueError:
                print("Nodes must be integers.")
                continue
            if not (0 <= p < n and 0 <= c < n) or p == c:
                print("Invalid edge.")
                continue
            if parent[c] != -1:
                print("Node already has a parent.")
                continue
            matrix[p][c] = 1
            parent[c] = p
            edges += 1
        print("Adjacency matrix:")
        for row in matrix:
            print(" ".join(str(value) for value in row))
        print("Parent array:", parent)


if __name__ == "__main__":
    main()
