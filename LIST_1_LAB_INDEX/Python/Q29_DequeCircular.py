CAPACITY = 5


class CircularDeque:
    def __init__(self, capacity=CAPACITY):
        self.data = [None] * capacity
        self.front = -1
        self.rear = -1

    def is_empty(self):
        return self.front == -1

    def is_full(self):
        return (self.rear + 1) % len(self.data) == self.front

    def insert_front(self, value):
        if self.is_full():
            print("Deque is full.")
            return
        if self.is_empty():
            self.front = self.rear = 0
        else:
            self.front = (self.front - 1) % len(self.data)
        self.data[self.front] = value
        print("Inserted at front:", value)

    def insert_rear(self, value):
        if self.is_full():
            print("Deque is full.")
            return
        if self.is_empty():
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % len(self.data)
        self.data[self.rear] = value
        print("Inserted at rear:", value)

    def delete_front(self):
        if self.is_empty():
            print("Deque is empty.")
            return None
        value = self.data[self.front]
        self.data[self.front] = None
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % len(self.data)
        print("Deleted from front:", value)
        return value

    def delete_rear(self):
        if self.is_empty():
            print("Deque is empty.")
            return None
        value = self.data[self.rear]
        self.data[self.rear] = None
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.rear = (self.rear - 1) % len(self.data)
        print("Deleted from rear:", value)
        return value

    def display(self):
        if self.is_empty():
            print("Deque is empty.")
            return
        values = []
        index = self.front
        while True:
            values.append(self.data[index])
            if index == self.rear:
                break
            index = (index + 1) % len(self.data)
        print("Deque (front -> rear):", values)


def main():
    deque = CircularDeque()
    while True:
        print("\n1. Insert front\n2. Insert rear\n3. Delete front")
        print("4. Delete rear\n5. Display\n6. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            deque.insert_front(input("Enter value: "))
        elif choice == "2":
            deque.insert_rear(input("Enter value: "))
        elif choice == "3":
            deque.delete_front()
        elif choice == "4":
            deque.delete_rear()
        elif choice == "5":
            deque.display()
        elif choice == "6":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
