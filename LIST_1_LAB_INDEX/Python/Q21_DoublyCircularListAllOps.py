# Q21: Doubly Circular List - All Operations
# Purpose: Menu-driven insert, delete and forward/backward display on a doubly circular list.


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyCircularList:
    def __init__(self):
        self.head = None
        self.size = 0

    def node_at(self, pos):
        cur = self.head
        for _ in range(pos):
            cur = cur.next
        return cur

    def insert(self, data, pos):
        if pos < 0 or pos > self.size:
            print("Invalid position.")
            return
        node = Node(data)
        if self.size == 0:
            node.next = node
            node.prev = node
            self.head = node
        else:
            cur = self.node_at(pos % self.size)
            before = cur.prev
            node.prev = before
            node.next = cur
            before.next = node
            cur.prev = node
            if pos == 0:
                self.head = node
        self.size += 1
        print("Inserted", data, "at position", pos)

    def delete(self, pos):
        if pos < 0 or pos >= self.size:
            print("Invalid position.")
            return
        if self.size == 1:
            print("Deleted:", self.head.data)
            self.head = None
        else:
            cur = self.node_at(pos)
            print("Deleted:", cur.data)
            cur.prev.next = cur.next
            cur.next.prev = cur.prev
            if pos == 0:
                self.head = cur.next
        self.size -= 1

    def display_forward(self):
        if self.size == 0:
            print("Forward: (empty)")
            return
        cur = self.head
        items = []
        for _ in range(self.size):
            items.append(str(cur.data))
            cur = cur.next
        print("Forward:", " <-> ".join(items), "-> (head)")

    def display_backward(self):
        if self.size == 0:
            print("Backward: (empty)")
            return
        cur = self.head.prev
        items = []
        for _ in range(self.size):
            items.append(str(cur.data))
            cur = cur.prev
        print("Backward:", " <-> ".join(items), "-> (tail)")


def main():
    lst = DoublyCircularList()
    while True:
        print("\n1. Insert begin   2. Insert end   3. Insert position")
        print("4. Delete first   5. Delete last   6. Delete position")
        print("7. Display forward   8. Display backward   0. Exit")
        choice = input("Enter choice: ").strip()
        if choice in ("1", "2", "3"):
            data = input("Enter value: ")
            pos = 0 if choice == "1" else lst.size
            if choice == "3":
                pos = int(input("Enter position: "))
            lst.insert(data, pos)
        elif choice in ("4", "5", "6"):
            pos = 0 if choice == "4" else lst.size - 1
            if choice == "6":
                pos = int(input("Enter position: "))
            lst.delete(pos)
        elif choice == "7":
            lst.display_forward()
        elif choice == "8":
            lst.display_backward()
        elif choice == "0":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
