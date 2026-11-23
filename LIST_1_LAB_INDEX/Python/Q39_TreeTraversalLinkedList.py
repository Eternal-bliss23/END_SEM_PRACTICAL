class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def build():
    value = input("Enter node value (or -1 for no node): ")
    if value == "-1" or not value:
        return None
    node = Node(value)
    print("Building left child of", value)
    node.left = build()
    print("Building right child of", value)
    node.right = build()
    return node


def preorder(node, result):
    if node is None:
        return
    result.append(node.value)
    preorder(node.left, result)
    preorder(node.right, result)


def inorder(node, result):
    if node is None:
        return
    inorder(node.left, result)
    result.append(node.value)
    inorder(node.right, result)


def postorder(node, result):
    if node is None:
        return
    postorder(node.left, result)
    postorder(node.right, result)
    result.append(node.value)


def main():
    while True:
        print("\n1. Build binary tree and show traversals\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        print("Enter the root value first.")
        root = build()
        if root is None:
            print("Tree is empty.")
            continue
        for name, traverse in (("Preorder", preorder), ("Inorder", inorder),
                               ("Postorder", postorder)):
            result = []
            traverse(root, result)
            print(name + ":", result)


if __name__ == "__main__":
    main()
