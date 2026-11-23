// Question 4: Matrix Addition and Subtraction
// Purpose: Use a menu to add or subtract two matrices of the same size.

import java.util.Scanner;

public class Q04_MatrixAddSub {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Add matrices   2. Subtract matrices   0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            if (choice == 1 || choice == 2) {
                System.out.print("Enter rows: ");
                int r = sc.nextInt();
                System.out.print("Enter columns: ");
                int c = sc.nextInt();
                int[][] a = readMatrix(r, c, "first");
                int[][] b = readMatrix(r, c, "second");
                int[][] result = new int[r][c];
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (choice == 1) result[i][j] = a[i][j] + b[i][j];
                        else result[i][j] = a[i][j] - b[i][j];
                    }
                }
                System.out.println(choice == 1 ? "Sum of matrices:" : "Difference of matrices:");
                printMatrix(result);
            } else if (choice != 0) {
                System.out.println("Wrong choice!");
            }
        } while (choice != 0);
        sc.close();
    }

    static int[][] readMatrix(int r, int c, String name) {
        int[][] m = new int[r][c];
        System.out.println("Enter elements of " + name + " matrix:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print("[" + i + "][" + j + "]: ");
                m[i][j] = sc.nextInt();
            }
        }
        return m;
    }

    static void printMatrix(int[][] m) {
        for (int[] row : m) {
            for (int x : row) {
                System.out.print(x + "\t");
            }
            System.out.println();
        }
    }
}
