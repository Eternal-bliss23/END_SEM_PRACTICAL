def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def read_graph():
    n = read_int("Number of vertices (0 to n-1): ")
    if n <= 0:
        print("Number of vertices must be positive.")
        return None, None
    directed = input("Directed? (y/n): ").strip().lower() == "y"
    graph = [[] for _ in range(n)]
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
        if v not in graph[u]:
            graph[u].append(v)
        if not directed and u not in graph[v]:
            graph[v].append(u)
    return n, graph


def dfs(vertex, graph, visited, order):
    visited[vertex] = True
    order.append(vertex)
    for neighbor in graph[vertex]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, order)


def main():
    while True:
        print("\n1. Run DFS\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        n, graph = read_graph()
        if n is None:
            continue
        start = read_int("Start vertex: ")
        if not 0 <= start < n:
            print("Start vertex out of range.")
            continue
        visited = [False] * n
        order = []
        dfs(start, graph, visited, order)
        print("DFS order:", order)


if __name__ == "__main__":
    main()
