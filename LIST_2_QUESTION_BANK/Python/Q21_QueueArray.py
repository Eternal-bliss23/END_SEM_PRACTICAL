# Q21 - Queue using an Array
# Purpose: Implement a fixed-size FIFO queue with front and rear indexes.

capacity = 5
queue = [None] * capacity
front = -1
rear = -1

def enqueue():
    global front, rear
    if rear == capacity - 1:
        print("Queue is full")
        return
    value = int(input("Enter value to enqueue: "))
    rear += 1
    queue[rear] = value
    if front == -1:
        front = 0
    print("Enqueued", value)

def dequeue():
    global front, rear
    if front == -1 or front > rear:
        print("Queue is empty")
        return
    print("Dequeued:", queue[front])
    queue[front] = None
    front += 1
    if front > rear:
        front = -1
        rear = -1

def peek():
    if front == -1 or front > rear:
        print("Queue is empty")
    else:
        print("Front element:", queue[front])

def display():
    if front == -1 or front > rear:
        print("Queue is empty")
        return
    items = []
    for i in range(front, rear + 1):
        items.append(queue[i])
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
