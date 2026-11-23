// Question 1: Merge Two Arrays
// Purpose: Read two arrays and copy all their elements into a third array.

import java.util.Scanner;

public class Q01_MergeTwoArrays {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter size of first array: ");
        int n1 = sc.nextInt();
        int[] a = new int[n1];
        System.out.println("Enter " + n1 + " elements of first array:");
        for (int i = 0; i < n1; i++) {
            System.out.print("a[" + i + "]: ");
            a[i] = sc.nextInt();
        }

        System.out.print("Enter size of second array: ");
        int n2 = sc.nextInt();
        int[] b = new int[n2];
        System.out.println("Enter " + n2 + " elements of second array:");
        for (int i = 0; i < n2; i++) {
            System.out.print("b[" + i + "]: ");
            b[i] = sc.nextInt();
        }

        int[] merged = new int[n1 + n2];
        int k = 0;
        for (int i = 0; i < n1; i++) {
            merged[k++] = a[i];       // copy first array
        }
        for (int i = 0; i < n2; i++) {
            merged[k++] = b[i];       // copy second array
        }

        System.out.print("Merged array: ");
        for (int x : merged) {
            System.out.print(x + " ");
        }
        System.out.println();
        sc.close();
    }
}
