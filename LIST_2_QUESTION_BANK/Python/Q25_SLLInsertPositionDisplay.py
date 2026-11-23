# Q25 - SLL: Insert at Position and Display
# Purpose: Insert a node at a 1-based position in a singly linked list.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def insert_position():
    global head
    pos = int(input("Enter position (1-based): "))
    value = int(input("Enter value to insert: "))
    new = Node(value)

    if pos == 1:
        new.next = head
        head = new
        print("Inserted at position 1")
        return

    cur = head
    for _ in range(pos - 2):
        if cur is None:
            print("Invalid position")
            return
        cur = cur.next

    if cur is None:
        print("Invalid position")
        return
    new.next = cur.next
    cur.next = new
    print("Inserted at position", pos)

def display():
    if head is None:
        print("List is empty")
        return
    cur = head
    while cur is not None:
        print(cur.data, end=" -> ")
        cur = cur.next
    print("None")

def main():
    while True:
        print("\n1. Insert at position  2. Display  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            insert_position()
        elif ch == 2:
            display()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
