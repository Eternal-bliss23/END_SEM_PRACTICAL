// Question 23: SLL - Insert at Beginning and Display
// Purpose: Build a singly linked list by inserting every new node at the head.

import java.util.Scanner;

public class Q23_SLLInsertBeginDisplay {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        Node head = null;
        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            System.out.print("Value " + (i + 1) + ": ");
            Node newNode = new Node(sc.nextInt());
            newNode.next = head;       // new node points to old head
            head = newNode;            // new node becomes the head
        }

        System.out.print("Linked list (head to tail): ");
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
        sc.close();
    }
}
