// Question 9: Quick Sort
// Purpose: Recursively partition an array around a pivot and sort both parts.

import java.util.Scanner;

public class Q09_QuickSort {
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

        quickSort(a, 0, n - 1);

        System.out.print("Array after quick sort: ");
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
        sc.close();
    }

    static void quickSort(int[] a, int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);
            quickSort(a, low, p - 1);      // sort left part
            quickSort(a, p + 1, high);     // sort right part
        }
    }

    static int partition(int[] a, int low, int high) {
        int pivot = a[high];               // last element as pivot
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;
        return i + 1;                      // final pivot position
    }
}
