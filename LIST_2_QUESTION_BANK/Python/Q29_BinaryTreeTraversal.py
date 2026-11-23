# Q29 - Binary Tree Traversal
# Purpose: Build a tree in level order, then show preorder/inorder/postorder.

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert_level_order(root, value):
    new = Node(value)
    if root is None:
        return new
    q = deque([root])
    while q:
        cur = q.popleft()
        if cur.left is None:
            cur.left = new
            return root
        q.append(cur.left)
        if cur.right is None:
            cur.right = new
            return root
        q.append(cur.right)
    return root

def preorder(node):
    if node is not None:
        print(node.data, end=" ")
        preorder(node.left)
        preorder(node.right)

def inorder(node):
    if node is not None:
        inorder(node.left)
        print(node.data, end=" ")
        inorder(node.right)

def postorder(node):
    if node is not None:
        postorder(node.left)
        postorder(node.right)
        print(node.data, end=" ")

def main():
    n = int(input("Enter number of nodes: "))
    root = None
    for i in range(n):
        value = int(input("Enter element %d: " % (i + 1)))
        root = insert_level_order(root, value)

    while True:
        print("\n1. Preorder  2. Inorder  3. Postorder  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            print("Preorder:", end=" ")
            preorder(root)
            print()
        elif ch == 2:
            print("Inorder:", end=" ")
            inorder(root)
            print()
        elif ch == 3:
            print("Postorder:", end=" ")
            postorder(root)
            print()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
