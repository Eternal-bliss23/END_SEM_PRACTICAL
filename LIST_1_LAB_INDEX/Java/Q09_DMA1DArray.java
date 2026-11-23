// Question 9: Dynamic 1D Array
// Purpose: Create a 1D array of runtime size, fill it and display it.
import java.util.Scanner;

public class Q09_DMA1DArray {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        // Java equivalent of C dynamic memory allocation
        int[] p = new int[n];   // Java arrays replace malloc and free
        for (int i = 0; i < n; i++) {
            System.out.print("p[" + i + "]: ");
            p[i] = sc.nextInt();
        }
        System.out.println("Array contents:");
        for (int i = 0; i < n; i++)
            System.out.println("p[" + i + "] = " + p[i]);
        sc.close();
    }
}
