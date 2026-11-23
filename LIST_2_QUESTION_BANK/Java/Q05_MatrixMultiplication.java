// Question 5: Matrix Multiplication
// Purpose: Read A (r1 x c1) and B (c1 x c2) and print their product.

import java.util.Scanner;

public class Q05_MatrixMultiplication {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter rows of A: ");
        int r1 = sc.nextInt();
        System.out.print("Enter columns of A: ");
        int c1 = sc.nextInt();
        System.out.print("Enter rows of B: ");
        int r2 = sc.nextInt();
        System.out.print("Enter columns of B: ");
        int c2 = sc.nextInt();

        if (c1 != r2) {
            System.out.println("Multiplication not possible: columns of A must equal rows of B.");
            sc.close();
            return;
        }

        int[][] a = readMatrix(r1, c1, "A");
        int[][] b = readMatrix(r2, c2, "B");
        int[][] product = new int[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                int sum = 0;
                for (int k = 0; k < c1; k++) {
                    sum += a[i][k] * b[k][j];
                }
                product[i][j] = sum;
            }
        }
        System.out.println("Product matrix (A x B):");
        for (int[] row : product) {
            for (int x : row) {
                System.out.print(x + "\t");
            }
            System.out.println();
        }
        sc.close();
    }

    static int[][] readMatrix(int r, int c, String name) {
        int[][] m = new int[r][c];
        System.out.println("Enter elements of matrix " + name + ":");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print("[" + i + "][" + j + "]: ");
                m[i][j] = sc.nextInt();
            }
        }
        return m;
    }
}
