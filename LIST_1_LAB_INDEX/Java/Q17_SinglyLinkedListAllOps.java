// Question 17: Singly Linked List - All Operations
// Purpose: Insert, delete, display, count and search in a singly linked list.
import java.util.Scanner;

public class Q17_SinglyLinkedListAllOps {
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static void insertBegin(int v) {
        Node n = new Node(v);
        n.next = head;
        head = n;
    }

    static void insertEnd(int v) {
        Node n = new Node(v);
        if (head == null) { head = n; return; }
        Node t = head;
        while (t.next != null) t = t.next;
        t.next = n;
    }

    static void insertAt(int pos, int v) {
        if (pos <= 1) { insertBegin(v); return; }
        Node t = head;
        for (int i = 1; i < pos - 1 && t != null; i++) t = t.next;
        if (t == null) { System.out.println("Position out of range"); return; }
        Node n = new Node(v);
        n.next = t.next;
        t.next = n;
    }

    static void deleteFirst() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.println("Deleted " + head.data);
        head = head.next;
    }

    static void deleteLast() {
        if (head == null) { System.out.println("List is empty"); return; }
        if (head.next == null) {
            System.out.println("Deleted " + head.data);
            head = null;
            return;
        }
        Node t = head;
        while (t.next.next != null) t = t.next;
        System.out.println("Deleted " + t.next.data);
        t.next = null;
    }

    static void deleteAt(int pos) {
        if (head == null) { System.out.println("List is empty"); return; }
        if (pos == 1) { deleteFirst(); return; }
        Node t = head;
        for (int i = 1; i < pos - 1 && t.next != null; i++) t = t.next;
        if (t.next == null) { System.out.println("Position out of range"); return; }
        System.out.println("Deleted " + t.next.data);
        t.next = t.next.next;
    }

    static void display() {
        if (head == null) { System.out.println("List is empty"); return; }
        System.out.print("List: ");
        for (Node t = head; t != null; t = t.next) System.out.print(t.data + " -> ");
        System.out.println("null");
    }

    static void count() {
        int c = 0;
        for (Node t = head; t != null; t = t.next) c++;
        System.out.println("Node count = " + c);
    }

    static void search(int v) {
        int pos = 1;
        for (Node t = head; t != null; t = t.next, pos++)
            if (t.data == v) {
                System.out.println(v + " found at position " + pos);
                return;
            }
        System.out.println(v + " not found");
    }

    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 Insert begin  2 Insert end  3 Insert at position");
            System.out.println("4 Delete first  5 Delete last  6 Delete at position");
            System.out.println("7 Display  8 Count  9 Search  0 Exit");
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
                case 8: count(); break;
                case 9:
                    System.out.print("Value to search: ");
                    search(sc.nextInt());
                    break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
