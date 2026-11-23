// Question 28: Doubly Linked List
// Purpose: Insert/delete at ends or a position; display forward and backward.

import java.util.Scanner;

public class Q28_DoublyLinkedList {
    static class Node {
        int data;
        Node prev, next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node head = null, tail = null;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Insert begin  2. Insert end  3. Insert position");
            System.out.println("4. Delete first  5. Delete last  6. Display forward");
            System.out.println("7. Display backward  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1: insertBegin(); break;
                case 2: insertEnd(); break;
                case 3: insertAt(); break;
                case 4: deleteFirst(); break;
                case 5: deleteLast(); break;
                case 6: display(true); break;
                case 7: display(false); break;
                case 0: System.out.println("Exiting..."); break;
                default: System.out.println("Wrong choice!");
            }
        } while (choice != 0);
        sc.close();
    }

    static void insertBegin() {
        System.out.print("Enter value: ");
        Node n = new Node(sc.nextInt());
        if (head == null) head = tail = n;
        else { n.next = head; head.prev = n; head = n; }
        System.out.println("Inserted at beginning.");
    }

    static void insertEnd() {
        System.out.print("Enter value: ");
        Node n = new Node(sc.nextInt());
        if (tail == null) head = tail = n;
        else { tail.next = n; n.prev = tail; tail = n; }
        System.out.println("Inserted at end.");
    }

    static void insertAt() {
        System.out.print("Enter value: ");
        int v = sc.nextInt();
        System.out.print("Enter position (1-based): ");
        int pos = sc.nextInt();
        if (pos < 1) { System.out.println("Invalid position!"); return; }
        Node n = new Node(v);
        if (head == null) {
            head = tail = n;
        } else if (pos == 1) {
            n.next = head; head.prev = n; head = n;
        } else {
            Node cur = head;
            int count = 1;
            while (cur != null && count < pos - 1) { cur = cur.next; count++; }
            if (cur == null || cur == tail) {          // append at the end
                tail.next = n; n.prev = tail; tail = n;
            } else {                                   // insert in the middle
                n.next = cur.next; n.prev = cur;
                cur.next.prev = n; cur.next = n;
            }
        }
        System.out.println("Inserted " + v + " at position " + pos + ".");
    }

    static void deleteFirst() {
        if (head == null) { System.out.println("List is empty!"); return; }
        System.out.println("Deleted first node: " + head.data);
        if (head == tail) head = tail = null;
        else { head = head.next; head.prev = null; }
    }

    static void deleteLast() {
        if (tail == null) { System.out.println("List is empty!"); return; }
        System.out.println("Deleted last node: " + tail.data);
        if (head == tail) head = tail = null;
        else { tail = tail.prev; tail.next = null; }
    }

    static void display(boolean forward) {
        if (head == null) { System.out.println("List is empty!"); return; }
        System.out.print(forward ? "Forward:  " : "Backward: ");
        if (forward) {
            for (Node cur = head; cur != null; cur = cur.next) {
                System.out.print(cur.data + " ");
            }
        } else {
            for (Node cur = tail; cur != null; cur = cur.prev) {
                System.out.print(cur.data + " ");
            }
        }
        System.out.println();
    }
}
