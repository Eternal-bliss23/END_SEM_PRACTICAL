// Question 26: SLL - Insert at End and Delete Last
// Purpose: Append nodes at the tail and remove the last node on request.

import java.util.Scanner;

public class Q26_SLLInsertEndDeleteEnd {
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
            System.out.println("1. Insert at end  2. Delete last  3. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    Node n = new Node(sc.nextInt());
                    if (head == null) {
                        head = n;
                    } else {
                        Node cur = head;
                        while (cur.next != null) cur = cur.next;   // find tail
                        cur.next = n;
                    }
                    System.out.println("Inserted at end.");
                    break;
                case 2:
                    if (head == null) {
                        System.out.println("List is empty!");
                    } else if (head.next == null) {
                        System.out.println("Deleted last node: " + head.data);
                        head = null;
                    } else {
                        Node cur = head;
                        while (cur.next.next != null) cur = cur.next;
                        System.out.println("Deleted last node: " + cur.next.data);
                        cur.next = null;
                    }
                    break;
                case 3:
                    if (head == null) System.out.println("List is empty!");
                    else {
                        System.out.print("Linked list: ");
                        Node cur = head;
                        while (cur != null) {
                            System.out.print(cur.data + " ");
                            cur = cur.next;
                        }
                        System.out.println();
                    }
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
}
