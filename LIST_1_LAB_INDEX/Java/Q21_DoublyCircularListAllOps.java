// Question 21: Doubly Circular List - All Operations
// Purpose: Maintain a doubly circular list and print it in both directions.
import java.util.Scanner;

public class Q21_DoublyCircularListAllOps {
    static class Node {
        int data;
        Node prev, next;
        Node(int d) { data = d; }
    }
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static Node lastNode() {
        if (head == null) return null;
        Node t = head;
        while (t.next != head) t = t.next;
        return t;
    }

    static int count() {
        if (head == null) return 0;
        int c = 1;
        for (Node t = head.next; t != head; t = t.next) c++;
        return c;
    }

    static void insertBegin(int v) {
        Node n = new Node(v);
        if (head == null) { n.next = n; n.prev = n; head = n; return; }
        Node last = lastNode();
        n.next = head;
        n.prev = last;
        last.next = n;
        head.prev = n;
        head = n;
    }

    static void insertEnd(int v) {
        if (head == null) { insertBegin(v); return; }
        Node last = lastNode();
        Node n = new Node(v);
        n.prev = last;
        n.next = head;
        last.next = n;
        head.prev = n;
    }

    static void insertAt(int pos, int v) {
        int c = count();
        if (pos < 1 || pos > c + 1) { System.out.println("Position out of range"); return; }
        if (pos == 1) { insertBegin(v); return; }
        if (pos == c + 1) { insertEnd(v); return; }
        Node t = head;
        for (int i = 1; i < pos - 1; i++) t = t.next;
        Node n = new Node(v);
        n.prev = t;
        n.next = t.next;
        t.next.prev = n;
        t.next = n;
    }

    static void deleteFirst() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.println("Deleted " + head.data);
        if (head.next == head) { head = null; return; }
        Node last = lastNode();
        head = head.next;
        head.prev = last;
        last.next = head;
    }

    static void deleteLast() {
        if (head == null) { System.out.println("List is empty"); return; }
        Node last = lastNode();
        System.out.println("Deleted " + last.data);
        if (last == head) { head = null; return; }
        Node before = last.prev;
        before.next = head;
        head.prev = before;
    }

    static void deleteAt(int pos) {
        int c = count();
        if (c == 0) { System.out.println("List is empty"); return; }
        if (pos < 1 || pos > c) { System.out.println("Position out of range"); return; }
        if (pos == 1) { deleteFirst(); return; }
        if (pos == c) { deleteLast(); return; }
        Node t = head;
        for (int i = 1; i < pos; i++) t = t.next;
        System.out.println("Deleted " + t.data);
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    static void displayForward() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.print("Forward: ");
        Node t = head;
        do { System.out.print(t.data + " <-> "); t = t.next; } while (t != head);
        System.out.println("(back to head)");
    }

    static void displayBackward() {
        if (head == null) { System.out.println("List is empty"); return; }
        Node last = lastNode();
        System.out.print("Backward: ");
        Node t = last;
        do { System.out.print(t.data + " <-> "); t = t.prev; } while (t != last);
        System.out.println("(back to tail)");
    }

    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 Insert begin  2 Insert end  3 Insert at position");
            System.out.println("4 Delete first  5 Delete last  6 Delete at position");
            System.out.println("7 Display forward  8 Display backward  0 Exit");
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
                case 7: displayForward(); break;
                case 8: displayBackward(); break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
