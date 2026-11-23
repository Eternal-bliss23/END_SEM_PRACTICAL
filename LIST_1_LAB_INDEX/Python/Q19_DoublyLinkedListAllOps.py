# Q19: Doubly Linked List - All Operations
# Purpose: Menu-driven insert, delete and forward/backward display operations.


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyList:
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
            self.head = node
        elif pos == 0:
            node.next = self.head
            self.head.prev = node
            self.head = node
        elif pos == self.size:
            cur = self.node_at(self.size - 1)
            cur.next = node
            node.prev = cur
        else:
            cur = self.node_at(pos)
            before = cur.prev
            node.prev = before
            node.next = cur
            before.next = node
            cur.prev = node
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
            if cur.prev is not None:
                cur.prev.next = cur.next
            else:
                self.head = cur.next
            if cur.next is not None:
                cur.next.prev = cur.prev
        self.size -= 1

    def display_forward(self):
        cur = self.head
        items = []
        while cur is not None:
            items.append(str(cur.data))
            cur = cur.next
        print("Forward:", " <-> ".join(items) if items else "(empty)")

    def display_backward(self):
        cur = self.head
        if cur is None:
            print("Backward: (empty)")
            return
        while cur.next is not None:
            cur = cur.next
        items = []
        while cur is not None:
            items.append(str(cur.data))
            cur = cur.prev
        print("Backward:", " <-> ".join(items))


def main():
    lst = DoublyList()
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
