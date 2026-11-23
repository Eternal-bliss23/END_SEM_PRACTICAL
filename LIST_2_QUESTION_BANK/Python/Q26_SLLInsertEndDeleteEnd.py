# Q26 - SLL: Insert at End and Delete Last Node
# Purpose: Append a node at the end and remove the last node of a list.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def insert_end():
    global head
    value = int(input("Enter value to insert: "))
    new = Node(value)
    if head is None:
        head = new
    else:
        cur = head
        while cur.next is not None:
            cur = cur.next
        cur.next = new
    print("Inserted", value, "at end")

def delete_end():
    global head
    if head is None:
        print("List is empty")
        return
    if head.next is None:
        print("Deleted:", head.data)
        head = None
        return
    cur = head
    while cur.next.next is not None:
        cur = cur.next
    print("Deleted:", cur.next.data)
    cur.next = None

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
        print("\n1. Insert at end  2. Delete last  3. Display  0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            insert_end()
        elif ch == 2:
            delete_end()
        elif ch == 3:
            display()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
