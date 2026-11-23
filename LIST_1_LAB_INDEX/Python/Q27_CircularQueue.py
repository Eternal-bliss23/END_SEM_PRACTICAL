CAPACITY = 5


class CircularQueue:
    def __init__(self, capacity=CAPACITY):
        self.data = [None] * capacity
        self.front = -1
        self.rear = -1

    def is_empty(self):
        return self.front == -1

    def is_full(self):
        return (self.rear + 1) % len(self.data) == self.front

    def enqueue(self, value):
        if self.is_full():
            print("Queue is full.")
            return
        if self.is_empty():
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % len(self.data)
        self.data[self.rear] = value
        print("Enqueued:", value)

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty.")
            return None
        value = self.data[self.front]
        self.data[self.front] = None
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % len(self.data)
        print("Dequeued:", value)
        return value

    def peek(self):
        if self.is_empty():
            print("Queue is empty.")
            return None
        print("Front:", self.data[self.front])
        return self.data[self.front]

    def display(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        values = []
        index = self.front
        while True:
            values.append(self.data[index])
            if index == self.rear:
                break
            index = (index + 1) % len(self.data)
        print("Queue (front -> rear):", values)


def main():
    queue = CircularQueue()
    while True:
        print("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            queue.enqueue(input("Enter value: "))
        elif choice == "2":
            queue.dequeue()
        elif choice == "3":
            queue.peek()
        elif choice == "4":
            queue.display()
        elif choice == "5":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
