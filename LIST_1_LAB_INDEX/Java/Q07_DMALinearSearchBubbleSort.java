// Question 7: Dynamic Array - Linear Search and Bubble Sort
// Purpose: Search and sort a runtime-sized array with simple algorithms.
import java.util.Scanner;

public class Q07_DMALinearSearchBubbleSort {
    static Scanner sc = new Scanner(System.in);

    static int linearSearch(int[] a, int key) {
        for (int i = 0; i < a.length; i++)
            if (a[i] == key) return i;
        return -1;
    }

    static void bubbleSort(int[] a) {
        for (int i = 0; i < a.length - 1; i++)
            for (int j = 0; j < a.length - 1 - i; j++)
                if (a[j] > a[j + 1]) {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
    }

    static void display(int[] a) {
        System.out.print("Array: ");
        for (int v : a) System.out.print(v + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        // Java equivalent of C dynamic memory allocation
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            a[i] = sc.nextInt();
        }
        int ch;
        do {
            System.out.println("1. Linear search  2. Bubble sort  3. Display  0. Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Value to search: ");
                    int pos = linearSearch(a, sc.nextInt());
                    if (pos == -1) System.out.println("Not found");
                    else System.out.println("Found at index " + pos + " (position " + (pos + 1) + ")");
                    break;
                case 2:
                    bubbleSort(a);
                    System.out.println("Sorted array:");
                    display(a);
                    break;
                case 3: display(a); break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
