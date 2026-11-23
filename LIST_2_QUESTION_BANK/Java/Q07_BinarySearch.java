// Question 7: Binary Search
// Purpose: Iteratively search a sorted array by repeatedly halving the range.

import java.util.Scanner;

public class Q07_BinarySearch {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter " + n + " elements in sorted (ascending) order:");
        for (int i = 0; i < n; i++) {
            System.out.print("a[" + i + "]: ");
            a[i] = sc.nextInt();
        }
        System.out.print("Enter key to search: ");
        int key = sc.nextInt();

        int low = 0, high = n - 1, pos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == key) {
                pos = mid;
                break;
            } else if (key < a[mid]) {
                high = mid - 1;       // search left half
            } else {
                low = mid + 1;        // search right half
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
