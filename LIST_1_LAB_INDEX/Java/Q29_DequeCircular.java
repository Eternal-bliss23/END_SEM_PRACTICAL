import java.util.Scanner;

public class Q29_DequeCircular {
    static final int CAP = 10;
    static int[] dq = new int[CAP];
    static int front = 0, rear = 0, count = 0;
    static Scanner sc = new Scanner(System.in);

    static void insertFront(int v) {
        if (count == CAP) { System.out.println("Deque full"); return; }
        front = (front - 1 + CAP) % CAP;
        dq[front] = v;
        count++;
    }
    static void insertRear(int v) {
        if (count == CAP) { System.out.println("Deque full"); return; }
        dq[rear] = v;
        rear = (rear + 1) % CAP;
        count++;
    }
    static void deleteFront() {
        if (count == 0) { System.out.println("Deque empty"); return; }
        System.out.println("Deleted front: " + dq[front]);
        front = (front + 1) % CAP;
        count--;
    }
    static void deleteRear() {
        if (count == 0) { System.out.println("Deque empty"); return; }
        rear = (rear - 1 + CAP) % CAP;
        System.out.println("Deleted rear: " + dq[rear]);
        count--;
    }
    static void display() {
        if (count == 0) { System.out.println("Deque empty"); return; }
        for (int i = 0; i < count; i++) System.out.print(dq[(front + i) % CAP] + " ");
        System.out.println();
    }
    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 InsertFront  2 InsertRear  3 DeleteFront  4 DeleteRear  5 Display  6 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.print("Value: "); insertFront(sc.nextInt()); break;
                case 2: System.out.print("Value: "); insertRear(sc.nextInt()); break;
                case 3: deleteFront(); break;
                case 4: deleteRear(); break;
                case 5: display(); break;
                case 6: break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 6);
        sc.close();
    }
}
