// Question 27: Circular List - Insert at Position
// Purpose: Insert a node at a 1-based position in a circular singly linked list.

import java.util.Scanner;

public class Q27_CircularListInsertPosition {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node head = null, tail = null;   // tail.next always points to head

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Insert at position  2. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    int v = sc.nextInt();
                    System.out.print("Enter position (1-based): ");
                    insert(v, sc.nextInt());
                    break;
                case 2:
                    display();
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Wrong choice!");
            }
        } while (choice != 0);
        sc.close();
    }

    static void insert(int v, int pos) {
        if (pos < 1) {
            System.out.println("Invalid position!");
            return;
        }
        Node n = new Node(v);
        if (head == null) {               // first node points to itself
            head = tail = n;
            n.next = n;
        } else if (pos == 1) {            // become the new head
            n.next = head;
            head = n;
        } else {
            Node cur = head;
            int count = 1;
            while (count < pos - 1 && cur != tail) {
                cur = cur.next;
                count++;
            }
            n.next = cur.next;            // old head if cur is the tail
            cur.next = n;
            if (cur == tail) tail = n;    // inserted after the tail
        }
        System.out.println("Inserted " + v + " at position " + pos + ".");
    }

    static void display() {
        if (head == null) {
            System.out.println("List is empty!");
            return;
        }
        System.out.print("Circular list: ");
        Node cur = head;
        do {
            System.out.print(cur.data + " ");
            cur = cur.next;
        } while (cur != head);
        System.out.println();
    }
}
