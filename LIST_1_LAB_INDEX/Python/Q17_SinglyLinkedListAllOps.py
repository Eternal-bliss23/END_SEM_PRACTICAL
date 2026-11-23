# Q17: Singly Linked List - All Operations
# Purpose: Menu-driven insert, delete, display, count and search operations.


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyList:
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
        if pos == 0:
            node.next = self.head
            self.head = node
        else:
            prev = self.node_at(pos - 1)
            node.next = prev.next
            prev.next = node
        self.size += 1
        print("Inserted", data, "at position", pos)

    def delete(self, pos):
        if pos < 0 or pos >= self.size:
            print("Invalid position.")
            return
        if pos == 0:
            print("Deleted:", self.head.data)
            self.head = self.head.next
        else:
            prev = self.node_at(pos - 1)
            print("Deleted:", prev.next.data)
            prev.next = prev.next.next
        self.size -= 1

    def display(self):
        cur = self.head
        items = []
        while cur is not None:
            items.append(str(cur.data))
            cur = cur.next
        print("List:", " -> ".join(items) if items else "(empty)")

    def count(self):
        total = 0
        cur = self.head
        while cur is not None:
            total += 1
            cur = cur.next
        return total

    def search(self, key):
        cur = self.head
        pos = 0
        while cur is not None:
            if cur.data == key:
                print("Found", key, "at position", pos)
                return
            cur = cur.next
            pos += 1
        print(key, "not found.")


def main():
    lst = SinglyList()
    while True:
        print("\n1. Insert begin   2. Insert end   3. Insert position")
        print("4. Delete first   5. Delete last   6. Delete position")
        print("7. Display   8. Count   9. Search   0. Exit")
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
            lst.display()
        elif choice == "8":
            print("Count:", lst.count())
        elif choice == "9":
            lst.search(input("Enter value to search: "))
        elif choice == "0":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
