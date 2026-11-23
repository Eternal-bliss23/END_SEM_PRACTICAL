// Question 3: Delete from Position
// Purpose: Delete the element at a 1-based position by shifting array elements left.

import java.util.Scanner;

public class Q03_DeleteFromPosition {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            System.out.print("a[" + i + "]: ");
            a[i] = sc.nextInt();
        }
        System.out.print("Enter position to delete (1 to " + n + "): ");
        int pos = sc.nextInt();

        if (pos < 1 || pos > n) {
            System.out.println("Invalid position!");
        } else {
            for (int i = pos - 1; i < n - 1; i++) {   // shift left
                a[i] = a[i + 1];
            }
            n--;
            System.out.print("Array after deletion: ");
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
