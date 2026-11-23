CAPACITY = 5


class Queue:
    def __init__(self, capacity=CAPACITY):
        self.data = [None] * capacity
        self.front = -1
        self.rear = -1

    def is_empty(self):
        return self.front == -1

    def is_full(self):
        return self.rear == len(self.data) - 1 and self.front == 0

    def enqueue(self, value):
        if self.is_full():
            print("Queue is full.")
            return
        if self.rear == len(self.data) - 1:
            for i in range(self.front, self.rear + 1):
                self.data[i - self.front] = self.data[i]
            self.rear -= self.front
            self.front = 0
        self.rear += 1
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
            self.front += 1
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
        print("Queue (front -> rear):", self.data[self.front:self.rear + 1])


def main():
    queue = Queue()
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
