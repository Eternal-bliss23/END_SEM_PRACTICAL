class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def is_empty(self):
        return self.top is None

    def push(self, value):
        node = Node(value)
        node.next = self.top
        self.top = node
        self.size += 1
        print("Pushed:", value)

    def pop(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        value = self.top.value
        self.top = self.top.next
        self.size -= 1
        print("Popped:", value)
        return value

    def peek(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        print("Top:", self.top.value)
        return self.top.value

    def display(self):
        if self.is_empty():
            print("Stack is empty.")
            return
        values = []
        current = self.top
        while current is not None:
            values.append(current.value)
            current = current.next
        print("Stack (top -> bottom):", values)


def main():
    stack = Stack()
    while True:
        print("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            stack.push(input("Enter value: "))
        elif choice == "2":
            stack.pop()
        elif choice == "3":
            stack.peek()
        elif choice == "4":
            stack.display()
        elif choice == "5":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
