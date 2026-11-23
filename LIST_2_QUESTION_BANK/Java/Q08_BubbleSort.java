// Question 8: Bubble Sort
// Purpose: Sort an array by repeatedly swapping adjacent out-of-order elements.

import java.util.Scanner;

public class Q08_BubbleSort {
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

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        System.out.print("Array after bubble sort: ");
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
        sc.close();
    }
}
