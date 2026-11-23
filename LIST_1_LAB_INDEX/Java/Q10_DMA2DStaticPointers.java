// Question 10: Dynamic 2D Array with Static Row Count (Pointer Style)
// Purpose: Keep 3 rows fixed and allocate each row separately at runtime.
import java.util.Scanner;

public class Q10_DMA2DStaticPointers {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // Java equivalent of C dynamic memory allocation
        int[][] p = new int[3][];   // 3 rows, each row allocated separately
        for (int i = 0; i < 3; i++) {
            System.out.print("Columns in row " + i + ": ");
            int cols = sc.nextInt();
            p[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                System.out.print("p[" + i + "][" + j + "]: ");
                p[i][j] = sc.nextInt();
            }
        }
        System.out.println("Matrix (rows may have different lengths):");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < p[i].length; j++)
                System.out.print(p[i][j] + "\t");
            System.out.println();
        }
        sc.close();
    }
}
