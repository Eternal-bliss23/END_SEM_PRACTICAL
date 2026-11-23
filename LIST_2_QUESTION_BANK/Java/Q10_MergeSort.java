// Question 10: Merge Sort
// Purpose: Recursively split an array into halves and merge them in sorted order.

import java.util.Scanner;

public class Q10_MergeSort {
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

        mergeSort(a, 0, n - 1);

        System.out.print("Array after merge sort: ");
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
        sc.close();
    }

    static void mergeSort(int[] a, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(a, low, mid);            // sort left half
            mergeSort(a, mid + 1, high);       // sort right half
            merge(a, low, mid, high);
        }
    }

    static void merge(int[] a, int low, int mid, int high) {
        int[] temp = new int[a.length];
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++];
        }
        while (i <= mid) temp[k++] = a[i++];
        while (j <= high) temp[k++] = a[j++];
        for (i = low; i <= high; i++) {
            a[i] = temp[i];                    // copy back
        }
    }
}
