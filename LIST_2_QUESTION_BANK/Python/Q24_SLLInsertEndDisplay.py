# Q24 - SLL: Insert at End and Display
# Purpose: Build a singly linked list by appending each value after the tail.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def display(head):
    cur = head
    while cur is not None:
        print(cur.data, end=" -> ")
        cur = cur.next
    print("None")

def main():
    n = int(input("Enter n: "))
    head = None
    tail = None

    for i in range(n):
        value = int(input("Enter element %d: " % (i + 1)))
        new = Node(value)
        if head is None:
            head = new
            tail = new
        else:
            tail.next = new
            tail = new
        print("Inserted", value, "at end")

    print("List (head to tail):")
    display(head)

if __name__ == "__main__":
    main()
