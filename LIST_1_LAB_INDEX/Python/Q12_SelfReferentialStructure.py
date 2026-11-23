# Q12: Self-Referential Structure
# Purpose: Give a Node a 'next' field that points to another Node, then walk it.


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def main():
    first = Node(10)
    second = Node(20)
    third = Node(30)

    first.next = second
    second.next = third
    third.next = None

    print("Linked nodes:")
    current = first
    position = 1
    while current is not None:
        print(f"Node {position}: data = {current.data}")
        current = current.next
        position += 1


if __name__ == "__main__":
    main()
