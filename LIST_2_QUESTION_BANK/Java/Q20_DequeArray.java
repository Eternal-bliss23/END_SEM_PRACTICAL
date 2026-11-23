// Question 20: Deque using Circular Array
// Purpose: Insert and delete at both ends of a deque using a circular array.

import java.util.Scanner;

public class Q20_DequeArray {
    static Scanner sc = new Scanner(System.in);
    static final int MAX = 5;
    static int[] dq = new int[MAX];
    static int front = -1, rear = -1;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Insert front  2. Insert rear  3. Delete front");
            System.out.println("4. Delete rear   5. Display      0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    if (isFull()) System.out.println("Deque is full!");
                    else {
                        System.out.print("Enter value: ");
                        int v = sc.nextInt();
                        if (front == -1) front = rear = 0;
                        else front = (front - 1 + MAX) % MAX;
                        dq[front] = v;
                        System.out.println("Inserted at front.");
                    }
                    break;
                case 2:
                    if (isFull()) System.out.println("Deque is full!");
                    else {
                        System.out.print("Enter value: ");
                        int v = sc.nextInt();
                        if (front == -1) front = rear = 0;
                        else rear = (rear + 1) % MAX;
                        dq[rear] = v;
                        System.out.println("Inserted at rear.");
                    }
                    break;
                case 3:
                    if (front == -1) System.out.println("Deque is empty!");
                    else {
                        System.out.println("Deleted from front: " + dq[front]);
                        if (front == rear) front = rear = -1;
                        else front = (front + 1) % MAX;
                    }
                    break;
                case 4:
                    if (front == -1) System.out.println("Deque is empty!");
                    else {
                        System.out.println("Deleted from rear: " + dq[rear]);
                        if (front == rear) front = rear = -1;
                        else rear = (rear - 1 + MAX) % MAX;
                    }
                    break;
                case 5:
                    if (front == -1) System.out.println("Deque is empty!");
                    else {
                        System.out.print("Deque (front to rear): ");
                        int i = front;
                        while (true) {
                            System.out.print(dq[i] + " ");
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

    static boolean isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }
}
