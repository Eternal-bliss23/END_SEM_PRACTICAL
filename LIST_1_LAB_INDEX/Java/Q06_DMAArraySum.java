// Question 6: Dynamic Array Sum
// Purpose: Allocate an array at runtime, read values and print their sum.
import java.util.Scanner;

public class Q06_DMAArraySum {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        // Java equivalent of C dynamic memory allocation
        int[] a = new int[n];   // malloc(n * sizeof(int)) in C
        int sum = 0;
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            a[i] = sc.nextInt();
            sum += a[i];
        }
        System.out.println("Elements:");
        for (int i = 0; i < n; i++) System.out.print(a[i] + " ");
        System.out.println();
        System.out.println("Sum = " + sum);
        sc.close();
    }
}
