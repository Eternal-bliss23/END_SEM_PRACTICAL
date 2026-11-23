SIZE = 5


class Stack:
    def __init__(self, size=SIZE):
        self.data = [None] * size
        self.top = -1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == len(self.data) - 1

    def push(self, value):
        if self.is_full():
            print("Stack is full.")
            return
        self.top += 1
        self.data[self.top] = value
        print("Pushed:", value)

    def pop(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        value = self.data[self.top]
        self.data[self.top] = None
        self.top -= 1
        print("Popped:", value)
        return value

    def peek(self):
        if self.is_empty():
            print("Stack is empty.")
            return None
        print("Top:", self.data[self.top])
        return self.data[self.top]

    def display(self):
        if self.is_empty():
            print("Stack is empty.")
            return
        print("Stack (bottom -> top):", self.data[:self.top + 1])


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
