// Question 2: Display Array Using a User Function
// Purpose: Read n integers and print them through a separate display() method.
import java.util.Scanner;

public class Q02_DisplayArrayUserFunction {
    static Scanner sc = new Scanner(System.in);

    static void display(int[] a, int n) {
        System.out.println("Array elements:");
        for (int i = 0; i < n; i++)
            System.out.println("a[" + i + "] = " + a[i]);
    }

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            a[i] = sc.nextInt();
        }
        display(a, n);
        sc.close();
    }
}
