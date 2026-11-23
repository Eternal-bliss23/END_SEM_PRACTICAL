def preorder(node, first_child, next_sibling, result):
    if node == -1:
        return
    result.append(node)
    preorder(first_child[node], first_child, next_sibling, result)
    preorder(next_sibling[node], first_child, next_sibling, result)


def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def main():
    while True:
        print("\n1. Build tree and show representation\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        n = read_int("Number of nodes: ")
        if n <= 0:
            print("Number of nodes must be positive.")
            continue
        first_child = [-1] * n
        next_sibling = [-1] * n
        root = read_int("Root node: ")
        if not 0 <= root < n:
            print("Root out of range.")
            continue
        edges = 0
        while edges < n - 1:
            line = input("Enter parent-child edge 'p c': ").strip()
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
            if first_child[p] == -1:
                first_child[p] = c
            else:
                sibling = first_child[p]
                while next_sibling[sibling] != -1:
                    sibling = next_sibling[sibling]
                next_sibling[sibling] = c
            edges += 1
        print("\nNode  FirstChild  NextSibling")
        for node in range(n):
            print("{0:>4}  {1:>10}  {2:>11}".format(
                node, first_child[node], next_sibling[node]))
        order = []
        preorder(root, first_child, next_sibling, order)
        print("Preorder:", order)


if __name__ == "__main__":
    main()
