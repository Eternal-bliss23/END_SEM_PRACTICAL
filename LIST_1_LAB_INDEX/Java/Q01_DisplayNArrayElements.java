// Question 1: Display N Array Elements
// Purpose: Read n integers into an array and print them in order.
import java.util.Scanner;

public class Q01_DisplayNArrayElements {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            a[i] = sc.nextInt();
        }
        System.out.println("Array elements:");
        for (int i = 0; i < n; i++)
            System.out.println("a[" + i + "] = " + a[i]);
        System.out.print("In order: ");
        for (int i = 0; i < n; i++) System.out.print(a[i] + " ");
        System.out.println();
        sc.close();
    }
}
