// Question 12: Stack using Linked List
// Purpose: Implement push, pop, peek and display using Node objects.

import java.util.Scanner;

public class Q12_StackLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node top = null;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Push  2. Pop  3. Peek  4. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    Node n = new Node(sc.nextInt());
                    n.next = top;              // new node points to old top
                    top = n;                   // new node is the top
                    System.out.println("Pushed successfully.");
                    break;
                case 2:
                    if (top == null) System.out.println("Stack is empty!");
                    else {
                        System.out.println("Popped value: " + top.data);
                        top = top.next;
                    }
                    break;
                case 3:
                    if (top == null) System.out.println("Stack is empty!");
                    else System.out.println("Top element: " + top.data);
                    break;
                case 4:
                    if (top == null) System.out.println("Stack is empty!");
                    else {
                        System.out.print("Stack (top to bottom): ");
                        Node cur = top;
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
