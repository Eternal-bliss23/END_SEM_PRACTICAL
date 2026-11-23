// Question 4: Insert and Delete in an Array
// Purpose: Insert and delete elements by shifting them in a fixed-size array.
import java.util.Scanner;

public class Q04_InsertDeleteArray {
    static final int CAP = 50;
    static int[] a = new int[CAP];
    static int size = 0;
    static Scanner sc = new Scanner(System.in);

    static void insert(int value, int pos) {
        if (size == CAP) { System.out.println("Array is full"); return; }
        if (pos < 1 || pos > size + 1) { System.out.println("Invalid position"); return; }
        for (int i = size; i >= pos; i--) a[i] = a[i - 1];
        a[pos - 1] = value;
        size++;
        System.out.println("Inserted " + value + " at position " + pos);
    }

    static void delete(int pos) {
        if (pos < 1 || pos > size) { System.out.println("Invalid position"); return; }
        int removed = a[pos - 1];
        for (int i = pos; i < size; i++) a[i - 1] = a[i];
        size--;
        System.out.println("Deleted " + removed + " from position " + pos);
    }

    static void display() {
        if (size == 0) { System.out.println("Array is empty"); return; }
        System.out.print("Array: ");
        for (int i = 0; i < size; i++) System.out.print(a[i] + " ");
        System.out.println("(size = " + size + ")");
    }

    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("1. Insert  2. Delete  3. Display  0. Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Value: ");
                    int v = sc.nextInt();
                    System.out.print("Position: ");
                    insert(v, sc.nextInt());
                    break;
                case 2:
                    System.out.print("Position: ");
                    delete(sc.nextInt());
                    break;
                case 3: display(); break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
