// Question 20: Singly Circular List - All Operations
// Purpose: Insert and delete at any position in a circular singly linked list.
import java.util.Scanner;

public class Q20_SinglyCircularListAllOps {
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static int count() {
        if (head == null) return 0;
        int c = 1;
        for (Node t = head.next; t != head; t = t.next) c++;
        return c;
    }

    static void insertBegin(int v) {
        Node n = new Node(v);
        if (head == null) { n.next = n; head = n; return; }
        Node t = head;
        while (t.next != head) t = t.next;
        n.next = head;
        t.next = n;
        head = n;
    }

    static void insertEnd(int v) {
        Node n = new Node(v);
        if (head == null) { n.next = n; head = n; return; }
        Node t = head;
        while (t.next != head) t = t.next;
        n.next = head;
        t.next = n;
    }

    static void insertAt(int pos, int v) {
        if (pos < 1 || pos > count() + 1) { System.out.println("Position out of range"); return; }
        if (pos == 1) { insertBegin(v); return; }
        Node t = head;
        for (int i = 1; i < pos - 1; i++) t = t.next;
        Node n = new Node(v);
        n.next = t.next;
        t.next = n;
    }

    static void deleteFirst() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.println("Deleted " + head.data);
        if (head.next == head) { head = null; return; }
        Node t = head;
        while (t.next != head) t = t.next;
        t.next = head.next;
        head = head.next;
    }

    static void deleteLast() {
        if (head == null) { System.out.println("List is empty"); return; }
        if (head.next == head) {
            System.out.println("Deleted " + head.data);
            head = null;
            return;
        }
        Node t = head;
        while (t.next.next != head) t = t.next;
        System.out.println("Deleted " + t.next.data);
        t.next = head;
    }

    static void deleteAt(int pos) {
        int c = count();
        if (c == 0) { System.out.println("List is empty"); return; }
        if (pos < 1 || pos > c) { System.out.println("Position out of range"); return; }
        if (pos == 1) { deleteFirst(); return; }
        Node t = head;
        for (int i = 1; i < pos - 1; i++) t = t.next;
        System.out.println("Deleted " + t.next.data);
        t.next = t.next.next;
    }

    static void display() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.print("List: ");
        Node t = head;
        do {
            System.out.print(t.data + " -> ");
            t = t.next;
        } while (t != head);
        System.out.println("(back to " + head.data + ")");
    }

    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 Insert begin  2 Insert end  3 Insert at position");
            System.out.println("4 Delete first  5 Delete last  6 Delete at position");
            System.out.println("7 Display  0 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: case 2:
                    System.out.print("Value: ");
                    int v = sc.nextInt();
                    if (ch == 1) insertBegin(v); else insertEnd(v);
                    break;
                case 3:
                    System.out.print("Position: ");
                    int p = sc.nextInt();
                    System.out.print("Value: ");
                    insertAt(p, sc.nextInt());
                    break;
                case 4: deleteFirst(); break;
                case 5: deleteLast(); break;
                case 6:
                    System.out.print("Position: ");
                    deleteAt(sc.nextInt());
                    break;
                case 7: display(); break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
