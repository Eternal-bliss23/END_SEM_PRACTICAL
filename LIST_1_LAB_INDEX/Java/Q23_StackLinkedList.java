import java.util.Scanner;

public class Q23_StackLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }
    static Node top;
    static Scanner sc = new Scanner(System.in);

    static void push(int v) {
        Node n = new Node(v);
        n.next = top;
        top = n;
    }
    static void pop() {
        if (top == null) { System.out.println("Stack empty"); return; }
        System.out.println("Popped: " + top.data);
        top = top.next;
    }
    static void peek() {
        if (top == null) { System.out.println("Stack empty"); return; }
        System.out.println("Top: " + top.data);
    }
    static void display() {
        if (top == null) { System.out.println("Stack empty"); return; }
        for (Node p = top; p != null; p = p.next) System.out.print(p.data + " ");
        System.out.println();
    }
    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1 Push  2 Pop  3 Peek  4 Display  5 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.print("Value: "); push(sc.nextInt()); break;
                case 2: pop(); break;
                case 3: peek(); break;
                case 4: display(); break;
                case 5: break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 5);
        sc.close();
    }
}
