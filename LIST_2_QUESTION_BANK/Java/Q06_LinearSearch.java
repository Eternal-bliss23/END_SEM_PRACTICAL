// Question 6: Linear Search
// Purpose: Search an array element by element and print its position.

import java.util.Scanner;

public class Q06_LinearSearch {
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
        System.out.print("Enter key to search: ");
        int key = sc.nextInt();

        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                pos = i;              // store 0-based index
                break;
            }
        }
        if (pos == -1) {
            System.out.println("Key " + key + " not found in the array.");
        } else {
            System.out.println("Key " + key + " found at position " + (pos + 1)
                               + " (index " + pos + ").");
        }
        sc.close();
    }
}
