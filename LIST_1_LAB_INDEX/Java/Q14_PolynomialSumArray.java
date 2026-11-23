// Question 14: Sum of Two Polynomials Using Arrays
// Purpose: Store coefficients by power in arrays, add them and print the result.
import java.util.Scanner;

public class Q14_PolynomialSumArray {
    static Scanner sc = new Scanner(System.in);

    static void printPoly(int[] c) {
        boolean first = true;
        for (int i = c.length - 1; i >= 0; i--) {
            if (c[i] == 0) continue;
            if (!first) System.out.print(" + ");
            if (i == 0) System.out.print(c[i]);
            else if (c[i] == 1) System.out.print("x^" + i);
            else System.out.print(c[i] + "x^" + i);
            first = false;
        }
        if (first) System.out.print("0");
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.print("Degree of first polynomial: ");
        int d1 = sc.nextInt();
        int[] p1 = new int[d1 + 1];   // coefficient of x^i is at index i
        for (int i = 0; i <= d1; i++) {
            System.out.print("Coefficient of x^" + i + ": ");
            p1[i] = sc.nextInt();
        }
        System.out.print("Degree of second polynomial: ");
        int d2 = sc.nextInt();
        int[] p2 = new int[d2 + 1];
        for (int i = 0; i <= d2; i++) {
            System.out.print("Coefficient of x^" + i + ": ");
            p2[i] = sc.nextInt();
        }

        int max = Math.max(d1, d2);
        int[] sum = new int[max + 1];
        for (int i = 0; i <= max; i++) {
            int c1 = (i <= d1) ? p1[i] : 0;
            int c2 = (i <= d2) ? p2[i] : 0;
            sum[i] = c1 + c2;
        }
        System.out.print("First polynomial : ");
        printPoly(p1);
        System.out.print("Second polynomial: ");
        printPoly(p2);
        System.out.print("Sum              : ");
        printPoly(sum);
        sc.close();
    }
}
