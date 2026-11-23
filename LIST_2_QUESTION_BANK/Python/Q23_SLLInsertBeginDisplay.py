# Q23 - SLL: Insert at Beginning and Display
# Purpose: Build a singly linked list by inserting each new value at the head.

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

    for i in range(n):
        value = int(input("Enter element %d: " % (i + 1)))
        new = Node(value)
        new.next = head
        head = new
        print("Inserted", value, "at beginning")

    print("List (head to tail):")
    display(head)

if __name__ == "__main__":
    main()
