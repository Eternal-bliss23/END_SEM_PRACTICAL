# Q22 - Circular Queue using an Array
# Purpose: Reuse freed slots by treating a fixed-size list as a circle.

capacity = 5
queue = [None] * capacity
front = 0
rear = -1
count = 0

def enqueue():
    global rear, count
    if count == capacity:
        print("Queue is full")
        return
    value = int(input("Enter value to enqueue: "))
    rear = (rear + 1) % capacity
    queue[rear] = value
    count += 1
    print("Enqueued", value)

def dequeue():
    global front, count
    if count == 0:
        print("Queue is empty")
        return
    print("Dequeued:", queue[front])
    queue[front] = None
    front = (front + 1) % capacity
    count -= 1

def peek():
    if count == 0:
        print("Queue is empty")
    else:
        print("Front element:", queue[front])

def display():
    if count == 0:
        print("Queue is empty")
        return
    items = []
    i = front
    for _ in range(count):
        items.append(queue[i])
        i = (i + 1) % capacity
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
