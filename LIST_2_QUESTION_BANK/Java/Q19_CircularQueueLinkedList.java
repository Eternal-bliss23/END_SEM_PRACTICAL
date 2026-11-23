// Question 19: Circular Queue using Linked List
// Purpose: Enqueue and dequeue using a circular singly linked list.

import java.util.Scanner;

public class Q19_CircularQueueLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node rear = null;          // rear.next is the front node

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Enqueue  2. Dequeue  3. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value to enqueue: ");
                    Node n = new Node(sc.nextInt());
                    if (rear == null) {
                        n.next = n;                 // one node points to itself
                    } else {
                        n.next = rear.next;
                        rear.next = n;
                    }
                    rear = n;
                    System.out.println("Enqueued successfully.");
                    break;
                case 2:
                    if (rear == null) System.out.println("Queue is empty!");
                    else {
                        Node front = rear.next;
                        int val = front.data;
                        if (front == rear) rear = null;   // only one node
                        else rear.next = front.next;      // skip the front node
                        System.out.println("Dequeued value: " + val);
                    }
                    break;
                case 3:
                    if (rear == null) System.out.println("Queue is empty!");
                    else {
                        System.out.print("Queue (front to rear): ");
                        Node cur = rear.next;
                        do {
                            System.out.print(cur.data + " ");
                            cur = cur.next;
                        } while (cur != rear.next);
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
