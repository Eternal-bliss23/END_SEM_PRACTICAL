import java.util.Scanner;

public class Q22_StackArray {
    static final int CAP = 10;
    static int[] stack = new int[CAP];
    static int top = -1;
    static Scanner sc = new Scanner(System.in);

    static void push(int v) {
        if (top == CAP - 1) { System.out.println("Stack full"); return; }
        stack[++top] = v;
    }
    static void pop() {
        if (top < 0) { System.out.println("Stack empty"); return; }
        System.out.println("Popped: " + stack[top--]);
    }
    static void peek() {
        if (top < 0) { System.out.println("Stack empty"); return; }
        System.out.println("Top: " + stack[top]);
    }
    static void display() {
        if (top < 0) { System.out.println("Stack empty"); return; }
        for (int i = top; i >= 0; i--) System.out.print(stack[i] + " ");
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
