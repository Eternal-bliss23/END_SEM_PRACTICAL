# Q28 - Doubly Linked List
# Purpose: Insert/delete at both ends or a position; display both directions.

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

head = None
tail = None

def insert_begin():
    global head, tail
    value = int(input("Enter value: "))
    new = Node(value)
    new.next = head
    if head is None:
        tail = new
    else:
        head.prev = new
    head = new
    print("Inserted at beginning")
def insert_end():
    global head, tail
    value = int(input("Enter value: "))
    new = Node(value)
    new.prev = tail
    if tail is None:
        head = new
    else:
        tail.next = new
    tail = new
    print("Inserted at end")
def insert_position():
    pos = int(input("Enter position (1-based): "))
    if pos < 1:
        print("Invalid position")
        return
    if pos == 1:
        insert_begin()
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
    if cur.next is None:
        insert_end()
        return
    value = int(input("Enter value: "))
    new = Node(value)
    new.prev = cur
    new.next = cur.next
    cur.next.prev = new
    cur.next = new
    print("Inserted at position", pos)
def delete_first():
    global head, tail
    if head is None:
        print("List is empty")
        return
    print("Deleted:", head.data)
    head = head.next
    if head is None:
        tail = None
    else:
        head.prev = None
def delete_last():
    global head, tail
    if tail is None:
        print("List is empty")
        return
    print("Deleted:", tail.data)
    tail = tail.prev
    if tail is None:
        head = None
    else:
        tail.next = None
def display(backward=False):
    cur = tail if backward else head
    items = []
    while cur is not None:
        items.append(cur.data)
        cur = cur.prev if backward else cur.next
    print(("Backward" if backward else "Forward") + ":", items)
def main():
    while True:
        print("\n1. Insert begin  2. Insert end  3. Insert position")
        print("4. Delete first  5. Delete last")
        print("6. Display forward  7. Display backward  0. Exit")
        ch = int(input("Enter choice: "))
        if ch == 1: insert_begin()
        elif ch == 2: insert_end()
        elif ch == 3: insert_position()
        elif ch == 4: delete_first()
        elif ch == 5: delete_last()
        elif ch == 6: display()
        elif ch == 7: display(True)
        elif ch == 0:
            print("Goodbye!")
            break
        else: print("Invalid choice")

if __name__ == "__main__":
    main()
