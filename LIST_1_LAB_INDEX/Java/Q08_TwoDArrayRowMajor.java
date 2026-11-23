// Question 8: Two-Dimensional Array in Row-Major Order
// Purpose: Store a matrix in one 1D array using index i*cols+j and print it.
import java.util.Scanner;

public class Q08_TwoDArrayRowMajor {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter cols: ");
        int cols = sc.nextInt();
        int[] a = new int[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Element [" + i + "][" + j + "]: ");
                a[i * cols + j] = sc.nextInt();   // row-major index
            }
        }
        System.out.println("Matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                System.out.print(a[i * cols + j] + "\t");
            System.out.println();
        }
        sc.close();
    }
}
