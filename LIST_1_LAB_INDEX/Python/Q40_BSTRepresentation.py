class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
            return
        current = self.root
        while True:
            if key == current.key:
                print("Duplicate value ignored.")
                return
            parent = current
            current = current.left if key < current.key else current.right
            if current is None:
                new_node = Node(key)
                if key < parent.key:
                    parent.left = new_node
                else:
                    parent.right = new_node
                return

    def search(self, key):
        current = self.root
        while current is not None:
            if key == current.key:
                return True
            current = current.left if key < current.key else current.right
        return False

    def inorder(self, node, result):
        if node is None:
            return
        self.inorder(node.left, result)
        result.append(node.key)
        self.inorder(node.right, result)

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        if node is None:
            return None
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left
            successor = node.right
            while successor.left is not None:
                successor = successor.left
            node.key = successor.key
            node.right = self._delete(node.right, successor.key)
        return node


def read_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Enter a valid integer.")


def main():
    tree = BST()
    while True:
        print("\n1. Insert\n2. Search\n3. Inorder\n4. Delete\n5. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            tree.insert(read_int("Value: "))
        elif choice == "2":
            key = read_int("Value: ")
            print("Found." if tree.search(key) else "Not found.")
        elif choice == "3":
            result = []
            tree.inorder(tree.root, result)
            print("Inorder:", result if result else "(empty)")
        elif choice == "4":
            if tree.root is None:
                print("Tree is empty.")
            else:
                key = read_int("Value: ")
                if tree.search(key):
                    tree.delete(key)
                else:
                    print("Value not found.")
        elif choice == "5":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
