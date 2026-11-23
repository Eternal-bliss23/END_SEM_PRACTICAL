// Question 18: Queue using Linked List
// Purpose: Implement enqueue, dequeue, peek and display with Node objects.

import java.util.Scanner;

public class Q18_QueueLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node front = null, rear = null;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Enqueue  2. Dequeue  3. Peek  4. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value to enqueue: ");
                    Node n = new Node(sc.nextInt());
                    if (rear == null) { front = rear = n; }
                    else { rear.next = n; rear = n; }
                    System.out.println("Enqueued successfully.");
                    break;
                case 2:
                    if (front == null) System.out.println("Queue is empty!");
                    else {
                        int val = front.data;
                        front = front.next;
                        if (front == null) rear = null;   // list became empty
                        System.out.println("Dequeued value: " + val);
                    }
                    break;
                case 3:
                    if (front == null) System.out.println("Queue is empty!");
                    else System.out.println("Front element: " + front.data);
                    break;
                case 4:
                    if (front == null) System.out.println("Queue is empty!");
                    else {
                        System.out.print("Queue (front to rear): ");
                        Node cur = front;
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
