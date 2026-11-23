# Q19 - Circular Queue using Linked List
# Purpose: Build a FIFO queue where the last node points back to the first.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# 'rear' points to the last node; rear.next is the front node.
rear = None

def enqueue():
    global rear
    value = int(input("Enter value to enqueue: "))
    new = Node(value)
    if rear is None:
        new.next = new
    else:
        new.next = rear.next
        rear.next = new
    rear = new
    print("Enqueued", value)

def dequeue():
    global rear
    if rear is None:
        print("Queue is empty")
    else:
        front = rear.next
        print("Dequeued:", front.data)
        if front is rear:
            rear = None
        else:
            rear.next = front.next

def display():
    if rear is None:
        print("Queue is empty")
    else:
        items = []
        cur = rear.next
        while True:
            items.append(cur.data)
            if cur is rear:
                break
            cur = cur.next
        print("Queue (front to rear):", items)

def main():
    while True:
        print("\n1. Enqueue  2. Dequeue  3. Display  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            enqueue()
        elif ch == 2:
            dequeue()
        elif ch == 3:
            display()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
