// Question 19: Doubly Linked List - All Operations
// Purpose: Insert/delete at both ends or a position; walk forward and backward.
import java.util.Scanner;

public class Q19_DoublyLinkedListAllOps {
    static class Node {
        int data;
        Node prev, next;
        Node(int d) { data = d; }
    }
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static void insertBegin(int v) {
        Node n = new Node(v);
        n.next = head;
        if (head != null) head.prev = n;
        head = n;
    }

    static void insertEnd(int v) {
        Node n = new Node(v);
        if (head == null) { head = n; return; }
        Node t = head;
        while (t.next != null) t = t.next;
        t.next = n;
        n.prev = t;
    }

    static void insertAt(int pos, int v) {
        if (pos <= 1) { insertBegin(v); return; }
        Node t = head;
        for (int i = 1; i < pos - 1 && t != null; i++) t = t.next;
        if (t == null) { System.out.println("Position out of range"); return; }
        Node n = new Node(v);
        n.next = t.next;
        n.prev = t;
        if (t.next != null) t.next.prev = n;
        t.next = n;
    }

    static void deleteFirst() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.println("Deleted " + head.data);
        head = head.next;
        if (head != null) head.prev = null;
    }

    static void deleteLast() {
        if (head == null) { System.out.println("List is empty"); return; }
        Node t = head;
        while (t.next != null) t = t.next;
        System.out.println("Deleted " + t.data);
        if (t == head) head = null;
        else t.prev.next = null;
    }

    static void deleteAt(int pos) {
        if (head == null) { System.out.println("List is empty"); return; }
        if (pos == 1) { deleteFirst(); return; }
        Node t = head;
        for (int i = 1; i < pos && t != null; i++) t = t.next;
        if (t == null) { System.out.println("Position out of range"); return; }
        System.out.println("Deleted " + t.data);
        t.prev.next = t.next;
        if (t.next != null) t.next.prev = t.prev;
    }

    static void displayForward() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.print("Forward: ");
        for (Node t = head; t != null; t = t.next) System.out.print(t.data + " <-> ");
        System.out.println("null");
    }

    static void displayBackward() {
        if (head == null) { System.out.println("List is empty"); return; }
        Node t = head;
        while (t.next != null) t = t.next;
        System.out.print("Backward: ");
        for (; t != null; t = t.prev) System.out.print(t.data + " <-> ");
        System.out.println("null");
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
