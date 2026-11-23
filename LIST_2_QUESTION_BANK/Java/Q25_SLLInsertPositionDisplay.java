// Question 25: SLL - Insert at Position and Display
// Purpose: Insert a value at a 1-based position in a singly linked list.

import java.util.Scanner;

public class Q25_SLLInsertPositionDisplay {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node head = null;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Insert at position  2. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    int value = sc.nextInt();
                    System.out.print("Enter position (1-based): ");
                    int pos = sc.nextInt();
                    insert(value, pos);
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

    static void insert(int value, int pos) {
        if (pos < 1) {
            System.out.println("Invalid position!");
            return;
        }
        Node n = new Node(value);
        if (pos == 1) {                    // new head
            n.next = head;
            head = n;
            System.out.println("Inserted at position 1.");
            return;
        }
        Node cur = head;
        int count = 1;
        while (cur != null && count < pos - 1) {
            cur = cur.next;
            count++;
        }
        if (cur == null) {
            System.out.println("Position beyond end of list!");
        } else {
            n.next = cur.next;
            cur.next = n;
            System.out.println("Inserted at position " + pos + ".");
        }
    }

    static void display() {
        if (head == null) {
            System.out.println("List is empty!");
            return;
        }
        System.out.print("Linked list: ");
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
    }
}
