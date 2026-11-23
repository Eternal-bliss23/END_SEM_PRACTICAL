# Q20 - Deque using a Circular Array
# Purpose: Insert and delete at both ends of a fixed-size circular list.

capacity = 5
deque = [None] * capacity
front = 0
rear = -1
count = 0

def insert_front():
    global front, rear, count
    if count == capacity:
        print("Deque is full")
        return
    front = (front - 1) % capacity
    deque[front] = int(input("Enter value: "))
    if count == 0:
        rear = front
    count += 1
    print("Inserted at front")

def insert_rear():
    global front, rear, count
    if count == capacity:
        print("Deque is full")
        return
    rear = (rear + 1) % capacity
    deque[rear] = int(input("Enter value: "))
    if count == 0:
        front = rear
    count += 1
    print("Inserted at rear")

def delete_front():
    global front, count
    if count == 0:
        print("Deque is empty")
        return
    print("Deleted from front:", deque[front])
    front = (front + 1) % capacity
    count -= 1

def delete_rear():
    global rear, count
    if count == 0:
        print("Deque is empty")
        return
    print("Deleted from rear:", deque[rear])
    rear = (rear - 1) % capacity
    count -= 1

def display():
    if count == 0:
        print("Deque is empty")
        return
    items = []
    i = front
    for _ in range(count):
        items.append(deque[i])
        i = (i + 1) % capacity
    print("Deque (front to rear):", items)

def main():
    while True:
        print("\n1. Insert front  2. Insert rear  3. Delete front")
        print("4. Delete rear   5. Display      0. Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            insert_front()
        elif ch == 2:
            insert_rear()
        elif ch == 3:
            delete_front()
        elif ch == 4:
            delete_rear()
        elif ch == 5:
            display()
        elif ch == 0:
            print("Goodbye!")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
