# Q18 - Queue using Linked List
# Purpose: Implement a FIFO queue with linked nodes and front/rear pointers.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

front = None
rear = None

def enqueue():
    global front, rear
    value = int(input("Enter value to enqueue: "))
    new = Node(value)
    if rear is None:
        front = new
        rear = new
    else:
        rear.next = new
        rear = new
    print("Enqueued", value)

def dequeue():
    global front, rear
    if front is None:
        print("Queue is empty")
    else:
        print("Dequeued:", front.data)
        front = front.next
        if front is None:
            rear = None

def peek():
    if front is None:
        print("Queue is empty")
    else:
        print("Front element:", front.data)

def display():
    if front is None:
        print("Queue is empty")
    else:
        items = []
        cur = front
        while cur is not None:
            items.append(cur.data)
            cur = cur.next
        print("Queue (front to rear):", items)

def main():
    while True:
        print("\n1. Enqueue  2. Dequeue  3. Peek  4. Display  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            enqueue()
        elif ch == 2:
            dequeue()
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
