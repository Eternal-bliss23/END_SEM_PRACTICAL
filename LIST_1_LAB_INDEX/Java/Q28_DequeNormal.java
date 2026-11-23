import java.util.Scanner;

public class Q28_DequeNormal {
    static class Node {
        int data;
        Node prev, next;
        Node(int d) { data = d; }
    }
    static Node front, rear;
    static Scanner sc = new Scanner(System.in);

    static void insertFront(int v) {
        Node n = new Node(v);
        n.next = front;
        if (front != null) front.prev = n; else rear = n;
        front = n;
    }
    static void insertRear(int v) {
        Node n = new Node(v);
        n.prev = rear;
        if (rear != null) rear.next = n; else front = n;
        rear = n;
    }
    static void deleteFront() {
        if (front == null) { System.out.println("Deque empty"); return; }
        System.out.println("Deleted front: " + front.data);
        front = front.next;
        if (front != null) front.prev = null; else rear = null;
    }
    static void deleteRear() {
        if (rear == null) { System.out.println("Deque empty"); return; }
        System.out.println("Deleted rear: " + rear.data);
        rear = rear.prev;
        if (rear != null) rear.next = null; else front = null;
    }
    static void display() {
        if (front == null) { System.out.println("Deque empty"); return; }
        for (Node p = front; p != null; p = p.next) System.out.print(p.data + " ");
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
