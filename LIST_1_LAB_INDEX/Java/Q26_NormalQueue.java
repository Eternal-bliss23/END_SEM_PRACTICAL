import java.util.Scanner;

public class Q26_NormalQueue {
    static final int CAP = 10;
    static int[] q = new int[CAP];
    static int front = 0, rear = -1;
    static Scanner sc = new Scanner(System.in);

    static boolean isEmpty() { return front > rear; }
    static void enqueue(int v) {
        if (rear == CAP - 1) { System.out.println("Queue full"); return; }
        q[++rear] = v;
    }
    static void dequeue() {
        if (isEmpty()) { System.out.println("Queue empty"); return; }
        System.out.println("Dequeued: " + q[front++]);
    }
    static void peek() {
        if (isEmpty()) { System.out.println("Queue empty"); return; }
        System.out.println("Front: " + q[front]);
    }
    static void display() {
        if (isEmpty()) { System.out.println("Queue empty"); return; }
        for (int i = front; i <= rear; i++) System.out.print(q[i] + " ");
        System.out.println();
    }
    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 Enqueue  2 Dequeue  3 Peek  4 Display  5 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.print("Value: "); enqueue(sc.nextInt()); break;
                case 2: dequeue(); break;
                case 3: peek(); break;
                case 4: display(); break;
                case 5: break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 5);
        sc.close();
    }
}
