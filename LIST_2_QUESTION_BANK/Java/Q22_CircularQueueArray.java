// Question 22: Circular Queue using Array
// Purpose: Use a circular array so empty slots can be reused after dequeue.

import java.util.Scanner;

public class Q22_CircularQueueArray {
    static Scanner sc = new Scanner(System.in);
    static final int MAX = 5;
    static int[] q = new int[MAX];
    static int front = -1, rear = -1;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Enqueue  2. Dequeue  3. Peek  4. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    if ((rear + 1) % MAX == front) System.out.println("Queue is full!");
                    else {
                        System.out.print("Enter value to enqueue: ");
                        if (front == -1) front = rear = 0;
                        else rear = (rear + 1) % MAX;
                        q[rear] = sc.nextInt();
                        System.out.println("Enqueued successfully.");
                    }
                    break;
                case 2:
                    if (front == -1) System.out.println("Queue is empty!");
                    else {
                        System.out.println("Dequeued value: " + q[front]);
                        if (front == rear) front = rear = -1;
                        else front = (front + 1) % MAX;
                    }
                    break;
                case 3:
                    if (front == -1) System.out.println("Queue is empty!");
                    else System.out.println("Front element: " + q[front]);
                    break;
                case 4:
                    if (front == -1) System.out.println("Queue is empty!");
                    else {
                        System.out.print("Queue (front to rear): ");
                        int i = front;
                        while (true) {
                            System.out.print(q[i] + " ");
                            if (i == rear) break;
                            i = (i + 1) % MAX;
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
