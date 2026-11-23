// Question 3: Random Numbers Array
// Purpose: Fill an array with random numbers from 0 to 99 and display them.
import java.util.Scanner;

public class Q03_RandomNumbersArray {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = (int)(Math.random() * 100);
        System.out.println("Random numbers (0 to 99):");
        for (int i = 0; i < n; i++)
            System.out.println("a[" + i + "] = " + a[i]);
        sc.close();
    }
}
