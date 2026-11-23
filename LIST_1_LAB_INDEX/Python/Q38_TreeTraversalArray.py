def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def preorder(index, data, left, right, result):
    if index == -1:
        return
    result.append(data[index])
    preorder(left[index], data, left, right, result)
    preorder(right[index], data, left, right, result)


def inorder(index, data, left, right, result):
    if index == -1:
        return
    inorder(left[index], data, left, right, result)
    result.append(data[index])
    inorder(right[index], data, left, right, result)


def postorder(index, data, left, right, result):
    if index == -1:
        return
    postorder(left[index], data, left, right, result)
    postorder(right[index], data, left, right, result)
    result.append(data[index])


def main():
    while True:
        print("\n1. Build binary tree and show traversals\n2. Exit")
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
        root = read_int("Root index (0 to n-1): ")
        if not 0 <= root < n:
            print("Root index out of range.")
            continue
        data = [None] * n
        left = [-1] * n
        right = [-1] * n
        for i in range(n):
            data[i] = input("Value for node {0}: ".format(i))
            left[i] = read_int("Left child index of {0} (-1 for none): ".format(i))
            right[i] = read_int("Right child index of {0} (-1 for none): ".format(i))
            for side in (left[i], right[i]):
                if side != -1 and not 0 <= side < n:
                    print("Child index out of range; using -1.")
            if left[i] != -1 and not 0 <= left[i] < n:
                left[i] = -1
            if right[i] != -1 and not 0 <= right[i] < n:
                right[i] = -1
        for name, traverse in (("Preorder", preorder), ("Inorder", inorder),
                               ("Postorder", postorder)):
            result = []
            traverse(root, data, left, right, result)
            print(name + ":", result)


if __name__ == "__main__":
    main()
