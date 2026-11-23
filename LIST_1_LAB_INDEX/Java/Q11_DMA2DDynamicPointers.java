// Question 11: Dynamic 2D Array with Dynamic Row Count (Pointer Style)
// Purpose: Read rows and cols, allocate the matrix, fill it and print it.
import java.util.Scanner;

public class Q11_DMA2DDynamicPointers {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter cols: ");
        int cols = sc.nextInt();
        // Java equivalent of C dynamic memory allocation
        int[][] p = new int[rows][cols];   // Java handles freeing memory automatically
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("p[" + i + "][" + j + "]: ");
                p[i][j] = sc.nextInt();
            }
        }
        System.out.println("Matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                System.out.print(p[i][j] + "\t");
            System.out.println();
        }
        sc.close();
    }
}
