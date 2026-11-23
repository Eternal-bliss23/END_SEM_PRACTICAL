// Question 24: SLL - Insert at End and Display
// Purpose: Build a singly linked list by appending every new node at the tail.

import java.util.Scanner;

public class Q24_SLLInsertEndDisplay {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            System.out.print("Value " + (i + 1) + ": ");
            Node newNode = new Node(sc.nextInt());
            if (head == null) {
                head = tail = newNode;    // first node
            } else {
                tail.next = newNode;
                tail = newNode;
            }
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
