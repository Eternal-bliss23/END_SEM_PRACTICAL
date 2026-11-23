# Q12 - Stack using Linked List
# Purpose: Implement a LIFO stack with linked nodes and a top pointer.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

top = None

def push():
    global top
    value = int(input("Enter value to push: "))
    new = Node(value)
    new.next = top
    top = new
    print("Pushed", value)

def pop():
    global top
    if top is None:
        print("Stack underflow: stack is empty")
    else:
        print("Popped:", top.data)
        top = top.next

def peek():
    if top is None:
        print("Stack is empty")
    else:
        print("Top element:", top.data)

def display():
    if top is None:
        print("Stack is empty")
    else:
        items = []
        cur = top
        while cur is not None:
            items.append(cur.data)
            cur = cur.next
        print("Stack (top to bottom):", items)

def main():
    while True:
        print("\n1. Push  2. Pop  3. Peek  4. Display  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            push()
        elif ch == 2:
            pop()
        elif ch == 3:
            peek()
        elif ch == 4:
            display()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
