# Q27 - Circular List: Insert at Position
# Purpose: Insert a node at a 1-based position in a circular singly list.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def list_size():
    if head is None:
        return 0
    cur = head
    count = 0
    while True:
        count += 1
        cur = cur.next
        if cur is head:
            break
    return count

def insert_position():
    global head
    pos = int(input("Enter position (1-based): "))
    n = list_size()
    if pos < 1 or pos > n + 1:
        print("Invalid position")
        return

    value = int(input("Enter value to insert: "))
    new = Node(value)

    if n == 0:
        new.next = new
        head = new
    elif pos == 1:
        tail = head
        while tail.next is not head:
            tail = tail.next
        new.next = head
        tail.next = new
        head = new
    else:
        cur = head
        for _ in range(pos - 2):
            cur = cur.next
        new.next = cur.next
        cur.next = new
    print("Inserted", value, "at position", pos)

def display():
    if head is None:
        print("List is empty")
        return
    cur = head
    while True:
        print(cur.data, end=" -> ")
        cur = cur.next
        if cur is head:
            break
    print("(back to head)")

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
