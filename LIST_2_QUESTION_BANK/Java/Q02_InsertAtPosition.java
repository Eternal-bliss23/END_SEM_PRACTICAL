// Question 2: Insert at Position
// Purpose: Insert a value at a 1-based position by shifting array elements right.

import java.util.Scanner;

public class Q02_InsertAtPosition {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n + 1];     // one extra space for the new value
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            System.out.print("a[" + i + "]: ");
            a[i] = sc.nextInt();
        }
        System.out.print("Enter value to insert: ");
        int value = sc.nextInt();
        System.out.print("Enter position (1 to " + (n + 1) + "): ");
        int pos = sc.nextInt();

        if (pos < 1 || pos > n + 1) {
            System.out.println("Invalid position!");
        } else {
            for (int i = n; i >= pos; i--) {     // shift right
                a[i] = a[i - 1];
            }
            a[pos - 1] = value;
            n++;
            System.out.print("Array after insertion: ");
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
