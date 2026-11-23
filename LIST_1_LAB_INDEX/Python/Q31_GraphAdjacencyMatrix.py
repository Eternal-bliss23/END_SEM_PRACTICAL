def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def main():
    while True:
        print("\n1. Build adjacency matrix\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        n = read_int("Number of vertices (0 to n-1): ")
        if n <= 0:
            print("Number of vertices must be positive.")
            continue
        directed = input("Directed? (y/n): ").strip().lower() == "y"
        matrix = [[0] * n for _ in range(n)]
        while True:
            line = input("Enter edge 'u v' (blank to finish): ").strip()
            if not line:
                break
            parts = line.split()
            if len(parts) != 2:
                print("Enter exactly two vertex numbers.")
                continue
            try:
                u, v = int(parts[0]), int(parts[1])
            except ValueError:
                print("Vertices must be integers.")
                continue
            if not (0 <= u < n and 0 <= v < n):
                print("Vertex out of range.")
                continue
            matrix[u][v] = 1
            if not directed:
                matrix[v][u] = 1
        print("Adjacency matrix:")
        for row in matrix:
            print(" ".join(str(value) for value in row))


if __name__ == "__main__":
    main()
