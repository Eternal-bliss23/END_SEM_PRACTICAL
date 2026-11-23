// Question 18: Sparse Matrix
// Purpose: Store non-zero terms as triplets and show triplet and dense forms.
import java.util.Scanner;

public class Q18_SparseMatrix {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter cols: ");
        int cols = sc.nextInt();
        System.out.print("Number of non-zero terms: ");
        int t = sc.nextInt();
        int[] row = new int[t], col = new int[t], val = new int[t];
        for (int i = 0; i < t; i++) {
            System.out.print("Term " + (i + 1) + " row: ");
            row[i] = sc.nextInt();
            System.out.print("           col: ");
            col[i] = sc.nextInt();
            System.out.print("           value: ");
            val[i] = sc.nextInt();
        }
        int ch;
        do {
            System.out.println("1. Triplet table  2. Dense matrix  0. Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Row\tCol\tValue");
                    for (int i = 0; i < t; i++)
                        System.out.println(row[i] + "\t" + col[i] + "\t" + val[i]);
                    break;
                case 2:
                    int[][] dense = new int[rows][cols];
                    for (int i = 0; i < t; i++) dense[row[i]][col[i]] = val[i];
                    System.out.println("Dense matrix:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) System.out.print(dense[i][j] + "\t");
                        System.out.println();
                    }
                    break;
                case 0: System.out.println("Goodbye"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 0);
        sc.close();
    }
}
