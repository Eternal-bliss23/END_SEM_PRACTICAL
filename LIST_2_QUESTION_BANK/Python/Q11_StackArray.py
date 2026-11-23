# Q11 - Stack using an Array (list)
# Purpose: Implement a LIFO stack with push, pop, peek and display.

stack = []

def push():
    value = int(input("Enter value to push: "))
    stack.append(value)
    print("Pushed", value)

def pop():
    if len(stack) == 0:
        print("Stack underflow: stack is empty")
    else:
        print("Popped:", stack.pop())

def peek():
    if len(stack) == 0:
        print("Stack is empty")
    else:
        print("Top element:", stack[-1])

def display():
    if len(stack) == 0:
        print("Stack is empty")
    else:
        print("Stack (bottom to top):", stack)

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
