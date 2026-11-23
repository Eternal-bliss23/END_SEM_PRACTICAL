CAPACITY = 5


class Deque:
    def __init__(self, capacity=CAPACITY):
        self.data = []
        self.capacity = capacity

    def is_empty(self):
        return len(self.data) == 0

    def is_full(self):
        return len(self.data) == self.capacity

    def insert_front(self, value):
        if self.is_full():
            print("Deque is full.")
            return
        self.data.insert(0, value)
        print("Inserted at front:", value)

    def insert_rear(self, value):
        if self.is_full():
            print("Deque is full.")
            return
        self.data.append(value)
        print("Inserted at rear:", value)

    def delete_front(self):
        if self.is_empty():
            print("Deque is empty.")
            return None
        value = self.data.pop(0)
        print("Deleted from front:", value)
        return value

    def delete_rear(self):
        if self.is_empty():
            print("Deque is empty.")
            return None
        value = self.data.pop()
        print("Deleted from rear:", value)
        return value

    def display(self):
        if self.is_empty():
            print("Deque is empty.")
            return
        print("Deque (front -> rear):", self.data)


def main():
    deque = Deque()
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
